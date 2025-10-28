/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:54:02 by itoudji           #+#    #+#             */
/*   Updated: 2024/01/30 12:35:05 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_realloc(char *str)
{
	char	*res;

	res = NULL;
	if (!ft_strlen(str))
		return (ft_calloc(STR_INCR + 1, sizeof(char)));
	else
	{
		res = ft_calloc (ft_strlen(str) + STR_INCR + 1, sizeof(char));
		ft_strlcpy(res, str, ft_strlen(str));
	}
	if (str)
		free(str);
	return (res);
}

char	*end_msg(int pid, char **str, char *c)
{
	ft_printf("%s\n", *str);
	kill(pid, SIGUSR2);
	if (*str)
		free(*str);
	usleep(300);
	*c = 0;
	return (NULL);
}

void	sig_handler_info(int sig, siginfo_t *info, void	*ucontext)
{
	static int	i = 0;
	static char	c = 0;
	static char	*msg = NULL;

	(void)ucontext;
	c |= (sig == SIGUSR2) << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			msg = end_msg(info->si_pid, &msg, &c);
		else
		{
			i = ft_strlen(msg);
			if (i % STR_INCR == 0)
				msg = ft_realloc(msg);
			msg[i] = c;
			c = 0;
		}
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	(void)av;
	if (ac == 1)
	{
		ft_printf("PID : %d\n", getpid());
		act.sa_sigaction = sig_handler_info;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		while (1)
			pause();
	}
	return (0);
}
