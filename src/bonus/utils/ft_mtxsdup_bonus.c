/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxsdup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:48:52 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/21 01:55:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_mtxsdup(char **mtx, size_t rows)
{
	char	**mtx_cpy;
	size_t	i;

	i = 0;
	if (!rows)
		return (NULL);
	mtx_cpy = ft_palloc((rows + 1) * sizeof(char *));
	while (i < rows && mtx[i])
	{
		mtx_cpy[i] = ft_strdup(mtx[i]);
		new_memory(mtx_cpy[i], VOID);
		i++;
	}
	mtx_cpy[i] = NULL;
	return (mtx_cpy);
}
