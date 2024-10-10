/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:48:33 by skvackov          #+#    #+#             */
/*   Updated: 2024/05/31 10:08:00 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	meh;

	meh = 0;
	if (n == 0)
		return (0);
	while (meh < n - 1 && str1[meh] != '\0' && str2[meh] != '\0'
		&& str1[meh] == str2[meh])
	{
		meh++;
	}
	return ((unsigned char)str1[meh] - (unsigned char)str2[meh]);
}
