/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:28:01 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 20:42:12 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include "ft_select.h"

int	ft_write_null(int nb)
{
	return (ft_putnbr_fd(nb, STDERR_FILENO));
}

void	ft_write_clear(void)
{
	tputs(tgetstr(TC_CLEAR, NULL), 1, &ft_write_null);
}
