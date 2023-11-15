#include "main.h"
/**
 *main - Simple shell program that reads commands,tokenizes them,and execute
 *@ac: The number of command line arguments.
 *@arg: An array containing the command line arguments.
 *Return: If the program exits successfully.
 */
int main(int ac, char **arg)
{
	char *executable = arg[0];
	char *lineptr = NULL, *lineptr_copy = NULL, **argv;
	size_t n = 0, indecs = 0, status = 0;

	(void) ac;
	signal(SIGINT, handler);
	if (isatty(STDIN_FILENO))
                        write(STDOUT_FILENO, "& ", 2);
	while (1)
	{
		ssize_t nchars_read ;
		lineptr = NULL, lineptr_copy = NULL,   argv = NULL, n =0;
	/*	if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "& ", 2);*/
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			 /*cleanup_memory(lineptr, lineptr_copy, argv);*/
			exit(0);
		}
		lineptr_copy = malloc((nchars_read + 1) * sizeof(char));
		if (lineptr_copy == NULL)
		{
			cleanup_memory(lineptr, NULL, argv);
			exit(127); }
		if (!is_empty(lineptr))
		{
			_strcpy(lineptr_copy, lineptr);
			indecs++;
			argv = my_tokenize_input(lineptr, lineptr_copy);
			if (argv != NULL)
			{
				cleanup_memory(lineptr, lineptr_copy, NULL);
				 status = execmd(argv, executable, indecs);
				if (status != 0)
				{
				 cleanup_memory(NULL, NULL, argv);
					exit(0);
				}
			}
		}
		else
			cleanup_memory(lineptr, lineptr_copy, argv);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "& ", 2); }
	cleanup_memory(lineptr, lineptr_copy, argv);
	return (0); }

/**
 *handler - Signal handler for SIGINT (Ctrl+C).
 *@signum: Signal number (unused, required for signal function).
 */
void handler(int signum)
{
	(void) signum;
	signal(SIGINT, handler);
	write(STDOUT_FILENO, "\n &", 3);
}

/**
 *cleanup_memory - Free dynamically allocated memory.
 *@lineptr: Pointer to the original input line.
 *@lineptr_copy: Pointer to the copy of the input line.
 *@argv: Array of arguments.
 */
void cleanup_memory(char *lineptr, char *lineptr_copy, char **argv)
{
	int i;

	if (lineptr != NULL)
	{
		free(lineptr);
	}

	if (lineptr_copy != NULL)
	{
		free(lineptr_copy);
	}

	if (argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}

		free(argv);
	}
}

/**
 *print_command_not_found_error - Print "command not found" error message
 *to stderr.
 *@executable: The name of the executable (program) generating the error.
 *@command: The command that was not found.
 *@indecs: The index of the command.
 */
void print_command_not_found_error(char *executable, char *command, int indecs)
{
	char *error_msg = "not found";
	char *separator = ": ";
	char *newline = "\n";
/*	char *index = _itoa(indecs);
*/	  

	write(STDERR_FILENO, executable, _strlen(executable));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, "1", indecs );
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, newline, _strlen(newline));
}
