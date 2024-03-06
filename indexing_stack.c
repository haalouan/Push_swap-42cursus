/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:59:13 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 17:33:37 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_stack(t_stack **a)
{
	t_stack	*save;
	t_stack	*temp;

	temp = *a;
	while (temp != NULL)
	{
		save = *a;
		while (save != NULL)
		{
			if (temp->value > save->value)
				temp->index++;
			save = save->next;
		}
		temp = temp->next;
	}
}
