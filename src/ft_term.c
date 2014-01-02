/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:47:56 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 17:09:53 by greyrol          ###   ########.fr       */
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
	int		t_result;
	char	*term_type;

	term_type = getenv("TERM");
	if (!term_type)
		ft_terminal_error("ft_select: error: You must specified\
							terminal type\n");
	t_result = tgetent(term->term_buffer, term_type);
	if (t_result < 0)
		ft_terminal_error("ft_select: error: Cannot access the termcap\
							database\n");
	else if (t_result == 0)
		ft_terminal_error("ft_select: error: Terminal type is not defined\n");
	term->arg_list = NULL;
	term->max_cols = tgetnum("col");
	term->max_rows = tgetnum("li");
	return (EXIT_SUCCESS);
}

void	ft_terminal_raw_mode(void)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag &= ~(ICANON | ECHO);
	termios.c_cc[VMIN] = 1;
	termios.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, 0, &termios);
}

void	ft_terminal_parse_args(t_term *term, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i] != '\0')
	{
		ft_lst_add_element(&term->arg_list, argv[i]);
		i++;
	}
	term->arg_count = i;
}

void	ft_terminal_restore(void)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, 0, &termios);
}

void	ft_terminal_exit(int status)
{
	ft_terminal_restore();
	exit(status);
}


