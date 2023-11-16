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
