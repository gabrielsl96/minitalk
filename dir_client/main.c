#include "../minitalk.h"

void	end_mss(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(700);
	}
}

void	send_bits(char c, int pid)
{
	int	i;
	int	buff[8];
	int	signal[2];

	i = 7;
	signal[0] = SIGUSR2;
	signal[1] = SIGUSR1;
	while (i >= 0)
	{
		buff[i] = ((c & 1) > 0);
		c >>= 1;
		i--;
	}
	while (++i < 8)
	{
		if ((kill(pid, signal[buff[i]]) != 0))
		{
			write(1, "\033[1;31mError:\n\033[0;31mFail send signal!\033[0m\n", 44);
			exit(-1);
		}
		usleep(700);
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
	end_mss(pid);
	return (0);
}
