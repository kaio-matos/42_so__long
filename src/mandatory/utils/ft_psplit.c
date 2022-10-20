/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:31:48 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/18 03:00:43 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
