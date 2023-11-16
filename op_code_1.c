#include "monty.h"

/**
* push - push element to stack or queue
* @data: DS
*
*/
void push(run_data *data)
{
	int n;

	if (!data->parsed[1] || !check_int(data->parsed[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	n = atoi(data->parsed[1]);
	if (!add_dnodeint(&data->head, n))
	{
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	data->stack_counter++;
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
		printf("%i\n", p->n);
	}
}

/**
 * pint - print top of the stack value
 * @data: DS
 *
*/
void pint(run_data *data)
{
	stack_t *p = data->head;

	if (!p)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", p->n);
}
