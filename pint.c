#include "monty.h"
/**
 * f_pint - the top of the stack is printed
 * @head: head of stack
 * @counter: counts number of lines
 * Return: returns nothing
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: cannot pint,the stack is empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
