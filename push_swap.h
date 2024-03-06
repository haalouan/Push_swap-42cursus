/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:58:31 by haalouan          #+#    #+#             */
/*   Updated: 2024/03/06 15:25:56 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				index;
	int				value;
}	t_stack;

// cheack_erros
int		check_sorted(t_stack **a); // 0 not sorted | 1 sorted
void	check_nb_exist(t_stack **stack, int value);
void	check_input(ssize_t nb, char *str, int i, t_stack *stack);
int		ft_atoi_with_cheak(char *str, int *i, t_stack *lst);

// indexing_stack
void	indexing_stack(t_stack **a);

// stack_utils
t_stack	*ft_add_new_node(t_stack **stack, int value);
int		ft_stack_size(t_stack *lst);
void	free_stack(t_stack *stack);

// helper_functions1
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

// helper_functions2
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// stack_moves 1
void	ft_sa(t_stack **stacka, int i);
void	ft_sb(t_stack **stackb, int i);
void	ft_ss(t_stack **stacka, t_stack **stackb, int i);
void	ft_pa(t_stack **stacka, t_stack **stackb, int i);
void	ft_pb(t_stack **stacka, t_stack **stackb, int i);

// stack_moves 2
void	ft_ra(t_stack **stacka, int i);
void	ft_rb(t_stack **stackb, int i);
void	ft_rr(t_stack **stacka, t_stack **b, int i);

// stack_moves 3
void	ft_rra(t_stack **stacka, int i);
void	ft_rrb(t_stack **stackb, int i);
void	ft_rrr(t_stack **stacka, t_stack **b, int i);

// sorting
void	sort_for_size_2(t_stack **stack);
void	sort_for_size_3(t_stack **stack);
int		get_position(t_stack **stack, int index);
void	sort_for_size_5(t_stack **a, t_stack **b);

// pivote_algo
void	pivote_sorting(t_stack **a, t_stack **b);
void	pivote_sorting_part2(t_stack **a, t_stack **b);
void	get_bottom(t_stack **a, t_stack **bot);
void	ft_pa_rrb(t_stack **a, t_stack **b, int value, t_stack **bot_a);

#endif