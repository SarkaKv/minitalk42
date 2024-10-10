/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:54:48 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/31 11:09:47 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	notok;

	notok = 0;
	if (dest == src)
		return (dest);
	if (*(unsigned char *)(src) < *(unsigned char *)(dest)
		&& *(unsigned char *)src + n > *(unsigned char *)dest)
	{
		while (n > 0)
		{
			n--;
			*(unsigned char *)(dest + n) = *(const char *)(src + n);
		}
	}
	else
	{
		while (notok < n)
		{
			*(unsigned char *)(dest + notok) = *(const char *)(src + notok);
			notok++;
		}
	}
	return (dest);
}
