/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:08:50 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/22 17:49:19 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	join = malloc(sizeof(char) * (len + 2));
	if (!join)
		return (NULL);
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

void	print_out(char *stash)
{
	ft_printf("%s\n", stash);
	free(stash);
	stash = NULL;
}

void	bin_to_ascii(int sigsent)
{
	static int	bit;
	static int	c;
	static char	*stash;
	char		*temp;

	if (!stash)
		stash = ft_calloc(1, 1);
	if (sigsent == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		temp = str_char_join(stash, (char)c);
		free(stash);
		stash = temp;
		if (c == 0)
		{
			ft_printf("%s\n", stash);
			free(stash);
			stash = NULL;
		}
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("ERROR ->too many args");
		return (1);
	}
	ft_printf("Server PID=%d\n", getpid());
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGTERM, signal_handler);
	while (1)
	{
		signal(SIGUSR1, bin_to_ascii);
		signal(SIGUSR2, bin_to_ascii);
		pause();
	}
	return (0);
}
