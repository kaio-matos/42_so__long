/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:58:36 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/10/11 02:19:52 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	logg(char	*message)
{
	ft_printf(SHELL_RC);
	ft_printf("[so_long] %s", message);
	ft_printf(SHELL_RC);
}

void	on_error(char	*error_message)
{
	ft_printf(SHELL_R);
	ft_printf("[so_long] Error:\n%s", error_message);
	ft_printf(SHELL_RC);
	ft_exit(1);
}

void	on_success(char	*success_message)
{
	ft_printf(SHELL_G);
	ft_printf("[so_long] %s", success_message);
	ft_printf(SHELL_RC);
}

void	ft_printf_mtx(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		ft_printf("%s\n", m[i]);
		i++;
	}
}
