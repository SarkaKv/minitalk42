/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:48:08 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/29 10:33:25 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	uh;
	char			*oki;

	uh = 0;
	if (!s || !f)
		return (NULL);
	oki = (char *)malloc(ft_strlen(s) + 1);
	if (!oki)
		return (NULL);
	while (s[uh] != '\0')
	{
		oki[uh] = (*f)(uh, s[uh]);
		uh++;
	}
	oki[uh] = '\0';
	return (oki);
}
