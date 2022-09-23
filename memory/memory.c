/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:06:38 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/23 02:51:37 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_free_memory(void **memory, int memory_nodes)
{
	int	i;

	i = 0;
	if (!memory)
		return ;
	while (memory[i] && i < memory_nodes)
	{
		free(memory[i]);
		i++;
	}
	free(memory);
}

void	*ft_push_memory(void **memory, void *payload, int memory_nodes)
{
	void	*temporary_pointer;

	temporary_pointer = memory;
	memory = ft_salloc(memory_nodes * sizeof(payload));
	if (temporary_pointer)
	{
		ft_memcpy(memory, temporary_pointer, memory_nodes * sizeof(payload));
		free(temporary_pointer);
	}
	memory[memory_nodes - 1] = payload;
	return (memory);
}

void memory(enum memory_actions action, void *payload)
{
	static void **memory;
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