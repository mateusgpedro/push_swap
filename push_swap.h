/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:59 by maguimar          #+#    #+#             */
/*   Updated: 2023/02/06 14:41:54 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack_a
{
	int *stackA;
	int sizeA;
	struct s_list *next;
}				t_stack_a;

typedef struct s_stack_b
{
	int *stackB;
	int sizeB;
	struct s_list *next;
}				t_stack_b;

#endif
