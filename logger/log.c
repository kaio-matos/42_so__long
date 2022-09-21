/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:58:36 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/22 01:44:48 by kmatos-s         ###   ########.fr       */
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
	ft_printf("[so_long] %s", error_message);
	ft_printf(SHELL_RC);
	exit(1);
}

void	on_success(char	*success_message)
{
	ft_printf(SHELL_G);
	ft_printf("[so_long] %s", success_message);
	ft_printf(SHELL_RC);
}
