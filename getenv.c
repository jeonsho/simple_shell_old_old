#include "main.h"

/**
 *_getenv - gets environment path
 *@v: the env variable
 *Return: the path
 */
char *_getenv(char *v)
{
	size_t len = _strlen(v);
	char **env = environ;

	while (*env)
	{
		size_t i;

		for (i = 0; i < len; ++i)
		{
			if ((*env)[i] != v[i])
				break;
		}

		if (i == len && (*env)[len] == '=')
			return (&(*env)[len + 1]);

		env++;
	}

	return (NULL);
}
