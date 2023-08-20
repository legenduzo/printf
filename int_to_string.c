#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/**
 * int_to_string - converts an int to a string
 * @number: int to convert
 *
 * Return: string
 */

char *int_to_string(int number)
{
	char *s;
	int i = 0, negative = 0;
	int start, end;
	char temp;

	s = malloc(12);
	if (!s)
	return (NULL);

	if (number == 0)
	{
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}

	if (number < 0)
	{
		negative = 1;
		number = -number;
	}

	while (number != 0)
	{
		s[i++] = '0' + number % 10;
		number /= 10;
	}

	if (negative)
		s[i++] = '-';

	s[i] = '\0';

	for (start = 0, end = i - 1; start < end; start++, end--)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
	}

	return (s);
}
