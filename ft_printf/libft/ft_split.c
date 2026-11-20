/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:56:36 by twalter           #+#    #+#             */
/*   Updated: 2026/10/29 21:07:12 by twalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Allocates memory (using malloc(3)) and returns an array of strings obtained by 
splitting ’s’ using the character ’c’ as a delimiter.
Each string in the returned array is allocated independently.
The array of pointers itself is also allocated dynamically.
The returned array must be NULL terminated.
 */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			counter++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (counter);
}

static size_t	word_len(char const *string, char c)
{
	size_t	len;

	len = 0;
	while (string[len] != '\0' && string[len] != c)
		len++;
	return (len);
}

static char	**free_array(char **array, size_t count)
{
	while (0 < count)
	{
		count--;
		free(array[count]);
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;
	size_t	idx;
	size_t	len_word;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	idx = 0;
	while (idx < words)
	{
		while (*s != '\0' && *s == c)
			s++;
		len_word = word_len(s, c);
		array[idx] = ft_substr(s, 0, len_word);
		if (array[idx] == NULL)
			return (free_array(array, idx));
		s += len_word;
		idx++;
	}
	array[idx] = NULL;
	return (array);
}
