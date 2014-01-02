/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:42:28 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 21:12:50 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"

void	ft_terminal_run(t_term *term)
{
	char	buff[5];

	ft_write_args(term);
	ft_move_to(term, /*pos-x, pos-y*/);
	while (42)
	{
		read(STDIN_FILENO, buff, 5);
	}
}

