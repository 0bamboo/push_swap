# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 14:08:46 by abdait-m          #+#    #+#              #
#    Updated: 2021/06/30 15:03:33 by abdait-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

B_NAME = checker

PS_LIB = pushswap.a

C_LIB = checker.a

MAIN = ./srcs/push_swap.c

B_MAIN  = ./srcs/checker.c

LIBFT = ./libft

LIBFT_LIB = $(LIBFT)/libft.a

FILES = ./srcs/error_checker.c ./srcs/push.c ./srcs/instructions_1.c ./srcs/get_next_line.c \
		./srcs/get_args.c ./srcs/sorting_the_stack.c ./srcs/sorting_tools.c ./srcs/sorting_tools_2.c \
		./srcs/rotate.c ./srcs/tools.c ./srcs/instructions_2.c ./srcs/sorting_the_array.c ./srcs/fill_stack.c \

B_FILES = ./srcs/checker_tools.c \

HEADER = ./header/push_swap.h

OBJECT = $(FILES:.c=.o)

B_OBJ = $(B_FILES:.c=.o)

FLAGS = -Wextra -Werror -Wall

LIBFT_FILES = $(wildcard ./libft/*.c ./libft/*.h)

all: $(NAME)

$(NAME): $(LIBFT_FILES) $(OBJECT) $(HEADER) $(MAIN) $(FILES)
			@make -C $(LIBFT)
			@ar -rcs $(PS_LIB) $(OBJECT)
			@gcc  $(FLAGS) $(MAIN) $(PS_LIB) $(LIBFT_LIB) -o $(NAME)
			@echo "\n\033[35m Push_swap program is created .\033[0m\n"
					
bonus : $(B_NAME)

$(B_NAME): $(LIBFT_FILES) $(OBJECT) $(B_OBJ) $(HEADER) $(B_MAIN) $(FILES) $(B_FILES)
			@make -C $(LIBFT)
			@ar -rcs $(C_LIB) $(OBJECT) $(B_OBJ)
			@gcc  $(FLAGS) $(B_MAIN) $(C_LIB) $(LIBFT_LIB) -o $(B_NAME)
			@echo "\n\033[33m Checker program is created .\033[0m\n"

%.o:%.c $(HEADER)
			@gcc -c $< $(FLAGS) -o $@

clean:
			@make clean -C $(LIBFT)
			@rm -rf srcs/*.o $(LIB)
			@echo "\n\033[32mCleaning is Done!\033[0m\n"

fclean: clean
			@make fclean -C $(LIBFT)
			@rm -rf $(NAME) $(PS_LIB) $(B_NAME) $(C_LIB)

re : fclean all