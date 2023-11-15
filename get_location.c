#include "main.h"
#define EXIT_COMMAND "exit"
#define ENV_COMMAND "/bin/env"

/**
 *construct_file_path - Constructs the absolute file path
 *@directory: The directory to append to the file path.
 *@command: The command to append to the file path.
 *Return: A dynamically allocated string containing the absolute path.
 */
char *construct_file_path(char *directory, char *command)
{
	size_t len;
	char *file_path;

	 len = _strlen(directory) + 1 + _strlen(command) + 1;
	 file_path = malloc(len);
	if (file_path == NULL)
		return (NULL);
	_strncpy(file_path, directory, len);
	file_path[len - 1] = '\0';
	_strncat(file_path, "/", 1);
	_strncat(file_path, command, len - _strlen(directory) - 2);
	return (file_path);
}

/**
 *get_location - Locates the absolute path of a command in the PATH env
 *@command: The command to locate.
 *Return: A dynamically allocated string containing the absolute path.
 */
char *get_location(char *command)
{
	struct stat buffer;
	char *path, *path_token, *path_copy, *file_path = NULL;

	if (command == NULL)
		return (NULL);
	path = _getenv("PATH");
	if (_strcmp(command, EXIT_COMMAND) == 0)
		return (_strdup(EXIT_COMMAND));
	if (_strcmp(command, "env") == 0)
		return (_strdup(ENV_COMMAND));
	if (path && _strlen(path) > 0)
	{
		path_copy = _strdup(path);
		if (path_copy == NULL)
			return (NULL);
		path_token = my_strtok(path_copy, ":");
		while (path_token != NULL)
		{
			file_path = construct_file_path(path_token, command);
			if (file_path == NULL)
			{
				free(path_copy);
				return (NULL);
			}
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = my_strtok(NULL, ":");
			}
		}
		free(path_copy);
	}
	if (stat(command, &buffer) == 0 && (command[0] == '/' || command[0] == '.'))
		return (_strdup(command));
	return (NULL);
}
