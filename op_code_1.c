#include "monty.h"

/**
* push - push element to stack or queue
* @data: DS
*
*/
void push(run_data *data)
{
	int n;

	if (!data->parsed[1])
	{
		fprintf(2, "L%i: usage: push integer", data->line_n);
		free_data(data);
		exit(EXIT_FAILURE);
	}
	n = atoi(data->parsed[1]);
	add_dnodeint(data->head, n);
	stack_counter++;
}

/**
* pall - print all elements in stack or queue
* @data: DS
*
*/
void pall(run_data *data)
{
	stack_t *p;

	for (p = data->head; p; p = p->next)
	{
		printf("%i", p->n);
	}
}
