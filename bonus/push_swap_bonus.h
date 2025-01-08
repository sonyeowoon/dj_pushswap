/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:58:28 by djang             #+#    #+#             */
/*   Updated: 2024/06/14 19:56:25 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_linkedlist
{
	int					num;
	struct s_linkedlist	*prev;
	struct s_linkedlist	*next;
}	t_node;

typedef struct s_stack
{
	int					currentcount;
	struct s_linkedlist	*front;
	struct s_linkedlist	*rear;
}	t_stack;

// deque_util_bonus.c
t_stack	*createstack(void);
t_node	*createnode(int data);
int		isstackempty(t_stack *stack);
t_node	*peekfrontstack(t_stack *stack);
t_node	*peekrearstack(t_stack *stack);

// deque_util2_bonus.c
void	insertfrontstack(t_stack *stack, t_node *element);
void	insertrearstack(t_stack *stack, t_node *element);
t_node	*deletefrontstack(t_stack *stack);
t_node	*deleterearstack(t_stack *stack);
void	destroystack(t_stack *stack);

//operator_bonus.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

//operator2_bonus.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

//operator3_bonus.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//ft_atoi_bonus.c
long	ft_atoi(char *str, int end);

//check_util_bonus.c
void	error(void);
void	check_argv(int argc, char *argv[]);
size_t	ft_strlen(char *s);
void	deque_in(t_stack *a, int argc, char *argv[]);
void	deque_in_inner(t_stack *a, char *str);

//check_util2_bonus.c
void	samecheck(t_stack *a);
void	sortedcheck(t_stack *a, t_stack *b);

//get_next_line_bonus.c
char	*restore_value(char *backup);
char	*returning_value(char *backup);
char	*get_next_line_inner(int fd, char *buffer, char *backup);
char	*get_next_line(int fd);

//get_next_linc_utils_bonus.c
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

//checker_bonus.c
int		ft_strcmp(char *s1, char *s2);
void	check(t_stack *a, t_stack *b);
void	check_inner(t_stack *a, t_stack *b, char *temp);
void	checker_error_exit(t_stack *a, t_stack *b, char *temp);
#endif
