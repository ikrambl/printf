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
	int tmp;
	int div;
	int dgts;
	int count;

	va_start(ag, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(ag, int);
					sum += k_putchar(c);
					break;
				case 's':
					s = va_arg(ag, char*);
					while (*s)
					{
						sum += k_putchar(*s);
						s++;
					}
					break;
				case '%':
					sum += k_putchar('%');
				break;
				case 'd':
				case 'i':
				n = va_arg(ag, int);
				if (n < 0)
				{
					sum += k_putchar('-');
					n = -n;
				}
				tmp= n;
				dgts = 0;
					do
					{
						dgts++;
						tmp /= 10;
					}
					while (tmp != 0);
					div = 1;
					for (count = 1; count < dgts; count++)
					{
						div *= 10;
					}
					while (div != '0')
					{
						int digit = n / div;
						
						sum += k_putchar('0' + digit);
						n %= div;
						div /= 10;
					}
					break;
				default:
					sum += k_putchar('%');
					sum += k_putchar(*format);
					break;
			}
		}
			else
			{
				sum += k_putchar(*format);
			}
			format++;
	}
		va_end(ag);
		return (sum);
}
