#include "minitalk.h"

/*void	sig_handler(int signum, siginfo_t *info, void *extra)
{

}
*/
void	signal_handler(int signum)
{
	if (signum == SIGINT)
		ft_printf("Received SIGINT\n", signum);
	else if (signum == SIGTSTP)
		ft_printf("Received SIGTSTP\n", signum);
	else if (signum == SIGTERM)
		ft_printf("Received SIGTERM\n", signum);
	exit(signum);
}

void	Bin_to_Ascii()

int	main(void)
{
	ft_printf("Server PID=%d\n", getpid());

	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGTERM, signal_handler);

	while (1)
	{
		pause();
	}
}
