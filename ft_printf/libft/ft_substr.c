/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:33:20 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/30 10:18:44 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	starti;
	char	*meow;

	starti = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	meow = (char *)malloc(sizeof(char) * len + 1);
	if (!meow)
		return (NULL);
	while (s[start + starti] && starti < len)
	{
		meow[starti] = s[start + starti];
		starti++;
	}
	meow[starti] = '\0';
	return (meow);
}
