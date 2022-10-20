/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psplit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:31:48 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:55:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_psplit(const char *s, char c)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = ft_split(s, c);
	if (!splitted)
		return (splitted);
	while (splitted[i])
	{
		new_memory(splitted[i], VOID);
		i++;
	}
	new_memory(splitted, VOID);
	return (splitted);
}
