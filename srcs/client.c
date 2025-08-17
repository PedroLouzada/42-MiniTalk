/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:20:37 by pedro             #+#    #+#             */
/*   Updated: 2025/08/16 20:44:29 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	char_to_bin(int pid , char c)
{
	int i;
	
	i = 0;
	while (i < 8)
	{
		if ((c >> i++) & 1)	
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1500);
	}
}

void handler_sigusr(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Servidor recebeu a string!\n");
		exit(0);
	}
}

void ft_strlen(char *str, int pid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (j < 31)
	{
		if ((i >> j++) & 1)	
		{
			if (kill (pid, 0) != -1)
				kill(pid, SIGUSR2);
		}
		else
			kill(pid, SIGUSR1);
		usleep(1500);
	}
}

int	main(int ac, char **av)
{
	int pid;
	int i;

	pid = atoi(av[1]);
	i = 0;
	if (ac != 3 || pid < 1)
		return (0);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	ft_strlen(av[2], pid);
	while(1)
	{
		char_to_bin(pid, av[2][i]);
		if (!av[2][i])
			break;
		i++;
	}
	pause();
	return (0);
}
