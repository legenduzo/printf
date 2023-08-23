#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/**
 * write_int - writes a digit to fd 1 or returns -1
 * @args: variadic list to pick digit from
 *
 * Return: Number length or -1
 */

int write_int(va_list *args)
{
	int number, result;
	char *buffer;

	number = va_arg(*args, int);

	buffer = int_to_string(number);
	if (!buffer)
		return (-1);

	result = write(1, buffer, strlen(buffer));

	free(buffer);

	return (result);
}
