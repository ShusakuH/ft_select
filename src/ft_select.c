/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:36:50 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/03 21:22:13 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <stdlib.h>
#include "ft_select.h"

int main(int argc, char *argv[])
{
	t_term	*term;

	term = (t_term *)malloc(sizeof(t_term));
	term->cursor = (t_cursor *)malloc(sizeof(t_cursor));
	ft_init_terminal_data(term);
	ft_terminal_raw_mode();
	if (argc > 1)
		ft_terminal_parse_args(term, argv);
	ft_signal();
	if (argc > 1)
		ft_terminal_run(term);
	free(term);
	return (0);
}
