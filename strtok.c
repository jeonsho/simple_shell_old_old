#include "main.h"
/**
 * my_strtok - Tokenize a string using specified delimiters
 * @str: The input string to be tokenized
 * @delim: The set of delimiter characters arators.
 * Return: A pointer to the next token in the string or NULL
 */
char *my_strtok(char *str, char *delim)
{
	static char *saved_ptr;
	char *token_start;

	if (str != NULL)
	{
		saved_ptr = str;
	}
	if (saved_ptr == NULL || *saved_ptr == '\0')
	{
		saved_ptr = NULL;
		return (NULL);
	}
	while (*saved_ptr != '\0' && _strchr(delim, *saved_ptr) != NULL)
	{
		saved_ptr++;
	}
	if (*saved_ptr == '\0')
	{
		saved_ptr = NULL;
		return (NULL);
	}

	token_start = saved_ptr;
	while (*saved_ptr != '\0' && _strchr(delim, *saved_ptr) == NULL)
	{
		saved_ptr++;
	}
	if (*saved_ptr != '\0')
	{
		*saved_ptr = '\0';
		saved_ptr++;
	}
	else
	{
		saved_ptr = NULL;
	}
	return (token_start);
}
