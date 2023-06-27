#include <unistd.h>
#include "main.h"

/**
 * k_putint - print a char at a time
 * @n: number to be printed
 * no return void func
 */
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
	}
	rev = 0;
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
