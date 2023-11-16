#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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
 * @linen: line number from file (start 1)
 * @head: ptr->stack (DLL)
 * @stack_counter: stack
 */
typedef struct run_data
{
	char *line;
	char *parsed[2];
	unsigned int stack_counter;
	stack_t *head;
	unsigned int linen;
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

	void (*f)(run_data *data);

} instruction_t;


/*----main----*/
int main(int ac, char **av);
void init_data(run_data *data);
int routine(run_data *data);

/*----input_parse----*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int check_space(char *str, ssize_t chars_read);
int _isspace(char c);
int check_int(char *str);

/*----op_exec.c----*/
void get_op(run_data *data);
int interpreter(run_data *data);

/*----op_code_1.c----*/
void push(run_data *data);
void pall(run_data *data);
void pop(run_data *data);
void pint(run_data *data);
void swap(run_data *data);

/*----op_code_math.c----*/
void add(run_data *data);
void sub(run_data *data);
void _div(run_data *data);
void mul(run_data *data);
void mod(run_data *data);

/*----op_code_util.c----*/
void pchar(run_data *data);
void pstr(run_data *data);
void rotl(run_data *data);



/*----dll.c----*/
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/*----mem_mngmt.c----*/
void free_data(run_data *data);
void free_stack(stack_t *head);

#endif /*monty.h*/
