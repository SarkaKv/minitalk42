/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:43:29 by skvackov          #+#    #+#             */
/*   Updated: 2024/06/05 16:59:55 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char splitter)
{
	int	len;
	int	oki;
	int	arewein;

	len = 0;
	oki = 0;
	arewein = 0;
	while (s[oki] != '\0')
	{
		if (s[oki] == splitter)
		{
			arewein = 0;
		}
		if (s[oki] != splitter && arewein == 0)
		{
			len++;
			arewein = 1;
		}
		oki++;
	}
	return (len);
}

static void	do_magic(char const *s, char splitter, int *len, int *oki)
{
	while (s[*oki] == splitter && s[*oki] != '\0')
		(*oki)++;
	while (s[*oki] != splitter && s[*oki] != '\0')
	{
		(*len)++;
		(*oki)++;
	}
}

char	**ft_split(char const *s, char splitter)
{
	int		whereinar;
	char	**helou;
	int		oki;
	int		len;
	int		words;

	whereinar = 0;
	oki = 0;
	words = word_count(s, splitter);
	helou = (char **)malloc(sizeof(char *) * (words + 1));
	if (!helou)
		return (NULL);
	while (whereinar < words)
	{
		len = 0;
		do_magic(s, splitter, &len, &oki);
		helou[whereinar] = (char *)malloc(sizeof(char) * (len + 1));
		if (!helou[whereinar])
			return (NULL);
		ft_strlcpy(helou[whereinar], s + oki - len, len + 1);
		whereinar++;
	}
	helou[whereinar] = NULL;
	return (helou);
}
