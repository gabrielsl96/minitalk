#include "../minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnmb(int num)
{
	int	temp;
	int	n;

	n = num;
	if (num < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
		ft_putnmb(n / 10);
	temp = (num % 10) + '0';
	ft_putchar(temp);
}
