/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:56:46 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/20 02:41:36 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strljoin(char *s1, char const *s2, int bytes)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * bytes + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1 && (bytes - i))
	{
		new_str[i] = *s1;
		i++;
		s1++;
	}
	free(s1 - i);
	while (s2 != NULL && *s2 && (bytes - i))
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}
