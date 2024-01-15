/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:24:08 by pfontenl          #+#    #+#             */
/*   Updated: 2023/08/27 15:38:51 by pfontenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f');
}

int	is_end(char c)
{
	return (c == '\n' || c == '\0');
}

char	*trim_str(char *str, char **end)
{
	char	*start;

	start = 0;
	while (!is_end(*str))
	{
		if (!is_space(*str))
		{
			if (!start)
				start = str;
			*end = str;
		}
		str++;
	}
	return (start);
}

void	trim_print(char *str)
{
	char	*start;
	char	*end;
	int		prev_space;

	start = trim_str(str, &end);
	prev_space = 0;
	while (start <= end)
	{
		if (!is_space(*start) || !prev_space)
			write(1, start, 1);
		prev_space = is_space(*start);
		start++;
	}
}
