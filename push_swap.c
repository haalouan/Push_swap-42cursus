/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:27 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 18:34:31 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	full_stack_a(t_stack **a, int arc, char **arv, int i)
{
	int	j;
	int	temp;
	int	val;

	temp = 1;
	j = 0;
	while (i < arc)
	{
		val = ft_atoi_with_cheak(arv[i], &j, *a);
		if (temp == 1)
			(*a)->value = val;
		else
			ft_add_new_node(a, val);
		temp = 0;
		check_nb_exist(a, val);
		if (arv[i][j] == '\0')
		{
			j = 0;
			i++;
		}
	}
}

int	main(int arc, char **arv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (arc > 1)
	{
		a = malloc(sizeof(t_stack));
		if (!a)
			exit(2);
		full_stack_a(&a, arc, arv, 1);
		indexing_stack(&a);
		if (ft_stack_size(a) != 1)
		{
			if (check_sorted(&a) == 0 && ft_stack_size(a) == 2)
				sort_for_size_2(&a);
			else if (check_sorted(&a) == 0 && ft_stack_size(a) == 3)
				sort_for_size_3(&a);
			else if (check_sorted(&a) == 0 && ft_stack_size(a) == 5)
				sort_for_size_5(&a, &b);
			else if (check_sorted(&a) == 0)
				pivote_sorting(&a, &b);
		}
		free_stack(a);
	}
}
