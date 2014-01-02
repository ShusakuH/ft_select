/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 00:18:50 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/05 03:36:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG__H
# define FT_DEBUG__H

# include <libft.h>

# define TXT(x) #x

# define PRINTNB_FD(nb, fd) ft_putnbr_fd(nbr, fd)
# define PRINTNBL_FD(nb, fd) ft_putnbr_fd(nbr, fd); ft_putendl_fd("")
# define PRINTNB(nb) PRINTNB_FD(nb, 1)
# define PRINTNBL(nb) PRINTNBL_FD(nb, 1)

# define PRINT_FD(x, fd) ft_putstr_fd(x, fd)
# define PRINT(x) PRINT_FD(x, 1)

# define PRINTL_FD(x, fd) ft_putendl_fd(x, fd)
# define PRINTL(x) PRINTL_FD(x, 1)

#endif /* !FT_DEBUG__H */
