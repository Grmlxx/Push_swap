/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:07:09 by alamaoui          #+#    #+#             */
/*   Updated: 2024/05/09 12:56:01 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}					t_node;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void				bye_bye(void);
t_node				*create_node(int value);
t_node				*read_data(t_node *stack_a, char **av, char **tokens,
						char *args);
size_t				ft_strlen(const char *s);
long				ft_atoi(const char *nptr, long resl);
char				*ft_strjoin(char *s1, char *s2);
void				free_memory(char *args, char **tokens);
void				free_stack(t_node *stack);
void				check_duplicates(t_node *stack);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(char *s1);
void				sa(t_node *stack_a, int flag);
void				sb(t_node *stack_b, int flag);
void				ss(t_node *stack_a, t_node *stack_b, int flag);
void				pa(t_node **stack_a, t_node **stack_b, int flag);
void				pb(t_node **stack_a, t_node **stack_b, int flag);
void				ra(t_node **stack_a, int flag);
void				rb(t_node **stack_b, int flag);
void				rr(t_node *stack_a, t_node *stack_b, int flag);
void				rra(t_node **stack_a, int flag);
void				rrb(t_node **stack_b, int flag);
void				rrr(t_node *stack_a, t_node *stack_b, int flag);
void				sort_2(t_node *stack_a);
void				sort_3(t_node **stack_a);
void				sort_4(t_node **stack_a, t_node **stack_b);
void				sort_5(t_node **stack_a, t_node **stack_b);
void				sort_more_than_5(t_node **stack_a, t_node **stack_b);
int					is_sorted(t_node *stack_a);
int					ft_lstsize(t_node *lst);
char				*args_joiner(char **av);
int					smallest(t_node *stack_a);
int					smallest(t_node *stack_a);
int					smallest_index(t_node *stack_a, int small);
void				push_to_b(t_node **stack_a, t_node **stack_b, int range);
void				push_to_a(t_node **stack_a, t_node **stack_b);
void				sorter(t_node **stack_a, t_node **stack_b);
char				*get_next_line(int fd);
char				*ft_strchr(char *s, int c);
int					ft_strcmp(char *s1, char *s2);

#endif