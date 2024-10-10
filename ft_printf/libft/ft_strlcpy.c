/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:52:07 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/31 09:40:34 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	ok;

	ok = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (ok < size - 1 && src[ok] != '\0')
	{
		dst[ok] = src[ok];
		ok++;
	}
	dst[ok] = '\0';
	return (ft_strlen(src));
}
