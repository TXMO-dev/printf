#include <unistd.h>

/**
 * _putchar - print the character 
 *
 * @c: char to print
 *
 * Return: On success 1.
 * 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
