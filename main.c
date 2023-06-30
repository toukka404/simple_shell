#include "main.h"

/**
 * main - main shell
 * @num_args: Number of inputed args.
 * @arry_args: Pointer to array of inputed args.
 * @env: Pointer to array of env variables.
 * Return: 0.
 */

int main(int num_args, char **arry_args, char **env)
{
	char *buff = NULL, **commands = NULL;
	size_t buffersize = 0;
	ssize_t chars_reading = 0;
	int cycle = 0;
	(void)num_args;

	while (1)
	{
		cycle++;
		signal(SIGINT, signal_handler);
		chars_reading = getline(&buff, &buffersize, stdin);
		if (chars_reading == -1)
			handles_EOF(buff);
		else if (*buff == '\n')
			free(buff);
		else
		{
			buff[strings_length(buff) - 1] = '\0';
			commands = tokenizing(buff, " \0");
			free(buff);

			if (strings_compare(commands[0], "exit") != 0)
			{
				exits_shell(commands);
			}
			else if (strings_compare(commands[0], "cd") != 0)
			{
				changes_directories(commands[1]);
			}
			else
				child_process(commands, arry_args[0], env, cycle);
		}
		fflush(stdin);
		buff = NULL, buffersize = 0;
	}
	if (chars_reading == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * signal_handler - Handle Ctr + C signal.
 * @prompt_handle: prompt to handle.
 * Return: Nothing.
 */

void signal_handler(int prompt_handle)
{
	(void)prompt_handle;
	write(STDOUT_FILENO, "\n(SimpleShell) $ ", 16);
}


/**
 * prompt - Prints the prompt.
 * Return: Nothing
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(simpleshell) $ ", 15);
}


/**
 * exits_shell - Exits the shell.
 * @commands: Pointer to tokenized command.
 * Return: nothing
 */
void exits_shell(char **commands)
{
	int status = 0;

	if (commands[1] == NULL)
	{
		memry_freed(commands);
		exit(EXIT_SUCCESS);
	}

	status = string_int(commands[1]);
	memry_freed(commands);
	exit(status);
}


/**
 * handles_EOF - Checks if buffer is EOF
 * @buff_strings: Pointer to the input string.
 * Return: Nothing
 */
void handles_EOF(char *buff_strings)
{
	if (buff_strings)
	{
		free(buff_strings);
		buff_strings = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buff_strings);
	exit(EXIT_SUCCESS);
}
