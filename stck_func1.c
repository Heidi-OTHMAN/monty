#include "monty.h"


/**
 * ad_to_stck - Adds a node to the stack.
 * @nw_node: Pointer to the new node.
 * @len: Interger representing the line number of of the opcode.
 */
void ad_to_stck(stack_t **nw_node, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (nw_node == NULL || *nw_node == NULL)
		exit(EXIT_FAILURE);
	if (hd == NULL)
	{
		hd = *nw_node;
		return;
	}
	temp = hd;
	hd = *nw_node;
	hd->nxt = temp;
	temp->prv = hd;
}


/**
 * prnt_stck - Adds a node to the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: line number of  the opcode.
 */
void prnt_stck(stack_t **stck, unsigned int line_numb)
{
	stack_t *temp;

	(void) line_numb;
	if (stck == NULL)
		exit(EXIT_FAILURE);
	temp = *stck;
	while (temp != NULL)
	{
		printf("%d\n", temp->a);
		temp = temp->nxt;
	}
}

/**
 * p_top - Adds a node to the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void p_top(stack_t **stck, unsigned int line_numb)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL)
		more_errors(7, line_numb);

	temp = *stck;
	*stck = temp->nxt;
	if (*stck != NULL)
		(*stck)->prv = NULL;
	free(temp);
}

/**
 * prnt_top - Prints the top node of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void prnt_top(stack_t **stck, unsigned int line_numb)
{
	if (stck == NULL || *stck == NULL)
		more_errors(6, line_numb);
	printf("%d\n", (*stck)->a);
}
