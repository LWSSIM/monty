#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

extern unsigned int stack_counter;

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
 * struct run_data - data for running the interperter
 * @line: line read from line
 * @parsed: parsed input line
 * @f: opened file
 * @line_n: line number from file (start 1)
 * @head: ptr->stack (DLL)
 *
 */
typedef struct run_data
{
	char *line;
	char **parsed;
	stack_t *head;
	unsigned int line_n;
	FILE *f;
} run_data;

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

	int (*f)(run_data *);

} instruction_t;


/*----main----*/
int main(int ac, char **av);

/*----input_parse----*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **get_token(char *input, const char *delimiter);

/*----op_exec.c----*/
int (*get_op(char *cmd))(run_data *);
int interpreter(run_data *data);

/*----op_code_1.c----*/
void push(run_data *data);
void pall(run_data *data);


#endif /*monty.h*/
