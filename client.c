#include "minitalk.h"

void	Ascii_to_Bin(int pid, )

int	main(int ac, char **av)
{
	int server_pid;

	if (ac == 3)
	{

		server_pid = ft_atoi(av[1]);
	}
	else
		printf("Client needs 2 arguments! First ->PID Second ->Message");
	return (0);
}
