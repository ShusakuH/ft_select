/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:28:01 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 19:15:51 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>
#include <libft_printf.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include "ft_select.h"

void	ft_write(t_term *term)
{
	int		display_area;
	t_arg	*elem;

	ft_write_clear();
	ft_write_prepare(term);
	display_area = term->arg_count - (term->col * term->max_rows);
	if (display_area > 0)
		term->col++;
	if ((term->col * term->cell_len - 1) <= term->max_cols)
	{
		ft_write_args(term);
		if (!term->cur_arg)
			term->cur_arg = term->arg_list->first;
		elem = term->cur_arg;
		if (elem)
			ft_move_to(term, elem->position->x, elem->position->y);
		term->status = TRUE;
	}
	else
	{
		ft_error(FT_WRITE_ERROR);
		ft_move_to(term, ft_strlen(FT_WRITE_ERROR), 0);
		term->status = FALSE;
	}
}

void	ft_write_args(t_term *term)
{
	t_arg	*elem;
	int		cur_row;
	int		cur_col;

	cur_col = 0;
	elem = term->arg_list->first;
	while (cur_col <= term->col)
	{
		cur_row = 0;
		while (cur_row < term->row)
		{
			if (!elem)
				return ;
			elem->position->x = cur_col * term->cell_len;
			elem->position->y = cur_row;
			ft_write_arg(term, elem);
			cur_row++;
			elem = elem->next;
		}
		cur_col++;
	}
}

void	ft_write_arg(t_term *term, t_arg *arg)
{
	ft_move_to(term, arg->position->x, arg->position->y);
	tputs(tgetstr(TC_CURSOR_INVI, NULL), 0, &ft_write_null);
	tputs(ft_s_underline(term->cur_arg->content == arg->content), 0,
							&ft_write_null);
	tputs(ft_s_inverse(arg->selected), 0, &ft_write_null);
	ft_fprintf(0, "%s", arg->content);
	tputs(ft_e_inverse(arg->selected), 0, &ft_write_null);
	tputs(ft_e_underline(term->cur_arg->content == arg->content), 0,
							&ft_write_null);
}

void	ft_write_prepare(t_term *term)
{
	t_arg			*elem;
	int				max_length;
	struct winsize	size;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &size);
	term->max_cols = size.ws_col;
	term->max_rows = size.ws_row;
	max_length = 0;
	elem = term->arg_list->first;
	while (elem)
	{
		if (elem->content_size > max_length)
			max_length = elem->content_size;
		elem = elem->next;
	}
	term->cell_len = max_length + 1;
	term->col = term->max_cols / term->cell_len;
	if (term->col > 1)
		term->row = term->max_rows;
	else
		term->row = term->arg_count;
}

int		ft_write_null(int nb)
{
	return (write(STDERR_FILENO, &nb, 1));
}

