#include "monty.h"

/**
 * swap - this swaps two elements from top of a stack
 * @stack: the stack to be swapped
 * @line_number: line number of the stack
 * Return: returns void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: cannot swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}
