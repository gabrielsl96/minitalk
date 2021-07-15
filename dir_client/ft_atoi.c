#include "../minitalk.h"

int	ft_isdigit(char num)
{
	if (num < '0' || num > '9')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	count;
	int	signal;

	num = 0;
	count = 0;
	signal = 1;
	while ((nptr[count] >= 7 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			signal = -1;
		count++;
	}
	while (ft_isdigit(nptr[count]))
	{
		num = num * 10 + (nptr[count] - 48);
		count++;
	}
	return (num * signal);
}
