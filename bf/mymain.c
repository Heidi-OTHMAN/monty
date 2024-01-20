#include "monty.h"
stack_t *hd = NULL;

/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: always 0
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(av[1]);
	fre_ndes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @a: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int a)
{
	stack_t *nod;

	nod = malloc(sizeof(stack_t));
	if (nod == NULL)
		errors(4);
	nod->nxt = NULL;
	nod->prv = NULL;
	nod->a = a;
	return (nod);
}

/**
 * fre_ndes - Frees nodes in the stack.
 */
void fre_ndes(void)
{
	stack_t *tmp;

	if (hd == NULL)
		return;

	while (hd != NULL)
	{
		tmp = hd;
		hd = hd->nxt;
		free(tmp);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @nw_node: Pointer to the new node.
 * @len: line number of the opcode.
 */
void add_to_queue(stack_t **nw_node, __attribute__((unused))unsigned int len)
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
	while (temp->nxt != NULL)
		temp = temp->nxt;

	temp->nxt = *nw_node;
	(*nw_node)->prv = temp;

}
