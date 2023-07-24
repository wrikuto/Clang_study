/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:06:44 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/24 19:34:08 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

long	ps_atol(const char *str)
{
	int		i;
	long	sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1 + ((str[i] == '-') * -2);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (((num > LONG_MAX / 10) && ft_isdigit(str[i]) == 1) || \
			((num == LONG_MAX / 10) && str[i] > (LONG_MAX % 10) + '0'))
			return (INT_MAX + 3L);
	}
	return (num * sign);
}

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

static int	chk_valid(char **argv)
{
	size_t	i;
	long	long_num;

	i = 0;
	long_num = 0;
	while (argv[i])
	{
		if (!(is_num(argv[i])))
			return (0);
		long_num = ps_atol(argv[i]);
		if (long_num < INT_MIN || INT_MAX < long_num)
			return (0);
		i++;
	}
	return (1);
}

static int	chk_dup(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ps_atol(argv[i]) == ps_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	chk_args(char **argv)
{
	if (chk_valid(argv) == 0)
		return (0);
	if (chk_dup(argv) == 0)
		return (0);
	return (1);
}