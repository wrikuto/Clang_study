/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:16:38 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/25 12:46:00 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;


long	ps_atol(const char *str);
int		chk_args(char **argv);

// list_utils
t_node	*free_list(t_node **head);
void	create_list(char **argv, t_node **head);

// swap
void	sa(t_node **head);
void	sb(t_node **head);
void	ss(t_node **list_a, t_node **list_b);

// rotate
void	ra(t_node **head);
void	rb(t_node **head);
void	rr(t_node **stack_a, t_node **stack_b);

// reverse
void	rra(t_node **head);
void	rrb(t_node **head);
void	rrr(t_node **stack_a, t_node **stack_b);

// push
void	push(t_node **src, t_node **dest);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

// sort
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	sort_three_elements(t_node **stack_a);
void	sort_five_elements(t_node **stack_a, t_node **stack_b, int count);
void	sort_insert(t_node **stack_a, t_node **stack_b);

int	count_list(t_node **stack_a);

#endif
