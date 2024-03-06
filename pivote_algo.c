/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivote_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:12 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 19:23:45 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivote_sorting(t_stack **a, t_stack **b)
{
	int	p1;
	int	p2;
	int	lp1;

	p1 = ft_stack_size(*a) / 3;
	p2 = ft_stack_size(*a) / 6;
	lp1 = -1;
	while (ft_stack_size(*a) > 3)
	{
		if ((*a)->index < p1)
			ft_pb(a, b, 1);
		else
			ft_ra(a, 1);
		if (ft_stack_size(*b) > 1 && (*b)->index >= p2 && (*b)->index >= lp1)
			ft_rb(b, 1);
		if (ft_stack_size(*b) == p1)
		{
			lp1 = p1;
			p1 += ft_stack_size(*a) / 3;
			p2 = lp1 + ft_stack_size(*a) / 6;
		}
	}
	sort_for_size_3(a);
	pivote_sorting_part2(a, b);
}

void	get_bottom(t_stack **a, t_stack **bot)
{
	*bot = *a;
	while ((*bot)->next)
		*bot = (*bot)->next;
}

void	ft_pa_rrb(t_stack **a, t_stack **b, int value, t_stack **bot_a)
{
	if (get_position(b, (*a)->index - 1) > ft_stack_size(*b) / 2)
	{
		if (((*bot_a)->index < (*b)->index || (*bot_a)->index == value))
		{
			ft_pa(a, b, 1);
			ft_ra(a, 1);
			get_bottom(a, bot_a);
		}
		else if (b)
			ft_rrb(b, 1);
	}
	else
	{
		if ((*bot_a)->index < (*b)->index || (*bot_a)->index == value)
		{
			ft_pa(a, b, 1);
			ft_ra(a, 1);
			get_bottom(a, bot_a);
		}
		else if (b)
			ft_rb(b, 1);
	}
}

void	pivote_sorting_part2(t_stack **a, t_stack **b)
{
	t_stack	*bot_a;
	int		value;

	get_bottom(a, &bot_a);
	value = bot_a->index;
	while (b != NULL)
	{
		while (((*b)->index != (*a)->index - 1) && (*b))
			ft_pa_rrb(a, b, value, &bot_a);
		while (*b && (*b)->index == (*a)->index - 1)
			ft_pa(a, b, 1);
		if ((*a)->index - 1 == bot_a->index)
		{
			while (bot_a->index == (*a)->index - 1)
			{
				ft_rra(a, 1);
				get_bottom(a, &bot_a);
			}
		}
		if (check_sorted(a) == 1 && *b == NULL)
			break ;
	}
}
