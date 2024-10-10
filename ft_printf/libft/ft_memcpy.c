/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:35:33 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/31 09:41:18 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	ok;

	ok = 0;
	if (!dest && !src)
		return (0);
	while (ok < n)
	{
		*(unsigned char *)(dest + ok) = *(unsigned char *)(src + ok);
		ok++;
	}
	return (dest);
}
