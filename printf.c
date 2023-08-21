#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * handle_specifiers - handles char
 * @args: variadic arguments
 * @format: the initial string to extract specifiers from
 *
 * Return: int
 */

int handle_specifiers(const char **format, va_list *args)
{
	int c;

	switch (*(++(*format)))
	{
		case 'c':
			c = write_char(args);
			break;
		case 's':
			c = write_string(args);
			break;
		case '%':
			c = write(1, "%", 1);
			break;
		case 'i':
		case 'd':
			c = write_int(args);
			break;
		default:
			--(*format);
			c = write(1, *format, 1);
			break;
	}
	return (c);
}

/**
 * _printf - mimics std printf
 * @format: format specifying string
 *
 * Return: number of chars printed or -1 on failure
 */

int _printf(const char *format, ...)
{
	int c, sum = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			c = handle_specifiers(&format, &args);
			if (c == -1)
				return (c);
			sum += c;
			format++;
		}
		else
		{
			c = write(1, format, 1);
			if (c == -1)
				return (c);
			sum++;
			format++;
		}
	}
	va_end(args);
	return (sum);
}
