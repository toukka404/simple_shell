#include "main.h"

/**
  * changes_directories -  function that changes working directory
  *
  * @paths: The new current working directory
  *
  * Return: 0 on success, -1 on failure.
  */

int changes_directories(const char *paths)
{
	char *buffer = NULL;
	size_t size = 1024;

	if (paths == NULL)
		paths = getcwd(buffer, size);
	if (chdir(paths) == -1)
	{
		perror(paths);
		return (49);
	}
	return (1);
}


/**
 * child_process - Function that creates a sub process.
 * @cmds: Pointer to tokenize command
 * @names: shell name of pointer.
 * @env: environ variable pointers.
 * @cycle: number of executed cycles.
 * Return: Nothing.
 */
void child_process(char **cmds, char *names, char **env, int cycle)
{
	int pid = 0;
	int statuses = 0;
	int waitingResults = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_memry_exit(cmds);
	}
	else if (pid == 0)
	{
		execute_cmd(cmds, names, env, cycle);
		memry_freed(cmds);
	}
	else
	{
		waitingResults = waitpid(pid, &status, 0);
		if (waitingResults < 0)
		{
			free_memry_exit(cmds);
		}
		memry_freed(cmds);
	}
}
