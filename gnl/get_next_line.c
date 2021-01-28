/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 12:55:47 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/21 14:45:01 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{	
	// to supress flag compile warnings
	fd = 0;
	line[0][0] = 'a';
	return (0);
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
