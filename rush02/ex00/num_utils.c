/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:42:19 by pfontenl          #+#    #+#             */
/*   Updated: 2023/08/27 17:27:44 by pfontenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c);

int	ft_atoi(char *str, int *out)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		if (result > 2147483647 || result < 0)
			*out = 0;
		i++;
	}
	if (str[i] != '\0')
		*out = 0;
	return (result);
}

char	*ft_itoa(int nb)
{
	char	*buffer;
	int		i;
	int		col_count;
	int		col_val;

	col_count = 2;
	col_val = 1;
	while (nb / col_val >= 10)
	{
		col_count++;
		col_val *= 10;
	}
	buffer = malloc(col_count * sizeof(char));
	i = 0;
	while (i < col_count - 1)
	{
		buffer[i] = (nb / col_val) % 10 + '0';
		col_val /= 10;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
