/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:17:46 by pfontenl          #+#    #+#             */
/*   Updated: 2023/08/27 15:26:58 by pfontenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	count_lines(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}

char	*find_line(char *str, int n)
{
	int	i;

	if (n == 0)
		return (str);
	i = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			i++;
			if (i == n)
				return (str + 1);
		}
		str++;
	}
	return (0);
}

int	count_chars(char *filename)
{
	int		fd;
	char	*buff;
	int		i;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (read(fd, &buff, sizeof(char)) > 0)
		i++;
	close(fd);
	return (i);
}

void	copy_file(char *filename, char *str)
{
	int		fd;
	char	buff[1];

	fd = open(filename, O_RDONLY);
	while (read(fd, &buff, sizeof(char)) > 0)
	{
		*str = *buff;
		str++;
	}
	close(fd);
}

char	*read_file(char *filename)
{
	char	*str;

	str = malloc(count_chars(filename) * sizeof(char));
	if (str)
		copy_file(filename, str);
	return (str);
}
