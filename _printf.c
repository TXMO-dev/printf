#include "main.h"
#include <unistd.h>
/**
 * get_function - function specifiers.
 *
 * @con_spec: change format
 * @args: aguments
 *
 * Return: counter.
 */

int get_function(char con_spec, va_list args)
{
	int i = 0;
	int count_fun = 0;

	specifiers_t spec[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_mod},
		{'d', print_digit},
		{'i', print_digit},
		{'r', print_rev_string},
		{0, NULL}
	};

	while (spec[i].specifiers)
	{
		if (con_spec == spec[i].specifiers)
			count_fun += spec[i].f(args);
		i++;
	}

	if (count_fun == 0)
	{
		count_fun += _putchar('%');
		count_fun += _putchar(con_spec);
	}

	return (count_fun);
}
/**
 * _printf - like printf.
 *
 * @format: Format of(c,s,d).
 *
 * Return: count of chars.
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, count_fun;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i])
	{
		count_fun = 0;
		if (format[i] == '%')
		{
			if (!format[i + 1] || (format[i + 1] == ' ' && !format[i + 2]))
			{
				count = -1;
				break;
			}
			count_fun += get_function(format[i + 1], args);
			if (count_fun == 0)
				count += _putchar(format[i + 1]);
			if (count_fun == -1)
				count = -1;
			i++;
		}
		else
		{
			(count == -1) ? (_putchar(format[i])) : (count += _putchar(format[i]));
		}
		i++;
		if (count != -1)
			count += count_fun;
	}
	va_end(args);
	return (count);
}
