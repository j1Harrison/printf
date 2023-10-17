#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - A simplified implementation of printf that handles %c, %s, and %% specifiers.
 *
 * @format: The format string containing conversion specifiers.
 * @...: Additional arguments based on the specifiers in the format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */

int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list list_of_args;

	if (format == NULL)
	return (-1);

	va_start(list_of_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
		{
		format++;

		if (*format == 'c')
		{
			char c = va_arg(list_of_args, int);
			write(1, &c, 1);
			chara_print++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(list_of_args, char *);
			int str_len = 0;

			while (str[str_len] != '\0')
			str_len++;

			write(1, str, str_len);
			chara_print += str_len;
		}
		else if (*format == '%')
		{
		write(1, "%", 1);
		chara_print++;
		}
	}
	format++;
	}

	va_end(list_of_args);

	return (chara_print);
}
