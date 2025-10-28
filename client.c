/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:56:40 by itoudji           #+#    #+#             */
/*   Updated: 2024/01/20 12:54:25 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg;

void	send_bit(int pid, int *pos, int *i)
{
	int	pid_bool;

	pid_bool = 0;
	if ((g_msg[*pos] >> *i) & 1)
		pid_bool = kill(pid, SIGUSR2);
	else
		pid_bool = kill(pid, SIGUSR1);
	if (pid_bool == -1)
	{
		ft_printf("\e[0;31mError : wrong PID\n\e[0;31m");
		exit(0);
	}
	(*i)++;
	if (*i == 8)
	{
		*i = 0;
		(*pos)++;
	}
}

void	sig_handler_info(int sig, siginfo_t *info, void	*ucontext)
{
	static int	i = 0;
	static int	j = 1;

	(void)ucontext;
	if (sig == SIGUSR2)
	{
		ft_printf("\e[0;32m\nMessage received\n\e[0;32m");
		exit(0);
	}
	else if (sig == SIGUSR1)
	{
		send_bit(info->si_pid, &i, &j);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					i;

	if (ac == 3 && ft_strlen(av[1]) > 0)
	{
		g_msg = av[2];
		i = 0;
		act.sa_sigaction = sig_handler_info;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		send_bit(ft_atoi(av[1]), &i, &i);
		while (1)
			pause();
	}
	else
	{
		ft_printf("\e[0;31mError : Wrong arguments entry\n\e[0;31m");
		return (1);
	}
	return (0);
}
