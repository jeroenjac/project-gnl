/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing-gnl.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 13:00:11 by jjacobs       #+#    #+#                 */
/*   Updated: 2020/12/21 13:26:01 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
	char	*filename;
	
	argc = 0;
	filename = strdup(argv[1]);

	printf("Testing GNL with file: %s\n", filename);

	return (0);
}
