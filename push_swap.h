/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:25:16 by djang             #+#    #+#             */
/*   Updated: 2024/06/08 15:25:18 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

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

// deque_util.c
t_stack	*createstack(void);
t_node	*createnode(int data);
int		isstackempty(t_stack *stack);
t_node	*peekfrontstack(t_stack *stack);
t_node	*peekrearstack(t_stack *stack);

// deque_util2.c
void	insertfrontstack(t_stack *stack, t_node *element);
void	insertrearstack(t_stack *stack, t_node *element);
t_node	*deletefrontstack(t_stack *stack);
t_node	*deleterearstack(t_stack *stack);
void	destroystack(t_stack *stack);

//operator.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

//operator2.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

//operator3.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//ft_atoi.c
long	ft_atoi(char *str, int end);

//check_util.c
void	error(void);
void	check_argv(int argc, char *argv[]);
size_t	ft_strlen(char *s);
void	deque_in(t_stack *a, int argc, char *argv[]);
void	deque_in_inner(t_stack *a, char *str);

//check_util2.c
void	samecheck(t_stack *a);
void	sortedcheck(t_stack *a);

//sort_indexing.c
void	swap(int *a, int *b);
void	sortfor_indexing(int *array, int left, int right);
int		pivot(t_stack *a, int num);

//atob.c
void	atob(t_stack *a, t_stack *b);

//atob_util.c
void	divide_move(t_stack *a, t_stack *b);
void	divide_move_inner(t_stack *a, t_stack *b, int p0, int p3);
void	divide_move2(t_stack *a, t_stack *b);
void	hard_sorting(t_stack *a);
void	sorting_three(t_stack *a);
// 엣지 포인트에 대한 수정 필요!!

//btoa.c
void	btoa(t_stack *a, t_stack *b);

//btoa_util.c
int		maxormin(t_stack *a, int min);
int		count_ra(t_stack *a, int num);
int		indicator(int ra_count, int rb_count, \
int new_ra_count, int new_rb_count);
int		cal(int ra, int rb);
void	count(t_stack *a, t_stack *b, int *ra_count, int *rb_count);

//minmax.c
int		get_max(t_stack *a);
int		get_min(t_stack *a);

//operator_greedy.c
void	do_rr_rrr(t_stack *a, t_stack *b, int *ra_count, int *rb_count);
void	do_ra_rra(t_stack *a, int *ra_count);
void	do_rb_rrb(t_stack *b, int *rb_count);
void	last(t_stack *a);

void	displayLinkedDeque(t_stack *pDeque);
int		ft_strcmp(char *s1, char *s2);
#endif