/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:24:19 by skvackov          #+#    #+#             */
/*   Updated: 2024/06/05 14:38:53 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlenghtofn(int ok)
{
	int	lenghtofthenb;

	lenghtofthenb = 0;
	if (ok <= 0)
	{
		lenghtofthenb++;
	}
	while (ok != 0)
	{
		ok = ok / 10;
		lenghtofthenb++;
	}
	return (lenghtofthenb);
}

char	*ft_itoa(int n)
{
	char			*thenumber;
	size_t			lenghtofthenb;
	unsigned int	tempn;

	lenghtofthenb = getlenghtofn(n);
	tempn = (unsigned int)n;
	thenumber = (char *)malloc(sizeof(char) * (lenghtofthenb + 1));
	if (!thenumber)
		return (NULL);
	thenumber[lenghtofthenb] = '\0';
	if (n < 0)
	{
		thenumber[0] = '-';
		tempn = -tempn;
	}
	if (n == 0)
		thenumber[0] = '0';
	while (tempn > 0)
	{
		thenumber[--lenghtofthenb] = (tempn % 10) + '0';
		tempn = tempn / 10;
	}
	return (thenumber);
}
