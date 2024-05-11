/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:52:25 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 17:20:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_vars(t_number_processor *np)
{
	np->r = 0.0;
	np->f = 0.0;
	np->d = 0;
	np->m = 0.1;
}

static void	process(const char **str, t_number_processor *np)
{
	while (**str != '\0')
	{
		if (**str >= '0' && **str <= '9')
		{
			if (np->d)
			{
				np->f += (**str - '0') * (np->m);
				np->m *= 0.1;
			}
			else
				np->r = np->r * 10 + (**str - '0');
		}
		else if (**str == '.')
			np->d = 1;
		else
			break ;
		(*str)++;
	}
}

double	ft_atof(const char *str)
{
	t_number_processor	np;
	int					s;

	init_vars(&np);
	s = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	process(&str, &np);
	return ((np.r + np.f) * s);
}
