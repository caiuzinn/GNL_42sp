/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xubuntu <xubuntu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:51:17 by cda-silv          #+#    #+#             */
/*   Updated: 2020/06/29 16:02:37 by xubuntu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

static void    ft_free_null(char **str)
{
    int     i;

    if (!str || !*str)
        return ;
    free(*str);
    *str = NULL;
}

int     ft_buffToLine(char **buff, char **line)
{
    int     i;
    int     j;
    char    *tmp[ARG_MAX];

    i = 0;
    while (buff[0][i] != '\n' && buff[0][i] != '\0') 
        i++;
    if (buff[0][i] == '\n')
    {
        *line = ft_substr(buff[0], 0, i); // barra N morre ou ele vai antes ou depois ?
        j = ft_strlen(buff[0]);
        tmp[0] = ft_substr(buff[0], i + 1, j);
        ft_free_null(&*buff);
        buff[0] = tmp[0];
        return (1);
    }
    *line = ft_substr(buff[0], 0, i);
    ft_free_null(&*buff);
    return (0);
}

int		get_next_line(int fd, char **line)
{
    char            tmp[ARG_MAX];
    int             r[2];
    static char     *buff[OPEN_MAX]; // cada linha da matrix voce coloca um fd que sera uyma linha retornada

    if (fd >= 0 && line && BUFFER_SIZE > 0 && (*line = ft_strdup(""))) //(  como tem varios returns eu setei pra que qualquer coisa difente ja va direto
    {
        r[0] = SEM_BARRA_N;
        while (r[0] == SEM_BARRA_N)
        {
            if (buff[fd] == NULL && (r[1] = read(fd, tmp, BUFFER_SIZE)) >= 0
                && (tmp[r[1]] = '\0') == 0)
                buff[fd] = ft_strdup(tmp); // se tem um barra N no meio eu tenho que pegar o que sobrou antes e salvar
            if (buff[fd] != NULL)
                r[1] = ft_strlen(buff[fd]);
            r[0] = ft_buffToLine(&buff[fd], *&line); //tmp = NULL; //preciso limpar o tmp // adicionei que linha vei pegar a aprte anterior do buff
            if (r[1] == 0)
				return (END);
        }
        if (r[0] == COM_BARRA_N)
            return (COM_BARRA_N);
    }
    return (-1);
}

// dica não ler muito ver se o buff ja tem algo
// tem que ler tudo caso tenha BARRA N corta ele aloca tudo no line 
// a sobre volta pro BUFF
// ENQUANTO não tiver \n no caso o ret 1