/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:23:10 by yson              #+#    #+#             */
/*   Updated: 2022/05/31 23:20:30 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void				*ft_memset(void *b, int c, unsigned int len);
void				ft_bzero(void *s, unsigned int n);
void				*ft_memcpy(void *dst, const void *src, unsigned int n);
void				*ft_memccpy(void *dst, const void *src, int c, \
unsigned int n);
void				*ft_memmove(void *dst, const void *src, unsigned int len);
void				*ft_memchr(const void *s, int c, unsigned int n);
int					ft_memcmp(const void *s1, const void *s2, unsigned int n);
unsigned int		ft_strlen(const char *str);
unsigned int		ft_strlcpy(char *dest, const char *src, unsigned int size);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);
char				*ft_strrchr(const char *str, int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strnstr(const char *str, const char *to_find, \
size_t len);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(unsigned int count, unsigned int size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstprint(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));
#endif
