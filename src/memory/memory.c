/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:06:38 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/24 01:48:25 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_free_memory(void **memory, int memory_nodes)
{
	int	i;

	i = 0;
	if (!memory)
		return ;
	while (i < memory_nodes && memory[i] != NULL)
	{
		free(memory[i]);
		i++;
	}
	free(memory);
}

void	*ft_push_memory(void **memory, void *payload, int memory_nodes)
{
	void	*temporary_pointer;
	int		new_space_to_allocate;
	int		old_space_to_allocated;

	temporary_pointer = memory;
	new_space_to_allocate = memory_nodes * sizeof(void *);
	old_space_to_allocated = (memory_nodes - 1) * sizeof(void *);
	memory = ft_salloc(new_space_to_allocate);
	if (temporary_pointer)
	{
		ft_memcpy(memory, temporary_pointer, old_space_to_allocated);
		free(temporary_pointer);
	}
	memory[memory_nodes - 1] = payload;
	return (memory);
}

void	memory(enum e_memory_actions action, void *payload)
{
	static void	**memory;
	static int	memory_nodes;

	if (action == FREE)
		return (ft_free_memory(memory, memory_nodes));
	if (!payload)
		return ;
	if (action == PUSH)
	{
		memory_nodes++;
		memory = ft_push_memory(memory, payload, memory_nodes);
	}
}
