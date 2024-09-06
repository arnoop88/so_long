/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:10:14 by apodader          #+#    #+#             */
/*   Updated: 2023/09/14 01:10:14 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char const *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

int	ft_nbrlen(long long nbr)
{
	int			len;

	len = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*arr;
	int			len;
	long int	num;

	num = n;
	len = ft_nbrlen(n);
	if (n < 0)
	{
		len++;
		num *= -1;
	}
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	while (len--)
	{
		arr[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		arr[0] = '-';
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	s_len;

	s_len = (unsigned int)ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_len < start)
		return (ft_strdup(""));
	if (len > (s_len - start))
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
