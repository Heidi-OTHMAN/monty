#include "monty.h"

/**
 * prnt_char - Prints the Ascii value.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void prnt_char(stack_t **stck, unsigned int line_numb)
{
	int ascii;

	if (stck == NULL || *stck == NULL)
		strg_err(11, line_numb);

	ascii = (*stck)->a;
	if (ascii < 0 || ascii > 127)
		strg_err(10, line_numb);
	printf("%c\n", ascii);
}

/**
 * prnt_str - Prints a string.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
 */
void prnt_str(stack_t **stck, __attribute__((unused))unsigned int len)
{
	int ascii;
	stack_t *temp;

	if (stck == NULL || *stck == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stck;
	while (temp != NULL)
	{
		ascii = temp->a;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->nxt;
	}
	printf("\n");
}

/**
 * rootl - Rotates the first node of the stack to the bottom.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
 */
void rootl(stack_t **stck, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)
		return;

	temp = *stck;
	while (temp->nxt != NULL)
		temp = temp->nxt;

	temp->nxt = *stck;
	(*stck)->prv = temp;
	*stck = (*stck)->nxt;
	(*stck)->prv->nxt = NULL;
	(*stck)->prv = NULL;
}


/**
 * rootr - Rotates the last node of the stack to the top.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
 */
void rootr(stack_t **stck, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL || (*stck)->nxt == NULL)
		return;

	temp = *stck;

	while (temp->nxt != NULL)
		temp = temp->nxt;

	temp->nxt = *stck;
	temp->prv->nxt = NULL;
	temp->prv = NULL;
	(*stck)->prv = temp;
	(*stck) = temp;
}
