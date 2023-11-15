#include "main.h"

/**
 *_isspace - check the character of input
 *@c: the character of input
 *Return: 0 if false, 1 if true
 */

int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r');
}

/**
 *is_empty - Check if a string consists only of whitespace characters.
 *@str: The input string to be checked.
 *Return: True if the string is empty or contains only whitespace characters,
 *false otherwise.
 */
bool is_empty(const char *str)
{
	while (*str)
	{
		if (!_isspace((unsigned char) *str))
		{
			return (false);
		}

		str++;
	}

	return (true);
}

/**
 *trimString - Trim leading and trailing spaces from a string.
 *@str: The input string to be trimmed.
 */
void trimString(char *str)
{
	char *end;

	while (*str == ' ')
	{
		str++;
	}

	if (*str == '\0')
	{
		exit(0);
	}
	else
	{
		end = str + _strlen(str) - 1;

		while (end > str && *end == ' ')
		{
			end--;
		}

		end[1] = '\0';
	}
}
