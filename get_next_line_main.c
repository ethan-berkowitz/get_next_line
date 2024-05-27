/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:47:42 by eberkowi          #+#    #+#             */
/*   Updated: 2024/05/27 11:46:19 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		file;
	char	*line;
	int		i;

	file = open(STDIN_FILENO, O_RDONLY);
	i = 1;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		printf("Line %d: %s\n", i, line);
		free(line);
		line = NULL;
		line = get_next_line(STDIN_FILENO);
		i++;
	}
	free(line);
	line = NULL;
	close(file);
}
