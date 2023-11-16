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
