/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 00:59:34 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/23 01:06:00 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strtolower(char *s)
{
	char	*start;

	start = s;
	while (s && *s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	return (start);
}
