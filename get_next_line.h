/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedfousi <pedfousi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:05:31 by pedfousi          #+#    #+#             */
/*   Updated: 2025/03/07 15:03:52 by pedfousi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
char	*get_line(t_list *list);
void	polish_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
void	append(t_list **list, char *buf);

#endif
