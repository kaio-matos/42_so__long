/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:06:38 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/25 04:25:46 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_memory(t_memory_node *memory, int memory_nodes)
{
	int	i;

	i = 0;
	if (!memory)
		return ;
	while (i < memory_nodes && memory[i].content != NULL)
	{
		if (memory[i].type == IMAGE)
			mlx_destroy_image(w()->init, memory[i].content);
		if (memory[i].type == VOID)
			free(memory[i].content);
		i++;
	}
	free(memory);
}

t_memory_node	*ft_push_memory(t_memory_node *memory,
								t_memory_node payload, int memory_nodes)
{
	t_memory_node	*temporary;
	int				new_space_to_allocate;
	int				old_space_to_allocate;

	temporary = memory;
	old_space_to_allocate = memory_nodes * sizeof(t_memory_node);
	new_space_to_allocate = (memory_nodes + 1) * sizeof(t_memory_node);
	memory = ft_salloc(new_space_to_allocate);
	if (temporary)
	{
		ft_memcpy(memory, temporary, old_space_to_allocate);
		free(temporary);
	}
	memory[memory_nodes] = payload;
	return (memory);
}

void	memory(enum e_memory_actions action, t_memory_node payload)
{
	static t_memory_node	*memory;
	static int				memory_nodes;

	if (action == FREE)
		return (ft_free_memory(memory, memory_nodes));
	if (!payload.content)
		return ;
	if (action == PUSH)
	{
		memory = ft_push_memory(memory, payload, memory_nodes);
		memory_nodes++;
	}
}
