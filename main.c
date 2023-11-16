#include "monty.h"

/**
 * init_data - initialize structure
 * @data: data struct
 *
 */
void init_data(run_data *data)
{
	data->q = 0;
	data->stack_counter = 0;
	data->head = NULL;
	data->line = NULL;
	data->parsed[0] = NULL;
	data->parsed[1] = NULL;
	data->linen = 0;
}
/**
 * routine - RPEL from file
 * @data: data interpreter data
 *
 * Return: int stat
 */
int routine(run_data *data)
{
	ssize_t chars_read;
	size_t num;
	int stat = 0;

	init_data(data);
	do	{
		chars_read = _getline(&data->line, &num, data->f);
		data->linen++;
		if (chars_read == EOF || stat == -1)
		{
			fclose(data->f);
			free_data(data), free_stack(data->head);
			return (stat);
		}
		if (chars_read > 0 && check_space(data->line, chars_read))
		{
			stat = interpreter(data);
			free_data(data);
		}
	} while (chars_read != EOF);
	return  (stat);
}

/**
 * main - monty interpreter entry point
 * @ac: input args count
 * @av: input args vector
 *
 * Return: 0 || error
 *
 */
int main(int ac, char **av)
{
	run_data data;
	int st;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.f = fopen(av[1], "r");
	if (!data.f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	st = routine(&data);

	return (st);
}
