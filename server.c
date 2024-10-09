/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:55:53 by skvackov          #+#    #+#             */
/*   Updated: 2024/10/09 14:02:53 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char		g_getbit[9] = "00000000";

static int	translprint(char *totranslate)
{
	int		asciifirst;
	int		counter;
	char	chartoprint;

	asciifirst = 0;
	counter = 0;
	while (counter < 8)
	{
		if (totranslate[counter] == '1')
		{
			asciifirst += (1 << (7 - counter));
		}
		counter++;
	}
	chartoprint = (char)asciifirst;
	write(1, &chartoprint, 1);
	return (1);
}

static void	sigusr_handler(int sig)
{
	static int	count = 0;

	if (sig == SIGUSR1 && count < 8)
	{
		g_getbit[count] = '1';
		count++;
	}
	else if (sig == SIGUSR2 && count < 8)
	{
		g_getbit[count] = '0';
		count++;
	}
	if (count == 8)
	{
		g_getbit[count] = '\0';
		translprint(g_getbit);
		count = 0;
		ft_memset(g_getbit, '0', 8);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("process ID: %d\n", pid);
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	while (1)
	{
		pause();
	}
}
