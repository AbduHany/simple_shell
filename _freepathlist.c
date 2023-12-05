#include "shell.h"

/**
 * _freepathlist - frees a pathdirs_t list.
 * @head: head of linked list of pathdirs_t nodes.
 *
 * Return: void.
 */
void _freepathlist(pathdirs_t *head)
{
	pathdirs_t *temp;

	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(head->dir);
		free(head);
		head = temp;
	}
}
