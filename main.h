#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <stddef.h>

extern char **environ;
char *_getenv(char *v);
void handler(int signum);
char *_itoa(int n);
int _strlen(char *s);
int _isspace(char c);
bool is_empty(const char *str);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *my_strtok(char *str, char *delim);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
void rev_str(char *str, int len);
int builtin_env(void);
void print_command_not_found_error(char *executable,
	char *command, int indecs);
void execute_command(char **argv, char *actual_command);
void cleanup_resources(char *actual_command, char *path_copy, char **argv);
int execmd(char **argv, char *executable, int indecs);
char *construct_file_path(char *directory, char *command);
char *get_location(char *command);
int compare(const void *a, const void *b);
int my_getline(char **lineptr, size_t *n, int fd);
void cleanup_memory(char *lineptr, char *lineptr_copy, char **argv);
char **my_tokenize_input(char *lineptr, char *lineptr_copy);
#endif
