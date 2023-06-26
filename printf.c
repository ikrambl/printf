#include "main.h"
void k_putchar(int c)
{
    write(1, &c, 1);
}

void k_putint(int n)
{
	int rev;
    if (n < 0)
    {
        k_putchar('-');
        n = -n;

    }

    if (n == 0)
    {
        k_putchar('0');
        return;
    }

    rev= 0;
    while (n > 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    while (rev > 0)
    {
        k_putchar('0' + (rev % 10));
        rev /= 10;
    }
}
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
					while (*s)
					{
						k_putchar(*s);
						s++;
						sum++;
					}
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
