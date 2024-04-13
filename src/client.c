/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parrot <parrot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:10:09 by allera-m          #+#    #+#             */
/*   Updated: 2024/04/09 20:35:36 by parrot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	confirm_reception(int signal)
{
	if (signal == SIGUSR2)
		write(1, "[OK] ", 5);
}

void	send_signal(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	struct	sigaction sig;	

	i = 0;
	pid = ft_atoi(argv[1]);
	sig.sa_handler = confirm_reception;
	check_sig_state(sigaction(SIGUSR1, &sig, NULL));
	check_sig_state(sigaction(SIGUSR2, &sig, NULL));
	if (argc != 3)
		return(0);
	else
	{
		while (argv[2][i])
		{
			send_signal(pid, argv[2][i]);
			i++;	
		}
		send_signal(pid, '\n');
	}
}