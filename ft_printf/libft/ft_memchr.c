/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:48:53 by skvackov          #+#    #+#             */
/*   Updated: 2024/06/06 15:49:05 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	hehe;

	hehe = 0;
	while (hehe < n)
	{
		if (*(unsigned char *)(str + hehe) == (unsigned char)c)
			return ((unsigned char *)(str + hehe));
		hehe++;
	}
	if (c == '\0')
		return (NULL);
	return (NULL);
}
