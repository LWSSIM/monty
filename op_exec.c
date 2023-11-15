#include "monty.h"

/**
* get_op - fetch upcode function
* @cmd: read command
*
* Return: ptr to command function || int
*/
int (*get_op(char *cmd))(run_data *)
{
	instruction_t op[] = {
		{"push", push}, {"pall", pall}};
	int i = 0;

	while (op[i].opcode)
	{
		if (!strcmp(op[i].opcode, cmd))
			return (op[i].f);
	}

	return (0);
}

/**
* interpreter - execute opcode logic
* @data: ds
*
* Return: int
*/
int interpreter(run_data *data)
{
	int stat;

	stat = get_op(data->parsed[0])(data);
	if (stat == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s", data->line_n, data->parsed[0]);
		return (-1);
	}
	return (stat);
}
