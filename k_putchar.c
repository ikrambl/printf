#include <unistd.h>
#include "main.h"

/**
 * k_putchar - print a char at a time
 * @c: char to be printed
 * return: char
 */
int k_putchar(char c)
{
	return (write(1, &c, 1));
}
