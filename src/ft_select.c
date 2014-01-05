/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:36:50 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 12:49:07 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <stdlib.h>
#include "ft_select.h"

t_term	*term;

int main(int argc, char *argv[])
{
	term = (t_term *)malloc(sizeof(t_term));
	term->cursor = (t_cursor *)malloc(sizeof(t_cursor));
	ft_init_terminal_data(term);
	ft_terminal_raw_mode(term);
	if (argc > 1)
		ft_terminal_parse_args(term, argv);
	ft_signal();
	if (argc > 1)
		ft_terminal_run(term);
	free(term);
	return (0);
}
