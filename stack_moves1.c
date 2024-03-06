/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:25:54 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 17:50:25 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stacka, int i)
{
	t_stack	*tmp;

	if (!(*stacka))
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = (*stacka)->next;
	(*stacka)->next = tmp;
	if (i)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **stackb, int i)
{
	t_stack	*tmp;

	if (!(*stackb))
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = (*stackb)->next;
	(*stackb)->next = tmp;
	if (i)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **stacka, t_stack **stackb, int i)
{
	ft_sa(stacka, 0);
	ft_sb(stackb, 0);
	if (i)
		ft_putstr_fd("ss\n", 1);
}

void	ft_pa(t_stack **stacka, t_stack **stackb, int i)
{
	t_stack	*tmp;

	if (!(*stackb))
		return ;
	tmp = *stacka;
	*stacka = *stackb;
	*stackb = (*stackb)->next;
	(*stacka)->next = tmp;
	if (i)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **stacka, t_stack **stackb, int i)
{
	t_stack	*tmp;

	if (!(*stacka))
		return ;
	tmp = *stackb;
	*stackb = *stacka;
	*stacka = (*stackb)->next;
	(*stackb)->next = tmp;
	if (i)
		ft_putstr_fd("pb\n", 1);
}
