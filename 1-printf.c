#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * op_i - prints integers using putchar
 * @n: integer to print
 * Return: void
 */
int op_i(va_list n)
{
	int a, p10 = 1, len = 0, i, j;
	unsigned int res, res1;

	a = va_arg(n, int);
	/* Menos de 0 es negativo */
	if (a < 0)
	{
		len = len + _putchar('-');
		res = a * -1;
	}
	else
		res = a;
	res1 = res;
	/* Potencia 10 */
	i = 0;
	while (res1 > 9)
	{
		p10 *= 10;
		res1 /= 10;
		i++;
	}
	j = 0;
	/* Mientras p10 es diferente de 0 */
	while (j <= i)
	{
		len = len + _putchar(res / p10 + '0');
		res = res % p10;
		p10 = p10 / 10;
		j++;
	}
	return (len);
}


/**
 *rangeof - Recognize a value to print.
 *@n: Number to convert.
 *Return: An integer.
 */
int rangeof(int n)
{
	int number = n;
	char digit, negative = '-';

	if (number < 0)
	{
		number = -number;
		write(1, &negative, 1);
	}

	if (number / 10 > 0)
		rangeof(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
	return (number);
}

/**
 *op_d - Prints a integer.
 *@d: Character to integer.
 *Return: An integer.
 */

int op_d(va_list d)

{
	int a;

	a = va_arg(d, int);
	rangeof(a);
	return (0);
}
