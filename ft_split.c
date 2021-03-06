/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:38:18 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/28 16:19:16 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_cutoff(const char *str, int start, int end)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc((end - start + 1) * sizeof(char));
	if (!new)
		return (0);
	while (start < end)
		new[i++] = str[start++];
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tmp;
	int		start;

	if (!s)
		return (0);
	tmp = (ft_calloc((sizeof(char *)), (ft_count(s, c) + 1)));
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tmp[j++] = ft_cutoff(s, start, i);
			start = -1;
		}
		i++;
	}	
	return (tmp);
}

// int	main(void)
// {
// 	char	*str[] = "Geeks-for-Geeks";
// 	char	c = '-';

// 	printf("%s\n", ft_split(str, c));
// }
// tmp[j] = 0;