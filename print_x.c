#include "main.h"
/**
 * print_hex - to print hex number
 * @a: unusigned to print
 *
 * return: count
 */
int print_hex_x(unsigned int n)
{
	unsigned int len, powten, j, digit, num;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		len = 0;

		diff = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 16;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
 /**
 * print_x - prints lowercase hex
 * @x: unsigned int to print
 *
 * Return: size of the output
 */
int print_x(va_list x)
{
	return (print_hex_x(va_arg(x, unsigned int)));
}
