/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:47:59 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/22 12:00:15 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	oki;
	int		ble;

	oki = 0;
	ble = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (big[oki] != '\0' && oki < len)
	{
		if (big[oki] == little[ble])
		{
			while (little[ble] != '\0' && big[oki + ble] == little[ble] && oki
				+ ble < len)
			{
				ble++;
			}
			if (little[ble] == '\0')
				return ((char *)&big[oki]);
		}
		ble = 0;
		oki++;
	}
	return (NULL);
}
