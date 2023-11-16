#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: ptr->DLL struct head
 * @n: input data
 *
 * Return: & of new node or NULL
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new->n = n;
	new->prev = NULL;
	if (!(*head))
		new->next = NULL;
	else
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;
	return (*head);
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 * @head: ptr->DLL struct head
 * @n: input data
 *
 * Return: & new node or NULL
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *tail;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		for (tail = *head; tail->next; tail = tail->next)
			;
		new->prev = tail;
		tail->next = new;
	}
	return (new);
}
