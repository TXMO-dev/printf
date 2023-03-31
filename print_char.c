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
	unsigned char my_char;

	my_char = va_arg(c, int);
	_putchar(my_char);
	
	return (1);
}
