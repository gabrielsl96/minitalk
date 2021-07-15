#include "../minitalk.h"

void	sigrecmsg(int signum)
{
	write(1, "\033[0m\n", 3);
	ft_putnmb(signum);
	write(1, "\n", 1);
	write(1, "EITA, FUI!!\n", 13);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;

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
	act.sa_handler = sigrecmsg;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	while (1)
		pause();
	return (0);
}
