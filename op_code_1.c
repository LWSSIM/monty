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

/**
 * pop - remove 1st stack element
 * @data: DS
 *
*/
void pop(run_data *data)
{
	if (delete_dnodeint_at_index(&data->head, 0) == -1)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	data->stack_counter--;
}

/**
 * swap - swaps 2 top elements of a stack
 * @data: DS
 *
*/
void swap(run_data *data)
{
	int tmp;

	if (data->stack_counter < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	tmp = data->head->n;
	data->head->n = data->head->next->n;
	data->head->next->n = tmp;
}
