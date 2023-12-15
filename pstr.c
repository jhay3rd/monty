#include "monty.h"
/**
 * f_pstr - prints string from top of the stack,then a new line
 * @head: head of stack
 * @counter: counts line number of stack
 * Return: returns nothing
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
