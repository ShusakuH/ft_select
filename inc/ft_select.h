/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:37:06 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 16:29:43 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

typedef struct	s_term {
	char	*term_buffer;
	int		max_cols;
	int		max_row;
}				t_term;

typedef struct	s_arg {
	char			*content;
	size_t			content_size;
	struct s_term	next;
}				t_arg;

int		ft_init_terminal_data(char **term_buffer);
void	ft_terminal_raw_mode(void);
void	ft_terminal_parse_args(char *argv[], char **env);
void	ft_terminal_run(void);
void	ft_terminal_exit(int status);
void	ft_terminal_restore(void);
void	ft_terminal_error(char *error_str);

char	*ft_ask_terminal_string(char *name, char **term_buffer);
int		ft_ask_terminal_numeric(char *name);
int		ft_ask_terminal_flag(char *name);

#endif /* !FT_SELECT_H */
