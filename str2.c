#include "main.h"

/**
 *_strncpy - Write a function that copies a string, with number of bytes
 *@dest: This is the output dest
 *@src: This is the input source
 *@n: This is the number of bytes to copy
 *
 *Return: Copied string with the number of bytes
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
 *_strncat - Write a function that concatenates two strings. it will use at
 *          most n bytes from src
 *
 *@dest: This is the output  dest
 *@src: This is the input src
 *@n: This is the number bytes fro src
 *
 *Return: This is my return
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	;
	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	if (j < n)
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
 *_strchr - function that locates a character in a string
 *@s: A pointer to the string
 *@c: The character we want to locate
 *
 *Return: char with result
 */
char *_strchr(char *s, char c)
{
	if (*s == '\0')
		return (s);
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}

		s++;
	}

	if (c == '\0')
		return (s);
	return ('\0');
}
/**
 *rev_str - reverse string
 *@str: string
 *@len: length
 */
void rev_str(char *str, int len)
{
	int b = 0, e = len - 1;
	char copy;

	while (b < e)
	{
		copy = str[b];
		str[b] = str[e];
		str[e] = copy;
		b++;
		e--;
	}
}
