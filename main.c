#include "monty.h"

/**
 * _init - initialize structure
 * @data: data struct
 *
 */
void _init(run_data *data)
{
	stack_counter = 0;
	data->head = NULL;
	data->line = NULL;
	data->parsed = NULL;
	data->line_n = 1;
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
	int stat;

	_init(data);
	do	{
		chars_read = _getline(&data->line, num, data->f);
		if (chars_read == EOF || stat == -1)
		{
			free_data(data);
			return (stat);
		}
		data->parsed = get_token(data->line, " /n/t");
		stat = interpreter(data);
		if (stat == -1)
		{
			free_data(data);
			exit(EXIT_FAILURE);
		}
		free(data->line), free_arr(data->parsed);
		data->line_n++;

	} while (chars_read != EOF);
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
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	data.f = fopen(av[1], 'r');
	if (data.f != 0)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	st = routine(&data);

	return (0);
}
