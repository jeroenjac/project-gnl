/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 12:55:47 by jjacobs       #+#    #+#                 */
/*   Updated: 2021/01/29 19:45:56 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>	//read
#include <stdio.h>	//rm; printf
#include <string.h> //rm; bzero, strchr, strndup

/*
** Functions
** 1 ft_bzero (or memset)
** 2 ft_strchr
** 3 ft_strlen
** 4 ft_strndup (memcpy)
** 5 ft_strjoin (memcpy, calloc, strlen)
** 6 ft_memcpy
** 7 ft_calloc
** 8 gnl
** 9	? get 1 line??
** 10	? free function 
*/

void	construct_line(char **line, char *buffer, ssize_t *rd, char **eol);

int	get_buffer(char *buffer, int fd)
{
	ssize_t	rd;

	bzero(buffer, BUFFER_SIZE + 1);
	rd = read(fd, buffer, BUFFER_SIZE);		
	return (rd);
}

int get_next_line(int fd, char **line)
{	
	static char		buffer[BUFFER_SIZE + 1];
	static char		*eol = NULL;
	static ssize_t	rd = 0;
	
	printf("rd (start gnl) = %zi\n", rd);
	if (rd == 1)
	{
		//if this the case, need to know last process buf char
		//and continue there, for a new line
		//eol has a value: the previous \n
		rd = (buffer - eol) - 1;
		construct_line(line, eol + 1, &rd, &eol);
	}
	while (eol == NULL && (rd == 0 || rd == BUFFER_SIZE))
	{
		rd = get_buffer(buffer, fd);
		printf("rd (gnl) = %zi\n", rd);
		construct_line(line, buffer, &rd, &eol);
	}
	if (rd == BUFFER_SIZE)		//in this case, full line is processed
		return (1);
	return (rd);
}
	
void	construct_line(char **line, char *buffer, ssize_t *rd, char **eol)
{
	size_t linechars;

	*eol = strchr(buffer, '\n');
	printf("eol = %s\n", *eol);
	if (*eol != NULL)
		linechars = (size_t)(*rd) - strlen(*eol);
	//printf("linechars = %zi\n", linechars);
	if (*eol == NULL)
		*line = ft_strjoin(*line, strndup(buffer, BUFFER_SIZE));
	else
	{
		*line = ft_strjoin(*line, strndup(buffer, linechars));
		*rd = 1;
	}
}
/*
** APPROACH
** 1. Read 1x buffer
** 2. Check for \n 
**		--> if none store text --> goto 1
**		--> if \n --> split in 2 lines --> goto 2
** 3. Store text: Merge with "line remainder" (part of buffer after last \n).
**			line remainder can be NULL ("")
**			strjoin with existing text
**
*/
