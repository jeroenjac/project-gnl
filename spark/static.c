/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   static.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 15:51:16 by jjacobs       #+#    #+#                 */
/*   Updated: 2021/01/28 15:51:50 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		fun(void)
{
	static int	var = 0;

	var++;
	return (var);
}

int		main(void)
{
	int		run;

	run = 0;
	while (run < 9)
	{
		printf("var = %i\n", fun());
		run++;
	}
	return (0);
}
