#include "main.h"

/**
 *_strlen - returns the length of a string
 *@s: string to evaluate
 *
 *Return: the length of the string
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}

/**
 *_strcpy - copies the string pointed to by src
 *including the terminating null byte (\0)
 *to the buffer pointed to by dest
 *@dest: pointer to the buffer in which we copy the string
 *@src: string to be copied
 *
 *Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';
	return (dest);
}

/**
 *_strcmp - Write a function that compares two strings.
 *
 *@s1: This is the input string
 *@s2: This is the input string
 *
 *Return: If the strings are equals return "0", if not return other number
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 **_strdup - copy of the string
 *@str: input
 *Return: pointer
 */

char *_strdup(char *str)
{
	int i, size;
	char *m;

	if (str == NULL)
		return (NULL);

	for (size = 0; str[size] != '\0'; size++)
	;
	size++;
	m = malloc(size * sizeof(*str));

	if (m == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		m[i] = str[i];
	return (m);
}
