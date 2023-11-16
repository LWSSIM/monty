#include "monty.h"

/**
* get_op - fetch upcode function
* @data: read command
*
* Return: ptr to command function || int
*/
void get_op(run_data *data)
{
	instruction_t op[] = {
		{"push", push}, {"pall", pall}
		, {NULL, NULL}
		};
	int i;

	for (i = 0; op[i].opcode; i++)
	{
		if (!strcmp(op[i].opcode, *data->parsed))
		{
			op[i].f(data);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", data->linen,
	data->parsed[0]);
	free_data(data), free_stack(data->head), fclose(data->f);
	exit(EXIT_FAILURE);
}

/**
* interpreter - execute opcode logic
* @data: ds
*
* Return: int
*/
int interpreter(run_data *data)
{

	get_op(data);

	return (0);
}
