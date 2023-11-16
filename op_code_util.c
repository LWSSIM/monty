#include "monty.h"

/**
 * pchar - prints char at top of stack
 * @data: DS
 *
*/
void pchar(run_data *data)
{
	if (!data->head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	if (!isalpha(data->head->n))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", data->linen);
		free_data(data), free_stack(data->head), fclose(data->f);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", data->head->n);
}

/**
 * pstr - prints string
 * @data: DS
 *
*/
void pstr(run_data *data)
{
	stack_t *p = data->head;

	while (p)
	{
		if (!p->n || !isalpha(p->n))
		{
			printf("\n");
			return;
		}
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}

/**
 * rotl - rotate 1st node to last
 * @data: DS
 *
*/
void rotl(run_data *data)
{
	if (data->stack_counter > 1)
	{
		add_dnodeint_end(&data->head, data->head->n);
		delete_dnodeint_at_index(&data->head, 0);
	}
}

/**
 * rotr - rotate 1st node to last
 * @data: DS
 *
*/
void rotr(run_data *data)
{
	stack_t *p = data->head;
	int n;

	if (data->stack_counter > 1)
	{
		for (; p; p = p->next)
		{
			n = p->n;
		}
		add_dnodeint(&data->head, n);
		delete_dnodeint_at_index(&data->head, data->stack_counter--);
	}
}
