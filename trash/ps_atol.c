/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:11:16 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/20 18:48:55 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ps_atol(const char *str)
{
	int		i;
	long	sign;
	long	num;

	sign = 1 + ((str[i] == '-') * -2);
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (((num > LONG_MAX / 10) && ft_isdigit(str[i]) == 1) || \
			((num == LONG_MAX / 10) && str[i] > (LONG_MAX % 10) + '0'))
			return (INT_MAX + 3);
	}
	return (num * sign);
}
