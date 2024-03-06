/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:55 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 17:50:41 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stacka, int i)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!(*stacka))
		return ;
	curr = *stacka;
	while (curr->next->next != NULL)
		curr = curr->next;
	tmp = curr->next;
	curr->next = NULL;
	tmp->next = *stacka;
	*stacka = tmp;
	if (i)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **stackb, int i)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!(*stackb))
		return ;
	curr = *stackb;
	while (curr->next->next != NULL)
		curr = curr->next;
	tmp = curr->next;
	curr->next = NULL;
	tmp->next = *stackb;
	*stackb = tmp;
	if (i)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **stacka, t_stack **stackb, int i)
{
	ft_rra(stacka, 0);
	ft_rrb(stackb, 0);
	if (i)
		ft_putstr_fd("rrr\n", 1);
}
