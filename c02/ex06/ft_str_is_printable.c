/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:38:49 by xroca-pe          #+#    #+#             */
/*   Updated: 2023/08/22 12:38:27 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	print;
	int	i;

	i = 0;
	print = 1;
	while (str[i] != '\0')
	{
		if (str[i] > 31 && str[i] < 127)
			print = 1;
		else
			return (0);
		i++;
	}
	return (print);
}
