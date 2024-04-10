/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parrot <parrot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:50:35 by allera-m          #+#    #+#             */
/*   Updated: 2024/04/09 19:45:21 by parrot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *str)
{
	int             i;
	int             signo;
	unsigned long   res;
	unsigned long   a;

	i = 0;
	signo = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	a = LONG_MAX + (signo == -1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((a / 10 < res) || (a + (str[i] - '0') < res * 10))
			return (a * signo);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * signo);
}

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}