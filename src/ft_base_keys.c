/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:37:06 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/03 21:11:46 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_key_down(t_term *term)
{
	t_arg	*new;
	t_arg	*old;
	int		i;

	old = term->cur_arg;
	if (old)
	{
		i = 0;
		while (old->next && i++ < term->col)
			old = old->next;
	}
	term->cur_arg = term->arg_list->first;
	new = term->cur_arg;
	ft_write_arg(term, old);
	ft_write_arg(term, new);
	ft_move_to(term, new->position->x, new->position->y);
}

void	ft_key_up(t_term *term)
{
	t_arg	*new;
	t_arg	*old;
	int		i;

	old = term->cur_arg;
	if (old)
	{
		i = 0;
		while (old->prev && i++ < term->col)
			old = old->prev;
	}
	term->cur_arg = term->arg_list->first;
	new = term->cur_arg;
	ft_write_arg(term, old);
	ft_write_arg(term, new);
	ft_move_to(term, new->position->x, new->position->y);
}

void	ft_key_left(t_term *term)
{
	t_arg	*new;
	t_arg	*old;

	old = term->cur_arg;
	if (term->cur_arg && term->cur_arg->prev)
		term->cur_arg = term->cur_arg->prev;
	else
	{
		term->cur_arg = term->arg_list->first;
		while (term->cur_arg->next)
			term->cur_arg = term->cur_arg->next;
	}
	new = term->cur_arg;
	ft_write_arg(term, old);
	ft_write_arg(term, new);
	ft_move_to(term, new->position->x, new->position->y);
}

void	ft_key_right(t_term *term)
{
	t_arg	*new;
	t_arg	*old;

	old = term->cur_arg;
	if (term->cur_arg && term->cur_arg->next)
		term->cur_arg = term->cur_arg->next;
	else
		term->cur_arg = term->arg_list->first;
	new = term->cur_arg;
	ft_write_arg(term, old);
	ft_write_arg(term, new);
	ft_move_to(term, new->position->x, new->position->y);
}

void	ft_key_space(t_term *term)
{
	t_arg	*arg;

	arg = term->cur_arg;
	arg->selected = !arg->selected;
	if (arg->selected)
		ft_key_right(term);
	else
	{
		ft_write_arg(term, arg);
		ft_move_to(term, arg->position->x, arg->position->y);
	}
}
