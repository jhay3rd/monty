#include "monty.h"
/**
*add_two - the function adds the two top elements of a stack
*@stack: the stack to be added
*@line_number: the nodes number
*Return: void
*/
void add_two(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *top = *stack, *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: cannot add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		second = top->next;

		sum = (top->n) + (second->n);
		second->n = sum;
		*stack = second;
		free(top);
	}

}
