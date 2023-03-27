#include <stdarg.h>
#include "main.h"
/**
* _puts - prints a string to stdout
* @str: string to be printed
*
* Return: number of characters printed
*/
int _puts(char *str)
{
int len = 0;
char c;
while ((c = *(str++)))
{
_putchar(c);
len++;
}
return (len);
}
/**
 * _printf - prints a formatted string to stdout
 * @format: format string containing zero or more directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    len++;
                    break;

                case 's':
                    len += _puts(va_arg(args, char *));
                    break;

                case '%':
                    _putchar('%');
                    len++;
                    break;

                default:
                    _putchar('%');
                    _putchar(*format);
                    len += 2;
		    break;
}
}
else
{
_putchar(*format);
len++;
}
format++;
}
va_end(args);
return (len);
}
