/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:34:00 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/20 18:53:41 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (chk_args(&argv[1]) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	write(1, "SUCCESS\n", 9);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}