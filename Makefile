SRCS =          ./srcs/actions.c \
				./srcs/del_app.c \
                ./srcs/gnl.c \
                ./srcs/merge_sort.c \
                ./srcs/rotate_push.c \
                ./srcs/second_utils.c \
                ./srcs/triplets.c \
                ./srcs/utils.c

B_SRCS =        ./bonuses/actions_bonus.c \
				./bonuses/del_app_bonus.c \
				./bonuses/draw_bonus.c \
				./bonuses/exec_comms_bonus.c \
				./bonuses/gnl_bonus.c \
				./bonuses/merge_sort_bonus.c \
				./bonuses/rotate_push_bonus.c \
				./bonuses/second_utils_bonus.c \
				./bonuses/triplets_bonus.c \
				./bonuses/utils_bonus.c

OBJS =			$(SRCS:.c=.o)

B_OBJS =        $(B_SRCS:.c=.o)

GCC = 			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			push_swap

LIBFT_NAME =	libftV3/libft.a

%.o:			%.c
				$(GCC) -c $(FLAGS) $< -o $(<:.c=.o)

all: 			$(NAME)

make_libft:
				@ cd ./libftV3 && make && cd ..

$(NAME):		$(OBJS) make_libft
				$(GCC) -c $(FLAGS) ./srcs/push_swap.c -o ./srcs/push_swap.o
				$(GCC) -c $(FLAGS) ./srcs/checker.c -o ./srcs/checker.o
				$(GCC) -o push_swap ./srcs/push_swap.o $(OBJS) $(LIBFT_NAME)
				$(GCC) -o checker ./srcs/checker.o $(OBJS) $(LIBFT_NAME)


bonus:          $(B_OBJS) make_libft
				$(GCC) -c $(FLAGS) ./bonuses/push_swap_bonus.c -o ./bonuses/push_swap_bonus.o
				$(GCC) -c $(FLAGS) ./bonuses/checker_bonus.c -o ./bonuses/checker_bonus.o
				$(GCC) -o push_swap ./bonuses/push_swap_bonus.o $(B_OBJS) $(LIBFT_NAME) ./bonuses/libmlx.a -framework OpenGL -framework AppKit
				$(GCC) -o checker ./bonuses/checker_bonus.o $(B_OBJS) $(LIBFT_NAME) ./bonuses/libmlx.a -framework OpenGL -framework AppKit

clean:
				rm -f $(OBJS) $(B_OBJS) ./srcs/push_swap.o ./srcs/checker.o ./bonuses/push_swap_bonus.o ./bonuses/checker_bonus.o
				cd ./libftV3 && make clean && cd ..

fclean:			clean
				rm -f push_swap checker
				cd ./libftV3 && make fclean && cd ..

re:				fclean all

.PHONY:			all clean fclean re