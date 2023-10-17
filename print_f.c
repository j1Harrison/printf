#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int chara_print = 0;

	while (*format && chara_print >= 0)
	{
	if (*format == '%')
	{
	format++;
	if (*format == 'c')
	{
	char c = va_arg(args, int);

	chara_print += write(1, &c, 1);
	}
	else if (*format == 's')
	{
		char *str = va_arg(args, char*);

		while (*str)
		{
		chara_print += write(1, str, 1);
		str++;
		}
	}
	else if (*format == '%')
	{
	chara_print += write(1, "%", 1);
	}
	}
	else
	{
	chara_print += write(1, format, 1);
	}
	format++;
	}
	va_end(args);
	return ((chara_print < 0) ? -1 : chara_print);
}
