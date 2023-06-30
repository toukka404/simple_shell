#include "main.h"

/**
 * strings_compare - Compares 2 strings
 * @string1: comparison 1st string
 * @string2: string 2nd for comparison
 * Return: if same, 0 if not the same
 */

int strings_compare(char *string1, char *string2)
{
	unsigned int i = 0;

	while (string1[i])
	{
		if (string1[i] != string2[i])
			return (0);
		i++;
	}

	return (1);
}


/**
 * strings_length - Finds the length of a strings
 * @string: string pointer
 * Return: length of the string
 */
unsigned int strings_length(char *string)
{
	int len = 0;

	if (!string)
		return (0);

	while (*string++)
		len++;
	return (len);
}


/**
 * strings_copy - copies a string to another destination
 * @desti: pointer to copied string destination
 * @sources: pointer to string copied from
 * Return: Pointer to copied string
 */

char *strings_copy(char *desti, char *sources)
{
	char *temp = desti;

	while (*sources)
		*desti++ = *sources++;
	*desti = '\0';
	return (temp);
}


/**
 * string_conc - Function that concatenates 2 strings.
 * @desti: destination for the concatenation
 * @sources: an input string
 * Return: pointer to the resulting strings
 */

char *string_conc(char *desti, char *sources)
{
	char *temp = desti;

	while (*desti)
		desti++;

	*desti++ = '/';
	while (*sources)
		*desti++ = *sources++;
	return (temp);
}


/**
 * string_int - that converts string to integer.
 * @string: Input string.
 * Return: integer equivalent.
 */
int string_int(char *string)
{
	int iz;
	int sign = 1, str_z = 0, output;
	unsigned int result = 0;

	for (iz = 0;  string[iz] != '\0' && str_z != 2; iz++)
	{
		if (string[iz] == '-')
			sign *= -1;

		if (string[iz] >= '0' && string[iz] <= '9')
		{
			str_z = 1;
			result *= 10;
			result += (string[iz] - '0');
		}
		else if (str_z == 1)
			str_z = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
