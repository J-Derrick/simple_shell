#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	int is_interactive = 0;

	if (isatty(STDIN_FILENO) && info->readfd <= 2)
		is_interactive = 1;

	return (is_interactive);
}

/**
 * is_delim - checks if character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	int is_delimiter = 0;

	while (*delim != '\0')
	{
		if (*delim == c)
		{
			is_delimiter = 1;
			break;
		}

		delim++;
	}

	return (is_delimiter);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int flag = 0;
	unsigned int result = 0;

	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;

		i++;
	}
	int output = (sign == -1) ? -result : result;

	return (output);
}
