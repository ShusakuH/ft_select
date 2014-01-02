/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ask_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 15:12:04 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 16:32:45 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>

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

