/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdancy <kdancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:37:41 by kdancy            #+#    #+#             */
/*   Updated: 2022/05/10 17:37:42 by kdancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_in(char c, char *set)
{
	int counter;

	counter = -1;
	while (set[++counter])
	{
		if (c == set[counter])
			return (1);
			// return (counter);
	}
	return (0);
	// return (-1);
}

size_t	command_words_count(char **args)
{
	size_t	counter;
	size_t	words_count;
//	size_t	word_len;

	words_count = 0;
//	word_len = 0;
	while (*args)
	{
		counter = 0;
		while ((*args)[counter])
		{
			if (is_in((*args)[counter], FT_DELIM) >= 0 && is_in((*args)[counter], FT_DELIM) == is_in((*args)[counter + 1], FT_DELIM))
			{
				if (counter > 0 || counter < ft_strlen(*args))
					++words_count;
				++words_count;
				++counter;
			}
			else if (is_in((*args)[counter], FT_DELIM) >= 0)
			{
				if (counter > 0 || counter < ft_strlen(*args))
					++words_count;
				++words_count;
			}
			++counter;
		}
		++args;
		++words_count;
	}
	return (words_count);
}

