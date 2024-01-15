/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:19:04 by pfontenl          #+#    #+#             */
/*   Updated: 2023/08/27 16:56:14 by pfontenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c);
int		count_lines(char *str);
char	*find_line(char *str, int n);
void	trim_print(char *str);

int	find_key(char *dict, char *key)
{
	char	*line;
	int		i;
	int		key_match;

	i = count_lines(dict);
	while (i >= 0)
	{
		line = find_line(dict, i);
		key_match = 0;
		while (*line == key[key_match])
		{
			key_match++;
			line++;
			if (key[key_match] == '\0' && (*line == ':' || is_space(*line)))
				return (i);
		}
		i--;
	}
	return (-1);
}

char	*find_value(char *dict, int line)
{
	char	*start;

	start = find_line(dict, line);
	while (*start != ':')
		start++;
	return (start + 1);
}

int	print_value(char *dict, char *key, int add_space)
{
	int	line;

	line = find_key(dict, key);
	if (line == -1)
		write(1, "Dict Error\n", 11);
	else
	{
		trim_print(find_value(dict, line));
		if (add_space)
			write(1, " ", 1);
	}
	return (line != -1);
}
