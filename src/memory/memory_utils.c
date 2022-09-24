/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 02:51:25 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/24 01:31:38 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*ft_salloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem && size > 0)
		on_error("MEMORY ALLOCATION ERROR");
	return (mem);
}

void	*ft_palloc(size_t size)
{
	void	*mem;

	mem = ft_salloc(size);
	memory(PUSH, mem);
	return (mem);
}
