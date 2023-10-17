#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int chars_written = 0;
	int i = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				chars_written++;
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				chars_written += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			chars_written++;
		}
		i++;
	}

	va_end(args);
	return (chars_written);
}
