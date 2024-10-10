/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:00:49 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/27 10:07:31 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int	ft_atoi(const char *str)
{
	int	hehe;
	int	minus;
	int	nb;

	hehe = 0;
	minus = 1;
	nb = 0;
	while ((str[hehe] >= 9 && str[hehe] <= 13) || str[hehe] == 32)
		hehe++;
	if (str[hehe] == '-')
	{
		minus = minus * -1;
		hehe++;
	}
	else if (str[hehe] == '+')
		hehe++;
	while (str[hehe] >= '0' && str[hehe] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[hehe] - '0');
		hehe++;
	}
	return (nb * minus);
}
// int main(void)
// {
// 	printf("%d", ft_atoi("-2147483 648"));
// }
