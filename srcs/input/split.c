/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:18:14 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 13:21:30 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	ft_isdelimeter(char str, char c)
{
	if (str == c)
		return (1);
	else
		return (0);
}

char	**clean(char **array, int i)
{
	while (--i >= 0)
		free(*(array + i));
	free (array);
	return (NULL);
}

int	substr_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isdelimeter(*str, c))
			str++;
		if (*str && !ft_isdelimeter(*str, c))
			count++;
		while (*str && !ft_isdelimeter(*str, c))
			str++;
	}
	return (count);
}

static char	*substr_cpy(const char *src, size_t len)
{
	char	*dest;

	dest = (char *)malloc(len * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len);
	return (dest);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	split = (char **)malloc((substr_count(str, c) + 1) * sizeof(char *));
	if (!str || !split)
		return (clean(split, k));
	while (*(str + i))
	{
		if (*(str + i) == c)
			i++;
		j = i;
		while (*(str + i) && *(str + i) != c)
			i++;
		if (i > j)
			*(split + k++) = substr_cpy(&str[j], (i - j) + 1);
		if (!*(split + k - 1))
			return (clean(split, k));
	}
	*(split + k) = NULL;
	return (split);
}
