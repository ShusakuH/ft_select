/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 16:25:03 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/03 18:10:21 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft_printf.h>
#include "ft_select.h"

void	ft_terminal_error(char *error_str)
{
	ft_error(FT_ERROR_MASK, FT_NAME, FT_ERROR_DESC, error_str);
	ft_terminal_exit(EXIT_FAILURE);
}
