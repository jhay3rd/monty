#include "monty.h"

/**
 * push - function moves an element to the stack
 * @line_number: the line number
 * @stack: a double pointer to the stack
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *data = strtok(NULL, " \n\t\r");
	int n;

	if (!data)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(data);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - function prints out all values in the stack
 * @line_number: indicates the line number
 * @stack: this is the pointer to the head
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
