#include "minitalk.h"

void	Signal(int signum, void *handler, bool use_other)
{
	struct sigaction	sa = {0};

	if (use_other)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
}
