/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main-gnl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 14:54:23 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/21 15:17:59 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h> //can this be left out since already in .h?
#include "../gnl/get_next_line.h" // this will not work for other dir?

void	prototyping(char *filename);
void	testing(char *filename);

int		main (int argc, char **argv)
{
	char	*filename;
	
	//to suppress flag compile warnings
	argc = 0;
	filename = strdup(argv[1]);

	printf("Setting (BUFFER_SIZE) = %i\n", BUFFER_SIZE);
	printf("Testing GNL with file: %s\n", filename);
	prototyping(filename);
	testing(filename);
	return (0);
}

void	testing(char *filename)
{
	printf("=== TESTING ==========\n");	
	int		fd;
	char	**line;
	int		ret_value;

	fd = open(filename, O_RDONLY);
	line = calloc(10, sizeof(*line));
	line[0] = strdup("ratel");
	ret_value = 99;
	ret_value = get_next_line(0, line);
	printf("gnl returns %i\n", ret_value);
}

void	prototyping(char *filename)
{
	printf("=== PROTOTYPING ======\n");	
	int		fd;
	char	buf[BUFFER_SIZE];

	//prep
	fd = open(filename, O_RDONLY);
	printf("fd = %i\n", fd);
	
	//this would gnl 'do'
	read(fd, buf, BUFFER_SIZE);
	printf("= BUFFER READS:\n");
	printf("%s", buf);
	printf("= END OF BUFFER\n");
	//closing
	close(fd);
}
