#include "monty.h"

/**
 * free_data - free main data structure
 * @data: ptr to data struct
 */
void free_data(run_data *data)
{
	if (data->f)
		fclose(data->f);

	if (data->line)
		free(data->line);

	if (data->head)
		free_stack(data->head);

	if (data->parsed)
		free_arr(data->parsed);
}
/**
 * free_arr - free array of strs
 * @arr: ptr the the array
 *
 */
void free_arr(char **arr)
{
	int i;

	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	arr = NULL;
}
/**
 * free_stack - frees a stack_t list.
 * @head: ptr->DLL head
 *
 */
void free_stack(stack_t *head)
{
	stack_t *p;

	if (!head)
		return;
	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}
}
