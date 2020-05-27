/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xubuntu <xubuntu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:51:17 by cda-silv          #+#    #+#             */
/*   Updated: 2020/05/26 17:55:02 by xubuntu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define BUFFER_SIZE 30

int		get_next_line(int fd, char **line)
{
    char    buff[BUFFER_SIZE + 1];
    int     size;
    
    if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
        return (-1);

    while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[size] = '\0';
        *line = ft_substr(buff, 0, ft_strlen(buff));
    }
    return (1);
}
