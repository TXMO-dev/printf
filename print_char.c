#include "main.h"
#include <unistd.h>

/**
 * print_char - print character
 *
 * @args: argument.
 *
 * Return: count of chars.
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}
