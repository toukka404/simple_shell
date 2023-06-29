#include "main.h"

/**
 * path_direc - gets the value from env PATH direction
 *
 * @env: environmental variables pointer
 *
 * Return: pathway for commands in directories
 */
char **path_direc(char **env)
{
	char **way_path = NULL, *values_path = NULL;
	unsigned int inte = 0;

	values_path = strtok(env[inte], "=");
	while (env[inte])
	{
		if (strings_compare(values_path, "PATH"))
		{
			values_path = strtok(NULL, "\n");
			way_path = tokenizing(values_path, ":");
			return (way_path);
		}
		inte++;
		values_path = strtok(env[inte], "=");
	}
	return (NULL);
}


/**
 * exe_command - function that executes a command
 *
 * @commands: command pointer of strings
 *
 * @names: name of the shell
 *
 * @env: environmental variables pointer
 * @cycle: number of executed cycles
 * Return: nothing
 */
void exe_command(char **commands, char *names, char **env, int cycle)
{
	char **way_path = NULL, *fullpaths = NULL;
	struct stat iz;
	unsigned int i = 0;

	if (strings_compare(commands[0], "env") != 0)
		print_environ(env);
	if (stat(commands[0], &iz) == 0)
	{
		if (execve(commands[0], commands, env) < 0)
		{
			perror(names);
			free_memry_exit(commands);
		}
	}
	else
	{
		path_ways = path_direc(env);
		while (path_ways[i])
		{
			fullpaths = string_conc(way_path[i], commands[0]);
			i++;
			if (stat(fullpaths, &iz) == 0)
			{
				if (execve(fullpaths, commands, env) < 0)
				{
					perror(names);
					memry_freed(way_path);
					free_memry_exit(commands);
				}
				return;
			}
		}
		error_messages(names, cycle, commands);
		memry_freed(way_path);
	}
}


/**
 * error_messages - Prints messages not found
 *
 * @names: shell name
 * @cycle: number of cycles
 * @commands: tokenized cmnd
 * Return: nothing
 */
void error_messages(char *names, int cycle, char **commands)
{
	char cycle_cee;

	cycle_cee = cycle + '0';
	write(STDOUT_FILENO, names, string_len(names));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cycle_cee, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, commands[0], string_len(commands[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}


/**
 * prints_environ - print all enviromental variable.
 * @env: enviromental variables pointer
 * return: nothing
 */
void prints_environ(char **env)
{
	size_t i = 0, length = 0;

	while (env[i])
	{
		length = string_len(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
