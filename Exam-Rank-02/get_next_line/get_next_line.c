/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:14:28 by slammari          #+#    #+#             */
/*   Updated: 2022/02/13 19:36:12 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

char *get_next_line(int fd)
{
    char tmp[800000];
    char buff[0];
    char *line;
    int i = 0;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    tmp[0] = '\0';
    while (read(fd, buff, 1) == 1)
    {
        tmp[i] = buff[0];
        tmp[i + 1] = '\0';
        if (tmp[i] == '\n')
        { 
            i++;
            break ;
        }    
        i++;
    }
    if (tmp[0] == '\0')
        return (NULL);
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (tmp[i])
    {
        line[i] = tmp[i];
        i++;
    }
    line[i] = '\0';
    return(line);
}
