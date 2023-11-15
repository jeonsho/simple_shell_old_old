#include "main.h"
/**
 *execute_command - Execute a command with arguments.
 *@argv: Array of arguments including the command.
 *@actual_command: The resolved absolute path of the command.
 */
void execute_command(char **argv, char *actual_command)
{
	if (_strcmp(actual_command, "/bin/env") != 0)
	{
		if (execve(actual_command, argv, environ) == -1)
		{
			free(actual_command);
			cleanup_memory(NULL, NULL, argv);
			exit(127);
		}
	}
	else
	{
		int i;

		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free(actual_command);
		cleanup_memory(NULL, NULL, argv);
		exit(0);
	}
}

/**
 *cleanup_resources - Free allocated resources.
 *@actual_command: Resolved absolute path of the command.
 *@path_copy: Copied PATH environment variable.
 *@argv: Array of arguments including the command.
 */
void cleanup_resources(char *actual_command, char *path_copy, char **argv)
{
	free(actual_command);
	cleanup_memory(NULL, NULL, argv);
	free(path_copy);
}

/**
 *execmd - Execute a command with arguments.
 *@argv: Array of arguments including the command.
 *@executable: Name of the executable file.
 *@indecs: Index of the current command.
 *Return: The status of the command execution.
 */
int execmd(char **argv, char *executable, int indecs)
{
	char *command = NULL, *actual_command = NULL;
	int status = 0;

	if (argv != NULL)
	{
		command = argv[0];
		actual_command = get_location(command);
		if (actual_command != NULL && (_strcmp(actual_command, "exit") != 0
					|| _strcmp(actual_command, "/bin/env") == 0))
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				cleanup_resources(actual_command, NULL, argv);
				exit(1);
			}
			else if (pid == 0)
				execute_command(argv, actual_command);
			else
			{
				if (waitpid(pid, &status, 0) == -1)
				{
					cleanup_resources(actual_command, NULL, argv);
					exit(1);
				}
			}
		}
		else if (actual_command != NULL && _strcmp(actual_command, "exit") == 0)
		{
			cleanup_resources(actual_command, NULL, argv);
			exit(0); }
		else
		{
			print_command_not_found_error(executable, command, indecs);
			cleanup_resources(actual_command, NULL, argv);
			exit(127); }
	}
	cleanup_resources(actual_command, NULL, argv);
	return (status);
}
