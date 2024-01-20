#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @a: integer
 * @prv: points to the previous element of the stack (or queue)
 * @nxt: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int a;
        struct stack_s *prv;
        struct stack_s *nxt;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcod: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcod;
        void (*f)(stack_t **stck, unsigned int line_numb);
} instruction_t;

extern stack_t *hd;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void op_file(char *);
int pars_line(char *, int, int);
void rd_file(FILE *);
int len_chars(FILE *);
void fd_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void fre_ndes(void);
void prnt_stck(stack_t **, unsigned int);
void ad_to_stck(stack_t **, __attribute__((unused))unsigned int);
void add_to_queue(stack_t **, unsigned int);

void cal_f(op_func, char *, char *, int, int);

void prnt_top(stack_t **, unsigned int);
void p_top(stack_t **, unsigned int);
void nope(stack_t **, unsigned int);
void swp_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void ad_nodes(stack_t **, unsigned int);
void sb_nodes(stack_t **, unsigned int);
void dv_nodes(stack_t **, unsigned int);
void ml_nodes(stack_t **, unsigned int);
void md_nodes(stack_t **, unsigned int);

/*String operations*/
void prnt_char(stack_t **, unsigned int);
void prnt_str(stack_t **, unsigned int);
void rootl(stack_t **, unsigned int);

/*Error hanlding*/
void errors(int err_code, ...);
void more_errors(int err_code, ...);
void strg_err(int err_code, ...);
void rootr(stack_t **, unsigned int);

#endif
