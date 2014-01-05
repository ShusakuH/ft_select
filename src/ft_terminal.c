/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:47:56 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:44:28 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include "ft_select.h"

int		ft_init_terminal_data(t_term *term)
{
	int		t_res;
	char	*term_type;

	term_type = getenv(FT_TERM);
	if (!term_type)
		ft_terminal_error(FT_TERMT_ERROR);
	t_res = tgetent(term->term_buffer, term_type);
	if (t_res < 0)
		ft_terminal_error(FT_TERMC_ERROR);
	else if (t_res == 0)
		ft_terminal_error(FT_TERMI_ERROR);
	term->arg_list = (t_list *)malloc(sizeof(t_list));
	ft_lst_init(term->arg_list);
	term->max_cols = tgetnum(TC_COLUM);
	term->max_rows = tgetnum(TC_LINES);
	term->cursor->x = 0;
	term->cursor->y = 0;
	return (EXIT_SUCCESS);
}

void	ft_terminal_raw_mode(t_term *term)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag &= ~(ICANON | ECHO);
	termios.c_cc[VMIN] = 1;
	termios.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, 0, &termios);
	term->termios = termios;
}

void	ft_terminal_parse_args(t_term *term, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i] != '\0')
	{
		ft_lst_add_element(term->arg_list, argv[i]);
		i++;
	}
	term->arg_count = i;
	term->cur_arg = term->arg_list->first;
}

void	ft_terminal_restore(void)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, 0, &termios);
	tputs(tgetstr(TC_CURSOR_DFL, NULL), 0, &ft_write_null);
}

void	ft_terminal_exit(int status)
{
	ft_terminal_restore();
	exit(status);
}

