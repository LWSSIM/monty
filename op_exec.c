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
		, {"pint", pint}, {"pop", pop}
		, {"swap", swap}, {"add", add}
		, {"sub", sub}, {"div", _div}
		, {"mul", mul}, {"mod", mod}
		, {"pchar", pchar}, {"pstr", pstr}
		, {"rotl", rotl}, {"rotr", rotr}
		, {NULL, NULL}
		};
	int i;

	for (i = 0; op[i].opcode; i++)
	{
		if (!strcmp(op[i].opcode, data->parsed[0]))
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
	data->parsed[0] = strtok(data->line, " \n\t");
	if (data->parsed[0] && data->parsed[0][0] == '#')
		return (0);
	if (!strcmp(data->parsed[0], "nop"))
		return (0);
	data->parsed[1] = strtok(NULL, " \n\t");
	get_op(data);

	return (0);
}
