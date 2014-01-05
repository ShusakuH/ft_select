/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capabilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:47:31 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:39:32 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <curses.h>
#include <term.h>

char	*ft_s_underline(t_bool selected)
{
	if (!selected)
		return ("");
	else
		return (tgetstr(TC_S_UNDERLINE, NULL));
}

char	*ft_e_underline(t_bool selected)
{
	if (!selected)
		return ("");
	else
		return (tgetstr(TC_E_UNDERLINE, NULL));
}

char	*ft_s_inverse(t_bool selected)
{
	if (!selected)
		return ("");
	else
		return (tgetstr(TC_S_INVERSE, NULL));
}

char	*ft_e_inverse(t_bool selected)
{
	if (!selected)
		return ("");
	else
		return (tgetstr(TC_E_INVERSE, NULL));
}

void	ft_write_clear(void)
{
	tputs(tgetstr(TC_CLEAR, NULL), 1, &ft_write_null);
}

