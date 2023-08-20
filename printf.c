#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/**
 * _printf - mimics std printf
 * @format: format specifying string
 *
 * Return: number of chars printed or -1 on failure
 */

int _printf(const char *format, ...)
{
	int a, b, s, c, d;
	int sum = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 'c')
		{
			c = write_char(&args);
			if (c == -1)
				return (c);
			sum += c;
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 's')
		{
			s = write_string(&args);
			if (s == -1)
				return (s);
			sum += s;
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			b = write(1, "%", 1);
			if (b == -1)
				return (b);
			sum++;
			format += 2;
		}
		else if ((*format == '%' && *(format + 1) == 'i') || (*format == '%' && *(format + 1) == 'd'))
		{
			d = write_int(&args);
			if (d == -1)
				return (d);
			sum += d;
			format += 2;
		}
		else
		{
			a = write(1, format, 1);
			if (a == -1)
				return (a);
			sum++;
			format++;
		}
	}
	va_end(args);
	return (sum);
}
