/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:52:59 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/30 10:24:14 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		oki;
	char	*ptr;
	int		start;

	start = 0;
	oki = ft_strlen(s);
	ptr = (char *)malloc((oki + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (start < oki)
	{
		ptr[start] = s[start];
		start++;
	}
	ptr[start] = '\0';
	return (ptr);
}
