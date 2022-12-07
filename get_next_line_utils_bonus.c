/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:10:31 by gmorais-          #+#    #+#             */
/*   Updated: 2022/12/07 13:31:20 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strojoin(char *str1, char *str2)
{
	int		i;
	char	*mem;

	i = 0;
	mem = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!mem)
		return NULL;
	while (str1[i] && str1)
	{
		mem[i] = str1[i];
		i++;
	}
	free(str1);
	while(str2)
	{
		mem[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	mem[i] = '\0';
	return (mem);
}

int	stashfree(char *buff)
{
	int	i;
	int	j;
	int	l_true;

	i = 0;
	j = 0;
	l_true = 0;

	while (*buff)
	{
		if (l_true)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			l_true = 1;
		buff[i++] = '\0';
	}
	return (l_true);
}