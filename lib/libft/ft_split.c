/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:51:02 by bluiz-al          #+#    #+#             */
/*   Updated: 2024/01/21 16:33:30 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_mtx(const char *s, const char *c, char **mtx, int count)
{
	char	*p;
	char	*p_chr;

	p = (char *)s;
	p_chr = p;
	while (p_chr && p && *p && *p_chr)
	{
		if (p_chr && *p_chr)
			p = p_chr;
		while (p_chr && *p && *p == *c && *c)
			p++;
		p_chr = ft_strchr(p, *c);
		count += (*p && *p != *c);
		if (p && *p && mtx != NULL)
			mtx[count - 1] = ft_substr(p, 0, p_chr - p);
	}
	if (mtx == NULL)
	{
		mtx = (char **)ft_calloc(count + 1, sizeof(char *));
		return (ft_mtx(s, c, mtx, 0));
	}
	mtx[count] = 0;
	return (mtx);
}

char	**ft_split(char const *s, char c)
{
	return (ft_mtx(s, &c, NULL, 0));
}
