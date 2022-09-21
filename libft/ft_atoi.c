/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:47:54 by kmatos-s          #+#    #+#             */
/*   Updated: 2022/09/20 01:29:17 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	charint(char c)
{
	return (c - '0');
}

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static int	check_signal(const char *nptr, int *counter)
{
	int	sign;
	int	sign_counter;

	sign = 1;
	sign_counter = 0;
	while ((*nptr == '+' || *nptr == '-'))
	{
		if (sign_counter >= 1)
			return (0);
		if (*nptr == '-')
			sign = sign * -1;
		nptr++;
		(*counter)++;
		sign_counter++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	sign = check_signal(nptr, &i);
	nptr += i;
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + charint(*nptr);
		nptr++;
	}
	return (res * sign);
}
