/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:53:24 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 12:50:31 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <libft_printf.h>
#include <unistd.h>
#include <signal.h>
#include <curses.h>
#include <term.h>

extern t_term *term;

void	ft_signal(void)
{
	signal(SIGTERM, &ft_signal_kill);
	signal(SIGKILL, &ft_signal_kill);
	signal(SIGINT, &ft_signal_kill);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, &ft_signal_cont);
	signal(SIGWINCH, &ft_signal_write);
}

void	ft_signal_kill(int sigint)
{
	(void)sigint;
	ft_write_clear();
	ft_terminal_exit(EXIT_FAILURE);
}

void	ft_signal_write(int sigint)
{
	if (sigint != SIGWINCH)
		return ;
	ft_write(term);
}

void	ft_signal_cont(int sigint)
{
	if (sigint != SIGCONT)
		return ;
	tcsetattr(0, TCSADRAIN, &term->termios);
	ft_write(term);
}

/*
** 	void	stp_catch(int a)
** 	{
** 		char cp[2] = {g_dat->c_cc[VSUSP], 0};
** 		printf("Stopping...\n");
** 		signal(SIGTSTP, SIG_DFL);
** 		ioctl(0, TIOCSTI, cp);
** 	}
*/
