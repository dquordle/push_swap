SRCS =          ./srcs/actions.c \
				./srcs/del_app.c \
                ./srcs/gnl.c \
                ./srcs/merge_sort.c \
                ./srcs/rotate_push.c \
                ./srcs/second_utils.c \
                ./srcs/triplets.c \
                ./srcs/utils.c

OBJS =			$(SRCS:.c=.o)

GCC = 			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			push_swap

LIBFT_NAME =	libftV3/libft.a

%.o:			%.c
				$(GCC) -c $(FLAGS) $< -o $(<:.c=.o)

all: 			make_libft $(NAME)

make_libft:
				cd ./libftV3 && make && cd ..

$(NAME):		$(OBJS)
				$(GCC) -c $(FLAGS) ./srcs/push_swap.c -o ./srcs/push_swap.o
				$(GCC) -c $(FLAGS) ./srcs/checker.c -o ./srcs/checker.o
				$(GCC) -o push_swap ./srcs/push_swap.o $(OBJS) $(LIBFT_NAME)
				$(GCC) -o checker ./srcs/checker.o $(OBJS) $(LIBFT_NAME)

clean:
				rm -f $(OBJS) ./srcs/push_swap.o ./srcs/checker.o
				cd ./libftV3 && make clean && cd ..

fclean:			clean
				rm -f push_swap checker
				cd ./libftV3 && make fclean && cd ..

re:				fclean all

.PHONY:			all clean fclean re