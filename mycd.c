#include "shell.h"
/**
 * cd - changes the directory
 * @args: array of tokenized strings from input
 * @input: input from user
 * Return: 0 on success, 1 on failure
 */
int cd(char **args, __attribute__((unused)) char *input)
{
	char *home = get_env("HOME");
	static char *previous_dir, current_dir[PATH_MAX];
	char *dir[2];

	if (args[1] == NULL)
	{
		dir[0] = home;
		getcwd(current_dir, PATH_MAX);
	}
	else if (strings_compare(args[1], "-") == 0)
	{
		if (previous_dir != NULL)
			dir[0] = previous_dir;
		else
		{
			write(2, "./hsh: cd: OLDPWD not set\n", 26);
			return (1);
		}
	}
	else
	{
		dir[0] = args[1];
		getcwd(current_dir, PATH_MAX);
	}
	dir[1] = NULL;
	previous_dir = current_dir;
	getcwd(current_dir, PATH_MAX);
	if (chdir(dir[0]) != 0)
	{
		perror("cd");
		return (1);
	}
	else
	{
		getcwd(current_dir, PATH_MAX);
		setenv("PWD", current_dir, 1);
		return (0);
	}
	return (0);
}
