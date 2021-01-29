/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jjacobs <jjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 14:28:39 by jjacobs       #+#    #+#                 */
/*   Updated: 2021/01/29 01:44:09 by jjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> //strlen, memcpy 
#include <stdlib.h> //calloc

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = strlen(s1);
	len2 = strlen(s2);
	join = calloc((len1 + len2 + 1), sizeof(char));
	if (join == NULL)
		return (NULL);
	memcpy(join, (char*)s1, len1 * sizeof(char));
	memcpy(join + len1, (char*)s2, len2 * sizeof(char));
	join[len1 + len2] = '\0';
	return (join);
}
