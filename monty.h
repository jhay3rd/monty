#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
*struct glob_s - globally useful variables, all rolled into one
*@top: double pointer to top of stack
*@ops: double pointer to an instruction struct
*/
typedef struct glob_s
{
	stack_t **top;
	instruction_t **ops;
} glob_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* monty.c */
void stack_init(stack_t **head);
void free_all(void);
stack_t *create_node(unsigned int n);
void insert(stack_t **newNode, unsigned int line_number);
int parse_line(char *line, unsigned int line_number, int info);

/* helper1.c */
int process_file(char *filename, stack_t **stack);

/* helper2.c */
void delegate_op(stack_t **stack, char *op, unsigned int line_number);

/* instruction.c */

void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add_two(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void f_pchar(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter);

#endif
