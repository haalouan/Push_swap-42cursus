/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:18:19 by haalouan          #+#    #+#             */
/*   Updated: 2024/01/05 17:30:59 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(ssize_t nb, char *str, int i, t_stack *stack)
{
	if (str[i] == ' ' && str[i + 1] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack);
		exit(2);
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack);
		exit(2);
	}
	if (nb > INT_MAX || nb < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack);
		exit(2);
	}
}

void	check_nb_exist(t_stack **stack, int val)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->value == val)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(*stack);
			exit(2);
		}
		temp = temp->next;
	}
}

int	check_sorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_atoi_with_cheak(char *str, int *i, t_stack *stack)
{
	ssize_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while (str[*i] == 32)
		(*i)++;
	if (str[*i] == '\0')
		check_input(result, str, *i, stack);
	if ((str[*i] == '+' || str[*i] == '-') && ft_isdigit(str[*i + 1]))
	{
		if (str[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	while (str[*i] != ' ' && str[*i] != '\0')
	{
		result = result * 10 + (str[*i] - '0');
		check_input(result * sign, str, *i, stack);
		(*i)++;
	}
	while (str[*i] == 32)
		(*i)++;
	return (result * sign);
}
