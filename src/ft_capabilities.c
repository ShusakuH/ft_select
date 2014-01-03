/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capabilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:47:31 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/03 20:03:07 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <curses.h>
#include <term.h>

char	*ft_s_underline(t_bool selected)
{
	char	*buff;

	buff = tgetstr(TC_S_UNDERLINE, NULL);
	if (!selected)
		return ("");
	else
		return (buff);
}

char	*ft_e_underline(t_bool selected)
{
	char	*buff;

	buff = tgetstr(TC_E_UNDERLINE, NULL);
	if (!selected)
		return ("");
	else
		return (buff);
}

char	*ft_s_inverse(t_bool selected)
{
	char	*buff;

	buff = tgetstr(TC_S_INVERSE, NULL);
	if (!selected)
		return ("");
	else
		return (buff);
}

char 	*ft_e_inverse(t_bool selected)
{
	char	*buff;

	buff = tgetstr(TC_E_INVERSE, NULL);
	if (!selected)
		return ("");
	else
		return (buff);
}

