#include "main.h"

/**
 * _printf - printf like func
 * @format: format to be print
 * @...: arguments
 * Return: sum of characters
 */
int _printf(const char *format, ...)
{
	va_list ag;
	char c;
	char *s;
	int n;
	int sum = 0;

	va_start(ag, format);

	while (*format)
	{
		if (*format == '%')
		{
			{
				format++;
			}
			switch (*format)
			{
				case 'c':
				{
					c = (char)va_arg(ag, int);
					k_putchar(c);
					sum++;
				}
					break;
				case 's':
				{
					s = va_arg(ag, char*);
					k_putstr(s);
				}
					break;
				case '%':
				{
					k_putchar('%');
					sum++;
				}
					break;
				case 'd':
				{
					n = va_arg(ag, int);
					k_putint(n);
					sum++;
				}
					break;
				case 'i':
				{
					n = va_arg(ag, int);
					k_putint(n);
					sum++;
				}
				break;
				default:
				{
					k_putchar('%');
					k_putchar(*format);
					sum += 2;
				}
					break;
			}
		}
		else
		{
			k_putchar(*format);
			sum++;
		}
		format++;
	}
	va_end(ag);

	return (sum);
}
