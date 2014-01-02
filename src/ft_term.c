/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:47:56 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 14:38:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

int		ft_init_terminal_data(char **term_buffer)
{
	int		t_result;
	char	*term_type;

	term_type = getenv("TERM");
	if (!term_type)
		ft_error("ft_select: error: You must specified terminal type\n");
	t_result = tgetent(*term_buffer, term_type);
	if (t_result < 0)
		ft_error("ft_select: error: Cannot access the termcap database\n");
	else if (t_result == 0)
		ft_error("ft_select: error: Terminal type is not defined\n");
	return (EXIT_SUCCESS);
}

char	*ft_ask_terminal_string(char *name, char **term_buffer)
{
	char	*return_str;
	
	return_str = tgetstr(name, term_buffer);
	return (return_str);	
}

int 	ft_ask_terminal_numeric(char *name)
{
	int	id;

	id = tgetnum(name);
	return (id);
}

int		ft_ask_terminal_flag(char *name)
{
	int	id;

	id = tgetflag(name);
	return (id);
}
