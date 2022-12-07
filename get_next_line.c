/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:48:04 by gmorais-          #+#    #+#             */
/*   Updated: 2022/12/07 13:40:49 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (stash[i])
			stash[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (stash[0] || read(fd, stash, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, stash);
		if (stashfree(stash))
			break ;
	}
	return (line);
}

/*int main()
{
	int fd = 0;
	char *to_free;
	fd = open("./fd.txt", O_RDWR);
	to_free = get_next_line(fd);
	printf("%s", to_free);
	close(fd);
}*/
