#include "monty.h"

/**
 * add - adds top 2 elements in 2nd delete 1st
 * @data: DS
 *
*/
void add(run_data *data)
{
	if (data->stack_counter < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	data->head->next->n += data->head->n;
	delete_dnodeint_at_index(&data->head, 0);
}

/**
 * sub - subs top 2 elements in 2nd delete 1st
 * @data: DS
 *
*/
void sub(run_data *data)
{
	if (data->stack_counter < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	data->head->next->n -= data->head->n;
	delete_dnodeint_at_index(&data->head, 0);
}

/**
 * _div - divides top 2 elements in 2nd delete 1st
 * @data: DS
 *
*/
void _div(run_data *data)
{
	if (data->stack_counter < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	if (!data->head->n)
	{
		fprintf(stderr, "L%u: division by zero\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	data->head->next->n /= data->head->n;
	delete_dnodeint_at_index(&data->head, 0);
}

/**
 * mul - multiply top 2 elements in 2nd delete 1st
 * @data: DS
 *
*/
void mul(run_data *data)
{
	if (data->stack_counter < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	data->head->next->n *= data->head->n;
	delete_dnodeint_at_index(&data->head, 0);
}

/**
 * mod - calc modulo of top 2 elements in 2nd delete 1st
 * @data: DS
 *
*/
void mod(run_data *data)
{
	if (data->stack_counter < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	if (!data->head->n)
	{
		fprintf(stderr, "L%u: division by zero\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	data->head->next->n %= data->head->n;
	delete_dnodeint_at_index(&data->head, 0);
}
