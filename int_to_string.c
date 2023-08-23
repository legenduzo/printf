#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * reverse_string - reverses string
 * @s: string to reverse
 *
 * Return: nothing
 */

void reverse_string(char *s)
{
	int start, end;
	char temp;

	end = strlen(s) - 1;
	for (start = 0; start < end; start++, end--)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
	}
}
/**
 * int_to_string - converts an int to a reversed string
 * @number: number to reverse
 *
 * Return: string
 */

char *int_to_string(int number)
{
	char *s;
	int i = 0;
	long n = number;

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
		n = -n;

	while (number != 0)
	{
		s[i++] = '0' + number % 10;
		number /= 10;
	}
	if (number < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse_string(s);
	return (s);
}
