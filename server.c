#include "minitalk.h"

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

char	*str_char_join(char const *str1, char c)
{
	size_t	len;
	int		i;
	char	*join;

	if (str1)
		len = ft_strlen(str1);
	else
		len = 0;
	join = malloc(sizeof(char) * (size + 2));
	if (!join)
	{
		free(join);
		return (NULL);
	}
	i = 0;
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	join[i++] = c;
	join[i] = '\0';
	return (join);
}

void	Bin_to_Ascii(int sigsent)
{
	static int	bit;
	static int	i;
	static char	*stash;
	char		temp;

	if (!stash)
		stash = ft_calloc(1,1);
	i++;
	if (sigsent == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		temp = str_char_join(stash, (char)i);
		free(str);
		str = temp;
		if (i = 0)
		{
			ft_printf("%s\n", stash);
			free(stash);
			stash = NULL;
		}
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("ERROR -> too many args")
		return (1);
	}
	ft_printf("Server PID=%d\n", getpid());

	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGTERM, signal_handler);
	signal

	while (1)
	{
		signal(SIGUSR1, Bin_to_Ascii);
		signal(SIGUSR2, Bin_to_Ascii);
		pause();
	}
	return (0);
}
