#include "monty.h"

/**
 * free_data - free main data structure
 * @data: ptr to data struct
 */
void free_data(run_data *data)
{
	if (data->line)
		free(data->line);
	data->line = NULL;

	if (data->parsed)
		free_arr(data);
}
/**
 * free_arr - free array of strs
 * @data: ptr the the array
 *
 */
void free_arr(run_data *data)
{
	int i;

	if (!data->parsed)
		return;
	for (i = 0; i < data->w_count; i++)
	{
		free(data->parsed[i]);
		data->parsed[i] = NULL;
	}
	free(data->parsed);
	data->parsed = NULL;
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
	head = NULL;
}
