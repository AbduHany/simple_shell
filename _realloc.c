#include "shell.h"
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the newly allocated memory.
 * @old_size: size in bytes of the allocated space for ptr.
 * @new_size: new size in bytes of the new memory block.
 *
 * Return: void pointer to the new allocated memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i, len;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		free(ptr);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size > old_size)
		len = old_size;
	else if (old_size > new_size)
		len = new_size;
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		*((char *) p + i) = *((char *) ptr + i);
	free(ptr);
	return (p);
}
