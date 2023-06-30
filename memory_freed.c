#include "main.h"

/**
 * free_memry_exit - free all the memory allocated and leave
 * @cmds: pointer to command memory of strings.
 * Return: Nothing.
 */

void free_memry_exit(char **cmds)
{
	size_t i = 0;

	if (cmds == NULL)
		return;

	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}

	if (cmds[i] == NULL)
		free(cmds[i]);
	free(cmds);
	exit(0);
}


/**
 * memry_freed - frees all the memory allocated for command
 * @cmds: Pointer to allocated memory
 * Return: nothing.
 */
void memry_freed(char **cmds)
{
	size_t i = 0;

	if (cmds == NULL)
		return;

	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}

	if (cmds[i] == NULL)
		free(cmds[i]);
	free(cmds);
}
