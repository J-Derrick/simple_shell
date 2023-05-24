/**
 * _strncpy - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @num_chars: the maximum number of characters to be copied
 *
 * Return: a pointer to the concatenated string
 */
char *_strncpy(char *destination, const char *source, int num_chars)
{
	int i;

	for (i = 0; i < num_chars - 1 && source[i] != '\0'; i++)
		destination[i] = source[i];

	for (; i < num_chars; i++)
		destination[i] = '\0';

	return (destination);
}

/**
 * _strncat - concatenates two strings
 * @destination: the first string
 * @source: the second string
 * @num_bytes: the maximum number of bytes to be used
 *
 * Return: a pointer to the concatenated string
 */
char *_strncat(char *destination, const char *source, int num_bytes)
{
	int dest_length, i;

	for (dest_length = 0; destination[dest_length] != '\0'; dest_length++)
		;

	for (i = 0; i < num_bytes && source[i] != '\0'; i++)
		destination[dest_length + i] = source[i];

	destination[dest_length + i] = '\0';

	return (destination);
}

/**
 * _strchr - locates a character in a string
 * @str: the string to be parsed
 * @character: the character to look for
 *
 * Return: a pointer to the memory area of the character in the string
 */
char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return ((char *)str);
		str++;
	}

	return (NULL);
}
