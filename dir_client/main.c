#include "../minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "\033[1;31mError:\nInvaid number of arguments.\033[0m\n", 47);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	ft_putnmb(pid);
}
