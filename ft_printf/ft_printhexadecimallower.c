/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexadecimallower.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:54:35 by skvackov          #+#    #+#             */
/*   Updated: 2024/06/25 11:00:08 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlenght(unsigned int nuber)
{
	int	lenght;

	lenght = 0;
	if (nuber == 0)
		return (1);
	while (nuber != 0)
	{
		nuber = nuber / 16;
		lenght++;
	}
	return (lenght);
}

static void	ft_puthex(unsigned int nuber)
{
	if (nuber <= 9)
		ft_printchar(nuber + '0');
	else if (nuber >= 10 && nuber <= 15)
		ft_printchar(nuber - 10 + 'a');
	else
	{
		ft_puthex(nuber / 16);
		ft_puthex(nuber % 16);
	}
}

int	ft_printhexadecimallower(unsigned int number)
{
	int	lenght;

	lenght = ft_hexlenght(number);
	ft_puthex(number);
	return (lenght);
}
