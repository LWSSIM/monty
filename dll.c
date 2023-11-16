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

/**
 * delete_dnodeint_at_index -  deletes the node at index linked list.
 * @head: ptr->head DDL struct
 * @index: node to be deleted
 *
 * Return: 1(succ) || -1(fail)
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *p, *c;
	unsigned int i;

	if (!head || !*head)
		return (-1);
	c = *head;
	if (index == 0)
	{
		*head = c->next;
		if (c->next)
			c->next->prev = NULL;
		free(c);
		return (1);
	}
	p = NULL;
	for (i = 0; i < index && c; i++)
	{
		p = c;
		c = c->next;
	}
	if (!c)
		return (-1);
	if (p)
		p->next = c->next;
	else
		*head = c->next;
	if (c->next)
		c->next->prev = p;
	free(c);
	return (1);
}
