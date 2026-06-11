
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
typedef struct ps_struct ps_struct;
typedef struct stack stack;



struct ps_struct
{

	stack *stack_a;
	stack *stack_b;
	int strategy;
	int benchie;
	float disorder; 

};

struct stack
{
	int	*array;
	int size;
	
	int	is_a;

	int s; //swap
	int ss;//swap swap
	int p; //push
	int r; //rotate
	int rr;//rotate rotate
	int rrr;//reverse rotate
	int rrrr;//reverse rotate reverse rotate

	ps_struct *struc;

};




#define PRINT_FINAL(X) _Generic((X), \
int: printf(#X "=%d ", (X)), \
float: printf(#X "=%f ", (X)), \
double: printf(#X "=%f ", (X)), \
char *: printf("%s ", (X)), \
char: printf(#X "=%c ", (X)), \
const char *: printf("%s ", (X)), \
default: printf("wtf "))


#define LOOP1(X) PRINT_FINAL(X)
#define LOOP2(X, ...) PRINT_FINAL(X); LOOP1(__VA_ARGS__)
#define LOOP3(X, ...) PRINT_FINAL(X); LOOP2(__VA_ARGS__)
#define LOOP4(X, ...) PRINT_FINAL(X); LOOP3(__VA_ARGS__)
#define LOOP5(X, ...) PRINT_FINAL(X); LOOP4(__VA_ARGS__)
#define LOOP6(X, ...) PRINT_FINAL(X); LOOP5(__VA_ARGS__)

#define WTF(_1, _2, _3, _4, _5, _6, LOOP, ...) LOOP

#define PRINT(...) WTF(__VA_ARGS__, LOOP6, LOOP5, LOOP4, LOOP3, LOOP2, LOOP1)(__VA_ARGS__); puts("");

char	*simple_algo(stack *a, stack *b);
char	*medium_algo(stack *a, stack *b);
char	*complex_algo(stack *a, stack *b);

void	push(stack *staack_from, stack *staack_to);
void	action_push(stack *staack_from, stack *staack_to);
void	pushpush(stack *stack_a, stack *stack_b);
void	reverse_rotate(stack *staack);

void	ft_sort_int_tab(int *tab, int size);
double	ft_sqrt(double n);

void	action_reverse_rotate(stack *staack);
void	reverse_rotate_reverse_rotate(stack *stack_a, stack *stack_b);
void	rotate(stack *staack);
void	action_rotate(stack *staack);
void	rotaterotate(stack *stack_a, stack *stack_b);
void	swap(stack *staack);
void	action_swap(stack *staack);
void	swapswap(stack *stack_a, stack *stack_b);

float	calculate_disorder(int *stack_a, int size);
int	check_arg(int check_bench, char **argv);
void	start_algo(int strategy, stack *stack_a, stack *stack_b, float disorder);
char	*get_strat_name(int strategy, float disorder);
void	generate_benchmark(int strategy, float disorder, stack *stack_a,
		stack *stack_b);
void	fill_values(stack *stack, int is_a, int size_array);
stack	*create_stack(int is_a, int size_array, int arg_index, char **argv);
ps_struct *create_struc(stack *stack_a, stack *stack_b, char **argv, int size_array);
int	ft_atoi(char *nptr);
void	print_stack(stack *staack);
int	is_sort(stack *staack);
int	string_equals(char *str1, char *str2);

void	push_swap(int size_array, char **argv, int arg_index);

static int	ft_kelforma(char forma, va_list ap, int *ct);
int	ft_printf(const char *cible, ...);
void	ft_printc(char ap, int *ct);
void	ft_printp(void *ap, int *ct);
void	ft_printdi(long nb, int *ct);
void	ft_printu(unsigned int ap, int *ct);
void	ft_printx(unsigned int nb, int *ct);
void	ft_print_majx(unsigned int nb, int *ct);
void	ft_printpc(int *ct);
void	ft_prints(char *ap, int *ct);
void ft_printfloat(float f, int *ct);