/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:42:28 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:42:37 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"

void	ft_terminal_run(t_term *term)
{
	t_arg	*elem;
	int		key;

	elem = term->arg_list->first;
	ft_write(term);
	ft_move_to(term, elem->position->x, elem->position->y);
	while (42)
	{
		key = 0;
		read(STDIN_FILENO, &key, 4);
		if (term->status)
			ft_check_keys(term, key);
		else if (key == FT_KEY_ESCAPE && !term->status)
			ft_key_quit(term);
		else
			ft_key_return(term);
	}
}

