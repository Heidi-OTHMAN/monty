#include "monty.h"

/**
 * ml_nodes - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void ml_nodes(stack_t **stck, unsigned int line_numb)
{
	int summ;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)
		more_errors(8, line_numb, "mul");

	(*stck) = (*stck)->nxt;
	summ = (*stck)->a * (*stck)->prv->a;
	(*stck)->a = summ;
	free((*stck)->prv);
	(*stck)->prv = NULL;
}


/**
 * md_nodes - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void md_nodes(stack_t **stck, unsigned int line_numb)
{
	int summ;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)

		more_errors(8, line_numb, "mod");


	if ((*stck)->a == 0)
		more_errors(9, line_numb);
	(*stck) = (*stck)->nxt;
	summ = (*stck)->a % (*stck)->prv->a;
	(*stck)->a = summ;
	free((*stck)->prv);
	(*stck)->prv = NULL;
}
