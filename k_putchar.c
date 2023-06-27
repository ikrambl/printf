#include <unistd.h>
#include "main.h"

/**
 * k_putchar - print a char at a time
 * @c: char to be printed
 * no return void func
 */
void k_putchar(int c)
{
	write(1, &c, 1);
}
