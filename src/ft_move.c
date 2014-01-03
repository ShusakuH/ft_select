/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:41:25 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/03 20:37:24 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <curses.h>
#include <term.h>

void	ft_move(t_term *term, int x, int y)
{
	ft_move_to(term, x + term->cursor->x, y + term->cursor->y);
}

void	ft_move_to(t_term *term, int x, int y)
{
	tputs(tgoto(tgetstr(TC_CURSOR_MOVE, NULL), x, y), 0, &ft_write_null);
	term->cursor->x = 0;
	term->cursor->y = 0;
}

void	ft_move_current(t_term *term)
{
	t_arg	*elem;

	elem = (t_arg *)malloc(sizeof(t_arg));
	if (!term->current_arg)
	{
		if (!elem)
			return ;
		term->current_arg = term->arg_list->first;
	}
	elem = term->current_arg;
	ft_move_to(term, elem->position->x, elem->position->y);
}
