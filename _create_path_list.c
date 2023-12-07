#include "shell.h"

/**
 * calcdirnum - calculates directory number in the PATH variable.
 * @val: value string of the PATH variable.
 *
 * Return: number of directories in PATH.
 */
int calcdirnum(char *val)
{
	int i, dirnum;

	for (dirnum = 1, i = 0; val[i] != '\0'; i++)
	{
		if (val[i] == ':')
			dirnum++;
	}
	return (dirnum);

}

/**
 * create_path_list - builds a linked list of the PATH directories.
 *
 * Return: head pointer to the first node/struct_pathdir in the
 * linked list.
 */
pathdirs_t *create_path_list(void)
{
	unsigned int dirnum, i;
	char *pathstring = _getenv("PATH"), *tmpstr, *dir, *tmpptr, *freeptr;
	pathdirs_t *head = NULL, *new, *temp;

	tmpstr = malloc(_strlen(pathstring) + 1);
	if (tmpstr == NULL)
		return (NULL);
	freeptr = tmpstr;
	_strcpy(tmpstr, pathstring);
	dirnum = calcdirnum(tmpstr);
	for (i = 0; i < dirnum; i++, tmpstr = NULL)
	{
		new = malloc(sizeof(pathdirs_t));
		if (new == NULL)
		{
			_freepathlist(head);
			return (NULL);
		}
		tmpptr = strtok(tmpstr, ":");
		dir = malloc(_strlen(tmpptr) + 1);
		if (dir == NULL)
		{
			free(tmpstr);
			free(new);
			_freepathlist(head);
			return (NULL);
		}
		dir = _strcpy(dir, tmpptr);
		new->dir = dir;
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
	free(freeptr);
	return (head);
}
