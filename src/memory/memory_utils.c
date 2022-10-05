/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 02:51:25 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/05 05:20:41 by kmatos-s         ###   ########.fr       */
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
	new_memory(mem, VOID);
	return (mem);
}

void	new_memory(void *content, enum e_memory_types type)
{
	t_memory_node	node;

	node.content = content;
	node.type = type;
	memory(PUSH, node);
}

void	free_memory(void)
{
	t_memory_node	node;

	node.content = NULL;
	node.type = VOID;
	memory(FREE, node);
}