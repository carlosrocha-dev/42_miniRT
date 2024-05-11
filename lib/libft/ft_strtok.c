/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:16:49 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:17:06 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	len;

	len = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (len);
	while (*s1)
	{
		if (ft_strchr(s2,*s1))
			return (len);
		else
		{
			s1++;
			len++;
		}
	}
	return (len);
}

static size_t	ft_strspn(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(str1 + i))
	{
		j = 0;
		while (*(str2 + j))
		{
			if (*(str1 + i) == *(str2 + j))
				break ;
			j++;
		}
		if (!*(str2 + j))
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*start;
	char		*end;

	if (str)
		start = str;
	else
		start = next_token;
	if (!start)
		return (NULL);
	start += ft_strspn(start, delim);
	if (*start == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	end = start + ft_strcspn(start, delim);
	if (*end == '\0')
		next_token = NULL;
	else
	{
		*end = '\0';
		next_token = end + 1;
	}
	return (start);
}
