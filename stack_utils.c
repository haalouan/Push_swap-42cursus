/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:57 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 17:49:49 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_add_new_node(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*temp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
	{
		exit(2);
		free_stack(*stack);
	}
	new->value = value;
	new->next = NULL;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}

int	ft_stack_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*save;

	temp = stack;
	while (temp)
	{
		save = temp->next;
		free(temp);
		temp = save;
	}
}
