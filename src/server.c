/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parrot <parrot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:03:30 by allera-m          #+#    #+#             */
/*   Updated: 2024/04/09 21:05:08 by parrot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static int	bit;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write (1, &i, 1);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	struct	sigaction sig;

	sig.sa_sigaction = handler;
	(void)argv;
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\nServer is running, waiting the message...\n", 44);
	check_sig_state(sigaction(SIGUSR1, &sig, NULL));
	check_sig_state(sigaction(SIGUSR2, &sig, NULL));
	if (argc != 1)
		return(0);
	else
	{
		while (1)
		{
			pause();			
		}
	}
}