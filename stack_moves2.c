/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:39 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 17:41:29 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stacka, int i)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!(*stacka))
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	curr = *stacka;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = tmp;
	tmp->next = NULL;
	if (i)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stackb, int i)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!(*stackb))
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	curr = *stackb;
	if (curr)
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = tmp;
	}
	tmp->next = NULL;
	if (i)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **stacka, t_stack **stackb, int i)
{
	ft_ra(stacka, 0);
	ft_rb(stackb, 0);
	if (i)
		ft_putstr_fd("rr\n", 1);
}
