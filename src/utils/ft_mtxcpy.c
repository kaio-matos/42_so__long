/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:48:52 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/08 02:56:26 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_mtxcpy(char **map)
{
	char	**new;
	int		i;

	i = 0;
	new = ft_palloc((ft_strlen(map[0]) + 1) * (char *));
	while (map[i])
	{
		new = map[i];
		i++;
	}
	map[i] = NULL;
	return (new);
}
