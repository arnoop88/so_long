/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:22:50 by apodader          #+#    #+#             */
/*   Updated: 2023/09/26 16:19:00 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_char(char c)
{
	return (write (1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;
	int	err;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		err = ft_print_char(str[i]);
		if (err == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	len = ft_print_str(str);
	free(str);
	return (len);
}

int	ft_formats(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (c == '%')
		len += ft_print_char(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;
	int		err;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			err = ft_formats(args, str[i + 1]);
			i++;
		}
		else
			err = ft_print_char(str[i]);
		if (err == -1)
			return (-1);
		else
			len += err;
		i++;
	}
	va_end(args);
	return (len);
}
