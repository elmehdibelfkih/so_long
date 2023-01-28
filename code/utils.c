/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:38:19 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/27 23:10:17 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	while (s2[++j])
		s[i++] = s2[j];
	s[i] = '\0';
	return (free(s1), free(s2), s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*s1;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (i < start)
		return (NULL);
	else if (i >= start + len)
		s1 = malloc(len + 1);
	else
		s1 = malloc(i - start + 1);
	if (!s1)
		return (NULL);
	while (len-- > 0 && s[start])
		s1[j++] = s[start++];
	s1[j] = '\0';
	return (s1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*s;
	int				i;
	unsigned char	*p;

	i = size * count;
	s = malloc(size * count);
	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	while (i-- > 0)
		*p++ = '\0';
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		j;
	char		*s2;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	s2 = malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (i >= j)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}
