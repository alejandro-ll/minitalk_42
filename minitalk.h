#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifndef MINITALK_H
# define MINITALK_H

int		ft_atoi(const char *str);
void	ft_putnbr(int num);
void	check_sig_state(int status_num);

#endif