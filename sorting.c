/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:48:59 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 17:51:42 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_size_2(t_stack **stack)
{
	ft_sa(stack, 1);
}

void	sort_for_size_3(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (check_sorted(stack) == 0 && top > bot && top > mid)
		ft_ra(stack, 1);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (check_sorted(stack) == 0 && (bot < top || bot < mid))
		ft_rra(stack, 1);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (check_sorted(stack) == 0 && (bot > mid || bot > top))
		ft_sa(stack, 1);
}

int	get_position(t_stack **stack, int index)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp && temp->index != index)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_for_size_5(t_stack **a, t_stack **b)
{
	int	index;
	int	size;

	size = ft_stack_size(*a);
	index = 0;
	while (ft_stack_size(*a) > 3)
	{
		if (get_position(a, index) > size / 2)
		{
			while ((*a)->index != index)
				ft_rra(a, 1);
		}
		else
		{
			while ((*a)->index != index)
				ft_ra(a, 1);
		}
		index++;
		ft_pb(a, b, 1);
	}
	sort_for_size_3(a);
	while (*b)
		ft_pa(a, b, 1);
}
