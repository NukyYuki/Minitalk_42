/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:35:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/22 16:55:58 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ascii_to_bin(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Error sending SIGUSR1");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Error sending SIGUSR2");
				exit(1);
			}
		}
		usleep(200);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	size_t	i;

	i = 0;
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			ft_printf("Server PID INVALID");
			return (1);
		}
		while (i <= ft_strlen(av[2]))
		{
			ascii_to_bin(server_pid, av[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("Client needs 2 arguments! First ->PID Second ->Message\n");
		return (1);
	}
	return (0);
}
