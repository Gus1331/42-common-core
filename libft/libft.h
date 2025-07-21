/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:26:13 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 02:47:14 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdio.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isascii(char c);
int		ft_isprint(char c);
int		ft_isalnum(char c);
int		ft_strlcpy(char *dst, char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char 	*ft_strchr(const char *s, int c);
char 	*ft_strrchr(const char *s, int c);
size_t	ft_strlcat(char *dst, char *src, size_t size);

#endif