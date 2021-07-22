#include "../minitalk.h"

void	print_char(int bit, int pid)
{
	static int	i;
	static char	c;

	(void)pid;
	c = c | bit;
	i++;
	if ((i % 8) == 0)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

void	handler_sig_receiver(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	print_char(sig == SIGUSR1, info->si_pid);
}

void	set_handler(struct sigaction *act)
{
	act->sa_flags = SA_SIGINFO;
	act->sa_sigaction = handler_sig_receiver;
	sigemptyset(&act->sa_mask);
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
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
	set_handler(&act);
	while (1)
		pause();
	return (0);
}
