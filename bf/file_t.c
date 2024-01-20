#include "monty.h"

/**
 * op_file - opens a file
 * @fi_name: the file namepath
 * Return: void
 */

void op_file(char *fi_name)
{
	FILE *f_d = fopen(fi_name, "r");

	if (fi_name == NULL || f_d == NULL)
		err(2, fi_name);

	rd_file(f_d);
	fclose(f_d);
}


/**
 * rd_file - reads a file
 * @f_d: pointer to file descriptor
 * Return: void
 */

void rd_file(FILE *f_d)
{
	int line_numb, formt = 0;
	char *buff = NULL;
	size_t ln = 0;

	for (line_numb = 1; getline(&buff, &ln, f_d) != -1; line_numb++)
	{
		formt = pars_line(buff, line_numb, formt);
	}
	free(buff);
}


/**
 * pars_line - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @line_numb: line number
 * @formt:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int pars_line(char *buff, int line_numb, int formt)
{
	char *opcod, *valu;
	const char *delm = "\n ";

	if (buff == NULL)
		errors(4);

	opcod = strtok(buff, delm);
	if (opcod == NULL)
		return (formt);
	valu = strtok(NULL, delm);

	if (strcmp(opcod, "stack") == 0)
		return (0);
	if (strcmp(opcod, "queue") == 0)
		return (1);

	fd_func(opcod, valu, line_numb, formt);
	return (formt);
}

/**
 * fd_func - find the appropriate function for the opcode
 * @opcod: opcode
 * @valu: argument of opcode
 * @formt:  storage format. If 0 Nodes will be entered as a stack.
 * @len: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void fd_func(char *opcod, char *valu, int len, int formt)
{
	int j;
	int flg;

	instruction_t func_list[] = {
		{"push", ad_to_stck},
		{"pall", prnt_stck},
		{"pint", prnt_top},
		{"pop", p_top},
		{"nop", nope},
		{"swap", swp_nodes},
		{"add", ad_nodes},
		{"sub", sb_nodes},
		{"div", dv_nodes},
		{"mul", ml_nodes},
		{"mod", md_nodes},
		{"pchar", prnt_char},
		{"pstr", prnt_str},
		{"rotl", rootl},
		{"rotr", rootr},
		{NULL, NULL}
	};

	if (opcod[0] == '#')
		return;

	for (flg = 1, j = 0; func_list[j].opcod != NULL; j++)
	{
		if (strcmp(opcod, func_list[j].opcod) == 0)
		{
			cal_f(func_list[j].f, opcod, valu, len, formt);
			flg = 0;
		}
	}
	if (flg == 1)
		errors(3, len, opcod);
}


/**
 * cal_f - Calls the required function.
 * @funct: Pointer to the function that is about to be called.
 * @ope: string representing the opcode.
 * @vali: string representing a numeric value.
 * @len: line numeber for the instruction.
 * @formt: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void cal_f(op_func funct, char *ope, char *vali, int len, int formt)
{
	stack_t *nod;
	int flg;
	int j;

	flg = 1;
	if (strcmp(ope, "push") == 0)
	{
		if (vali != NULL && vali[0] == '-')
		{
			vali = vali + 1;
			flg = -1;
		}
		if (vali == NULL)
			errors(5, len);
		for (j = 0; vali[j] != '\0'; j++)
		{
			if (isdigit(vali[j]) == 0)
				errors(5, len);
		}
		nod = create_node(atoi(vali) * flg);
		if (formt == 0)
			func(&nod, len);
		if (formt == 1)
			add_to_queue(&nod, len);
	}
	else
		func(&hd, len);
}
