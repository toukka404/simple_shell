#include "main.h"

/**
 * tokenizing - Split and create a full string cmd.
 * @strings: Delimiter for strtok.
 * @buffers: Pointer to input string.
 * Return: String with full cmd.
 */
char **tokenizing(char *buffers, const char *strings)
{
	char *tokens = NULL, **command = NULL;
	size_t bufferSizes = 0;
	int tokencounter = 0;

	if (buffers == NULL)
		return (NULL);

	bufferSizes = strings_length(buffers);
	command = malloc((bufferSizes + 1) * sizeof(char *));
	if (command == NULL)
	{
		perror("Buffers allocation error");
		free(buffers);
		memry_freed(command);
		exit(EXIT_FAILURE);
	}

	command = strtok(buffers, strings);
	while (tokens != NULL)
	{
		command[tokencounter] = malloc(strings_length(tokens) + 1);
		if (command[tokencounter] == NULL)
		{
			perror("Buffers allocation error");
			memry_freed(command);
			return (NULL);
		}
		strings_copy(command[tokencounter], tokens);
		tokens = strtok(NULL, strings);
		tokencounter++;
	}

	command[tokencounter] = NULL;
	return (command);
}
