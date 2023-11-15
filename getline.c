#include "main.h"
#define BUFFER_SIZE 1024
/**
 * allocate_if_null - Ensures that *lineptr
 * @lineptr: Pointer to the buffer to be allocated if it is initially NULL.
 * @n: Pointer to the size of the buffer.
 * This function checks if *lineptr is NULL.
 * with a default size specified by @n.
 */
void allocate_if_null(char **lineptr, size_t *n)
{
	if (*lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * my_getline - Custom getline function.
 * @lineptr: Pointer to the buffer to store the line.
 * @n: Pointer to the size of the buffer.
 * @fd: File descriptor to read from.
 * Return: Number of characters read, or -1 on failure.
 */
int my_getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos, buffer_end;
	size_t i = 0, j, new_size;
	char c, *new_buffer;

	if (lineptr == NULL || n == NULL)
		return (-1);
	allocate_if_null(lineptr, n);
	while (1)
	{
		if (buffer_pos >= buffer_end)
		{
			buffer_end = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_end <= 0)
				return (i == 0 ? -1 : (int) i);
		}
		c = buffer[buffer_pos++];
		if (i >= *n)
		{
			new_size = *n + BUFFER_SIZE;
			new_buffer = malloc(new_size);
			if (new_buffer == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1); }
			for (j = 0; j < i; ++j)
				new_buffer[j] = (*lineptr)[j];
			free(*lineptr);
			*lineptr = new_buffer;
			*n = new_size;
		}
		if (c == '\n')
			break;
		(*lineptr)[i++] = c;
	}
	(*lineptr)[i] = '\0';
	return ((int) i);
}
