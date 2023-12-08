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
 * _freeall - frees the tmpstr, new node pointer and
 * linked list through the head pointer.
 * @tmplist: array of strings of tokens.
 * @tmpstr: pointer to the path string.
 * @new: pathdirs_t pointer to the new node.
 * @head: pathdirs_t pointer to the head of the list.
 *
 * Return: void.
 */
void _freeall(char **tmplist, char *tmpstr, pathdirs_t *new, pathdirs_t *head)
{
	if (tmplist)
		_freedouble(tmplist);
	if (tmpstr)
		free(tmpstr);
	if (new)
		free(new);
	if (head)
		_freepathlist(head);
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
	char *pathstring = _getenv("PATH"), *tmpstr, *dir, **tmplist;
	pathdirs_t *head = NULL, *new, *temp;

	if (pathstring == NULL || pathstring[0] == '\0')
		return (NULL);
	tmpstr = malloc(_strlen(pathstring) + 1);
	if (tmpstr == NULL)
		return (NULL);
	_strcpy(tmpstr, pathstring);
	dirnum = calcdirnum(tmpstr);
	tmplist = _strtolist(tmpstr, ':');
	for (i = 0; i < dirnum; i++)
	{
		new = malloc(sizeof(pathdirs_t));
		if (new == NULL)
		{
			_freeall(tmplist, tmpstr, new, head);
			return (NULL);
		}
		dir = malloc(_strlen(tmplist[i]) + 1);
		if (dir == NULL)
		{
			_freeall(tmplist, tmpstr, new, head);
			return (NULL);
		}
		dir = _strcpy(dir, tmplist[i]);
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
	_freedouble(tmplist);
	free(tmpstr);
	return (head);
}
