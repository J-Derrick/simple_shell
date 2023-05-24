#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int index = 0;

	if (!str)
		return;
	for (int i = 0; str[i] != '\0'; i++)
	{
		_eputchar(str[i]);
	}

}

/**
 * _eputchar - writes the character c to standard error
 * @c: The character to print
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
		if (i >= WRITE_BUF_SIZE || c == BUF_FLUSH)
		{
			for (int j = 0; j < i; j++)
			{
				write(2, &buf[j], 1);
			}
			i = 0;
		}
	}
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int index;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || index >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, index);
		index = 0;
	}

	if (c != BUF_FLUSH)
		buffer[index++] = c;

	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: The number of characters put
 */
int _putsfd(char *str, int fd)
{
	int count = 0;

	if (!str)
		return (0);

	while (*str)
	{
		count += _putfd(*str++, fd);
	}

	return (count);
}
