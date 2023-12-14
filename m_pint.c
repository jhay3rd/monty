#include "monty.h"

/**
* pint - displays the top value of the stack
* @line_number: this is the line number of the code.
* @stack: this pointer points to top node of the stack.
*/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
	}
}
