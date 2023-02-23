/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:59 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/23 14:50:03 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"

typedef struct s_item
{
	int value;
	struct s_item *next;
}	t_item;

typedef struct s_stack
{
	int size;
	t_item *head;
}				t_stack;

void	init_with_split(t_stack *stack, char *str);
void	init_with_args(t_stack *stack, char **strs, int size);
void	push(t_stack *stack, t_item *item);
void	swap(int *a, int *b);
void	init_stack(int *values, t_stack *stack, int size);
t_item	*create_new_item(int val);
void	free_strs(char **strs);
int	ft_atol(int *value, const char *str);

#endif
