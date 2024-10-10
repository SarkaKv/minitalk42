/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:27 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/27 12:12:28 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	start1;
	size_t	start2;

	start1 = 0;
	start2 = 0;
	news = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (start1 < ft_strlen(s1))
	{
		news[start1] = s1[start1];
		start1++;
	}
	while (start1 < ((ft_strlen(s1) + ft_strlen(s2))))
	{
		news[start1] = s2[start2];
		start1++;
		start2++;
	}
	news[start1] = '\0';
	return (news);
}
