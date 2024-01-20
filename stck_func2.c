#include "monty.h"

/**
 * nope - Does nothing.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void nope(stack_t **stck, unsigned int line_numb)
{
	(void)stck;
	(void)line_numb;
}


/**
 * swp_nodes - Swaps the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void swp_nodes(stack_t **stck, unsigned int line_numb)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)
		more_errors(8, line_numb, "swap");
	temp = (*stck)->nxt;
	(*stck)->nxt = temp->nxt;
	if (temp->nxt != NULL)
		temp->nxt->prv = *stck;
	temp->nxt = *stck;
	(*stck)->prv = temp;
	temp->prv = NULL;
	*stck = temp;
}

/**
 * ad_nodes - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void ad_nodes(stack_t **stck, unsigned int line_numb)
{
	int summ;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)
		more_errors(8, line_numb, "add");

	(*stck) = (*stck)->nxt;
	summ = (*stck)->a + (*stck)->prv->a;
	(*stck)->a = summ;
	free((*stck)->prv);
	(*stck)->prv = NULL;
}


/**
 * sb_nodes - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void sb_nodes(stack_t **stck, unsigned int line_numb)
{
	int summ;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)

		more_errors(8, line_numb, "sub");


	(*stck) = (*stck)->nxt;
	summ = (*stck)->a - (*stck)->prv->a;
	(*stck)->a = summ;
	free((*stck)->prv);
	(*stck)->prv = NULL;
}


/**
 * dv_nodes - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void dv_nodes(stack_t **stck, unsigned int line_numb)
{
	int summ;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)
		more_errors(8, line_numb, "div");

	if ((*stck)->a == 0)
		more_errors(9, line_numb);
	(*stck) = (*stck)->nxt;
	summ = (*stck)->a / (*stck)->prv->a;
	(*stck)->a = summ;
	free((*stck)->prv);
	(*stck)->prv = NULL;
}
