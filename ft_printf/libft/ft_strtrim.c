/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:08:37 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/30 12:37:14 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char const *src, size_t n)
{
	size_t	copy;

	copy = 0;
	while (copy < n && src[copy] != '\0')
	{
		dest[copy] = src[copy];
		copy++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	findstart;
	size_t	findend;
	size_t	newlenght;

	findstart = 0;
	findend = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[findstart]) != NULL && s1[findstart])
		findstart++;
	while (ft_strchr(set, s1[findend - 1]) != NULL && findend > findstart)
		findend--;
	newlenght = findend - findstart;
	new = (char *)malloc(sizeof(char) * newlenght + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s1 + findstart, newlenght);
	new[newlenght] = '\0';
	return (new);
}
