/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main-gnl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 14:54:23 by jjacobs       #+#    #+#                 */
/*   Updated: 2021/01/29 19:05:13 by jjacobs       ########   odam.nl         */
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
	line = calloc(10, sizeof(*line));		//max 10 lines?
	//line[0] = strdup("ratel");				//init first line
	line[0] = calloc(1000, sizeof(**line));
	ret_value = 99;							//init ret value
	printf("= GNL READS:\n");
	ret_value = get_next_line(fd, line);
	printf("line: %s", *line);
	ret_value = get_next_line(fd, line);
	close(fd);
	printf("\nline: %s", *line);
	printf("\n= END OF GNL (gnl should not return the \\n, so no extra newline)\n");
	printf("last gnl returns %i\n", ret_value);
}

void	prototyping(char *filename)
{
	printf("=== PROTOTYPING ======\n");	
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	int		rd;

	//prep
	fd = open(filename, O_RDONLY);
	printf("fd = %i\n", fd);
	bzero(buf, BUFFER_SIZE + 1);
	
	//this would gnl 'do', e.g. for one line at a time, and MAX ONE LINE
	rd = read(fd, buf, BUFFER_SIZE);
	printf("rd = %i\n", rd);
	printf("= BUFFER READS:\n");
	printf("%s", buf);
	printf("= END OF BUFFER\n");
	//closing
	close(fd);
}

