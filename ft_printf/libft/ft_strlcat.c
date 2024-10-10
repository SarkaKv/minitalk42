/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:50:50 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/31 11:10:00 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destl;
	size_t	siz;
	size_t	srcl;

	siz = 0;
	destl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (size <= destl)
		return (srcl + size);
	while ((destl + siz < size - 1) && src[siz] != '\0')
	{
		dst[destl + siz] = src[siz];
		siz++;
	}
	dst[destl + siz] = '\0';
	return (destl + srcl);
}
