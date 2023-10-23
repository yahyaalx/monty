#include "monty.h"
stack_t *head = NULL;
/**
 * create_node - create a new node
 * @n: value to put at each node
 * Return: on sucess a pointer to the created node. fail NULL
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handle_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * add_to_queue - Add the node to queue
 * @new_node: Pointer to the new node
 * @ln: line num of the opcode
 */
void add_to_queue(stack_t **new_node, unsigned int ln)
{
	stack_t *tmp;
(void)ln;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}


/**
 * add_nodes - add the top two elements of the stack
 * @stack: Pointer to top node of the stack
 * @line_number: line number of the opocode
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_error2(8, line_number, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
