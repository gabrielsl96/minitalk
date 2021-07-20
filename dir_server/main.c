#include "../minitalk.h"

void	handler_sig_receiver(int signal)
{
	static int	i;
	static char	c;

	if ((signal == SIGUSR1) && ((i % 8) > 0))
		c = c << 1 | 1;
	else if (signal == SIGUSR2)
		c = c << 1;
	else
		c = c | 1;
	i += 1;
	if ((i % 8) == 0)
	{
		write(1, &c, 1);
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		write(1, "\033[33mWarning:\nArguments are not needed.\033[0m\n", 45);
		return (-1);
	}
	pid = getpid();
	write (1, "\033[1;32m----------SERVER LAUNCHED----------\033[0m\n", 48);
	write(1, "\033[34mPID: ", 11);
	ft_putnmb(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handler_sig_receiver);
	signal(SIGUSR2, handler_sig_receiver);
	while (1)
		pause();
	return (0);
}
