/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:53:33 by skvackov          #+#    #+#             */
/*   Updated: 2024/06/27 10:47:30 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper2(unsigned long ptr3)
{
	int	lenght;

	lenght = 0;
	if (ptr3 == 0)
		return (1);
	while (ptr3 != 0)
	{
		ptr3 = ptr3 / 16;
		lenght++;
	}
	return (lenght);
}

static void	helper3(unsigned long ptr4)
{
	if (ptr4 <= 9)
		ft_printchar(ptr4 + '0');
	else if (ptr4 >= 10 && ptr4 <= 15)
		ft_printchar(ptr4 - 10 + 'a');
	else
	{
		helper3(ptr4 / 16);
		helper3(ptr4 % 16);
	}
}

static int	ft_pointerhelper(unsigned long ptr2)
{
	int	lenght;

	lenght = helper2(ptr2);
	helper3(ptr2);
	return (lenght);
}

int	ft_printpointer(void *ptr)
{
	unsigned long	adress;
	int				lenght;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	adress = (unsigned long)ptr;
	lenght = 2;
	ft_printchar('0');
	ft_printchar('x');
	lenght += ft_pointerhelper(adress);
	return (lenght);
}
