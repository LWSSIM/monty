#include "monty.h"

/**
* push - push element to stack or queue
* @data: DS
*
*/
void push(run_data *data)
{
	int n;

	
	if (data->w_count != 2 || !check_int(data->parsed[1]))
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
 * check_int - check if str is int
 * @str: str to check
 * Return: 0 || 1
 */
int check_int(char *str)
{
	int i, flag = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		flag = 1;
		str++;
	}
	for (i = 0; i < (int)strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	if (flag == 1 && i == 0)
		return (0);
	return (1);
}
