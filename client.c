/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:55:50 by skvackov          #+#    #+#             */
/*   Updated: 2024/10/09 14:02:41 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*plzencrypt(char message)
{
	static char	messagetosend[9];
	int			numberofbit;
	int			chartobit;

	numberofbit = 7;
	chartobit = (int)message;
	while (numberofbit >= 0)
	{
		if ((chartobit >> numberofbit) & 1)
			messagetosend[7 - numberofbit] = '1';
		else
			messagetosend[7 - numberofbit] = '0';
		numberofbit--;
	}
	messagetosend[8] = '\0';
	return (messagetosend);
}

static void	plzsend(int pid, char *message)
{
	int	count;

	count = 0;
	while (message[count] != '\0')
	{
		if (message[count] == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("ERROR sending sigusr1");
				exit(1);
			}
		}
		else if (message[count] == '0')
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("ERROR sending sigusr2");
				exit(1);
			}
		}
		count++;
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*themessage;
	int		count;

	count = 0;
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Please check PID");
		return (1);
	}
	while (argv[2][count] != '\0')
	{
		themessage = plzencrypt(argv[2][count]);
		plzsend(pid, themessage);
		count++;
	}
	return (0);
}
