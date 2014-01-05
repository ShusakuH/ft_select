/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:42:28 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:49:39 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <libft_printf.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>

static	t_key keys[] =
{
	{FT_KEY_LEFT, &ft_key_left},
	{FT_KEY_UP, &ft_key_up},
	{FT_KEY_RIGHT, &ft_key_right},
	{FT_KEY_DOWN, &ft_key_down},
	{FT_KEY_SPACE, &ft_key_space},
	{FT_KEY_RETURN, &ft_key_return},
	{FT_KEY_DELETE, &ft_key_delete},
	{FT_KEY_BACKSPACE, &ft_key_delete},
	{FT_KEY_ESCAPE, &ft_key_quit},
	{FT_KEY_TAB, &ft_key_right},
	{0, NULL}
};

void	ft_check_keys(t_term *term, int key)
{
	int	i;

	i = 0;
	while (keys[i].key)
	{
		if (key == keys[i].key && term->arg_count > 0)
		{
			(*keys[i].fkey)(term);
			return ;
		}
		i++;
	}
	ft_key_default(term);
}

void	ft_key_delete(t_term *term)
{
	t_arg	*tmp_arg;

	tmp_arg = term->cur_arg;
	term->cur_arg = NULL;
	if (tmp_arg->prev)
		tmp_arg->prev->next = tmp_arg->next;
	else
		term->arg_list->first = tmp_arg->next;
	if (tmp_arg->next)
		tmp_arg->next->prev = tmp_arg->prev;
	tputs(tgetstr(TC_CLEAR, NULL), 1, &ft_write_null);
	if (tmp_arg->next)
		term->cur_arg = tmp_arg->next;
	else if (tmp_arg->prev)
		term->cur_arg = tmp_arg->prev;
	else
		term->cur_arg = NULL;
	term->arg_count--;
	if (term->arg_count == 1)
		ft_terminal_exit(EXIT_SUCCESS);
	free(tmp_arg);
	ft_move_to(term, 0, 0);
	ft_write(term);
	ft_move_current(term);
}

void	ft_key_return(t_term *term)
{
	t_arg	*arg;
	char	separator;
	t_bool	first;

	first = TRUE;
	separator = ' ';
	ft_write_clear();
	arg = term->arg_list->first;
	while (arg)
	{
		if (arg->selected)
		{
			if (!first)
				write(STDOUT_FILENO, &separator, 1);
			first = FALSE;
			write(STDOUT_FILENO, arg->content, arg->content_size);
		}
		arg = arg->next;
	}
	ft_terminal_exit(EXIT_SUCCESS);
}

void	ft_key_quit(t_term *term)
{
	(void)term;
	ft_write_clear();
	ft_terminal_exit(EXIT_SUCCESS);
}

void	ft_key_default(t_term *term)
{
	(void)term;
	return ;
}

