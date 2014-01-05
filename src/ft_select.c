/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:36:50 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 20:54:04 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <stdlib.h>
#include "ft_select.h"

t_term	*g_term;

int	main(int argc, char *argv[])
{
	g_term = (t_term *)malloc(sizeof(t_term));
	g_term->cursor = (t_cursor *)malloc(sizeof(t_cursor));
	ft_init_terminal_data(g_term);
	ft_terminal_raw_mode(g_term);
	if (argc > 1)
		ft_terminal_parse_args(g_term, argv);
	ft_signal();
	if (argc > 1)
		ft_terminal_run(g_term);
	free(g_term);
	return (0);
}
