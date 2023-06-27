#include "main.h"

/**
 * k_putstr - function that prints string
 * @str: string to be printed
 * no return
 */
void k_putstr(char *str)
{
	while (*str)
	{
		k_putchar(*str);
		str++;
	}
}
