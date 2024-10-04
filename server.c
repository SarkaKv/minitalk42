/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:55:53 by skvackov          #+#    #+#             */
/*   Updated: 2024/10/04 14:59:20 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

char		g_getbit[9];

static void	sigusr_handler(int sig)
{
	static int	count = 0;

	if (sig == SIGUSR1 && count < 8)
	{
		g_getbit[count] = '1';
		count++;
		usleep(500);
	}
	else if (sig == SIGUSR2 && count < 8)
	{
		g_getbit[count] = '0';
		count++;
		usleep(500);
	}
	if (count == 8)
	{
		g_getbit[count] = '\0';
		if (ft_strcmp(g_getbit, "00000000") == 0)
		{
			exit(0);
		}
		count = 0;
		translprint(g_getbit);
	}
}

static void	translprint(char *totranslate)
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
	printf("%c", chartoprint);
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
