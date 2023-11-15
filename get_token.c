#include "main.h"

/**
 *my_tokenize_input - Tokenizes a string into an array of tokens.
 *@lineptr: The string to be tokenized.
 *@lineptr_copy: A pointer to a char pointer that
 *will store the resulting array of tokens
 *Return: If the tokenization is successful, it returns 0;
 *otherwise, it returns -1 on memory allocation failure.
 */

char **my_tokenize_input(char *lineptr, char *lineptr_copy)
{
	char *delim = " \n";
	int num_tokens = 0;
	char *token = NULL;
	int i = 0;
	char **argv = NULL;

	token = my_strtok(lineptr_copy, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = my_strtok(NULL, delim);
	}

	num_tokens++;
	argv = (char **) malloc(sizeof(char *) * num_tokens);
	if (argv == NULL)
	{
		return (NULL);
	}

	token = my_strtok(lineptr, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = (char *) malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(argv[i], token);
		token = my_strtok(NULL, delim);
	}

	argv[i] = NULL;

	return (argv);
}
