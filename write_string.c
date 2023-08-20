#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * write_string - writes a string to fd 1 or returns -1
 * @args: variadic list to pick the string from
 *
 * Return: strlen or -1
 */

int write_string(va_list *args)
{
	char *s;

	s = va_arg(*args, char *);

	if (!s)
		return (write(1, "(nil)", -1));
	return (write(1, s, strlen(s)));
}
