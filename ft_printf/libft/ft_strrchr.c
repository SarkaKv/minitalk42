/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:51:52 by skvackov          #+#    #+#             */
/*   Updated: 2024/06/06 15:37:12 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	ok;

	ok = ft_strlen(str);
	while (ok >= 0)
	{
		if (str[ok] == (char)c)
		{
			return ((char *)&str[ok]);
		}
		ok--;
	}
	return (NULL);
}
