/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:00:37 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/15 21:23:40 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*** ~~ LIBS ~~ ***/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*** ~~ GET_NEXT_LINE_VARS ~~ ***/

# define BUFFER_SIZE 64

typedef struct s_gnl_fds
{
	char				buf[BUFFER_SIZE + 1];
	int					i;
	int					fd;
	struct s_gnl_fds	*next;
}						t_gnl_fds;

/*** ~~ PROTOTYPES ~~ ***/

// ~~ gnl
int			get_next_line(int fd, char **line);
t_gnl_fds	*gnl_lstadd_front(t_gnl_fds **start, int fd);
void		gnl_lstdelone(t_gnl_fds **start, t_gnl_fds *elem);
// ~~ mem
void		ft_bzero(void *dst, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		ft_free(char **ptr);
void		free_array(char ***ptr, size_t size);
void		*ft_memchr(const void *src, int value, size_t lenn);
int			ft_memcmp(const void *src1, const void *src2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *dst, int value, size_t len);
// ~~ num
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
char		*ft_nbtobase(long long nb, const char *base);
long long	ft_basetonb(char *nbr, const char *base);
char		*ft_convert_base(char *nbr, const char *base_from, const char *base_to);
int			ft_framing(int min, int nb, int max);
float		ft_framingf(float min, float nb, float max);
void		ft_swap(int *a, int *b);
// ~~ put
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putstr_fd(const char *s, int fd);
// ~~ str
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
char		**ft_split(char const *str, char sep);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strchrstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strchrstr_count(char *str, char *charset);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t dst_size);
char		*ft_strdup(const char *src);
char		*ft_strjoin(const char *s1, const char *s2, int alloc_args);
size_t		ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t		ft_strlen(const char *str);
char		*ft_strrev(char *str);
char		*ft_strtrim(char const *src, char const *charset);
int			ft_str_isalpha(char *str);
int			ft_str_isdigit(char *str);
int			ft_str_isalnum(char *str);
int			ft_str_isascii(char *str);
int			ft_str_isprint(char *str);
char		*ft_substr(char const *src, unsigned int start, size_t len);

#endif
