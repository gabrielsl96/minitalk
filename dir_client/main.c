#include "../minitalk.h"

void	end_mss(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
		kill(pid, SIGUSR2);
}

void	send_bits(char c, int pid)
{
	int	i;
	int	buff[8];

	i = 7;
	while (i >= 0)
	{
		buff[i] = ((c & 1) > 0);
		c >>= 1;
		i--;
	}
	while (++i < 8)
	{
		if (buff[i])
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(1, "\033[1;31mError:\nInvaid number of arguments.\033[0m\n", 47);
		return (-1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_bits(argv[2][i], pid);
		i++;
	}
	return (0);
}
