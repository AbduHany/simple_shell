#include "shell.h"

/**
 * create_path_list - builds a linked list of the PATH directories.
 *
 * Return: head pointer to the first node/struct_pathdir in the
 * linked list.
 */
pathdirs_t *create_path_list(void)
{
	unsigned int dirnum, i;
	char *pathstring, *tmpstr;
	pathdirs_t *head = NULL, *new, *temp;

	pathstring = _getenv("PATH");
	tmpstr = malloc(strlen(pathstring) + 1);
	if (tmpstr == NULL)
		return (NULL);
	strcpy(tmpstr, pathstring);
	for (dirnum = 1, i = 0; pathstring[i] != '\0'; i++)
	{
		if (pathstring[i] == ':')
			dirnum++;
	}
	for (i = 0; i < dirnum; i++, tmpstr = NULL)
	{
		new = malloc(sizeof(pathdirs_t));
		if (new == NULL)
			return (NULL);
		new->dir = strtok(tmpstr, ":");
		new->next = NULL;
		if (head == NULL)
		{
			head = new;
			continue;
		}
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (head);
}
