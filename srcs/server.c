/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:20:29 by pedro             #+#    #+#             */
/*   Updated: 2025/08/16 16:13:57 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int bin_to_char(int sig, char *msg)
{
	static int i;
	static char c;
	static int index;

	c =  (sig << i) | c;
	if (i == 7)
	{	
	
		msg[index++] = c;
		if (c == 0)
		{	
			printf("%s\n", msg);
			index = 0;
		}
		i = 0;
		c = 0;
		if (index == 0)
			return (1);
	}
	else
		i++;
	return (0);
}

void handler_sigusr(int sig, siginfo_t *i)
{
	static char msg[LINE_MAX + 1];

	if(bin_to_char(sig == SIGUSR2, msg))
		kill(i->si_pid, SIGUSR2);
	else
		kill(i->si_pid, SIGUSR1);
}

int main ()
{
    int pid = getpid();
	struct sigaction	action;
	
    printf("PID: %i\n", pid);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = (void *) handler_sigusr;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

    while(1)
		pause();
}