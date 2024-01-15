/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:09:07 by xroca-pe          #+#    #+#             */
/*   Updated: 2023/08/28 17:04:32 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' 
		|| c == '\v' || c == '\f');
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	neg = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	if (!(neg % 2 == 0))
		result *= -1;
	return (result);
}
