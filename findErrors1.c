/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 *         -1 on error
 */
int _erratoi(char *s)
{
	unsigned long result = 0;

	if (*s == '+')
		s++; /* TODO: why does this make main return 255? */

	for (; *s != '\0'; s++)
	{
		if (*s >= '0' && *s <= '9')
		{
			result *= 10;
			result += (*s - '0');
			if (result > INT_MAX)
				return -1;
		}
		else
			return -1;
	}

	return result;
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 *
 * Return: Nothing
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int count = 0;
	unsigned int abs_val = (unsigned int)(input < 0 ? -input : input);

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		__putchar('-');
		count++;
	}

	for (unsigned int divisor = 1000000000; divisor > 0; divisor

