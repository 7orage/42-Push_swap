# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/21 13:06:52 by lheteau           #+#    #+#              #
#    Updated: 2026/03/11 14:56:34 by lheteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME      = push_swap

CC = cc
SRC = main.c get_stack.c get_lst.c utils.c \
	radix.c check_arg.c op_p.c op_r.c op_rr.c op_s.c  
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
CFLAGS = -Wall -Wextra -Werror -g

FT_PRINTF_DIR = includes/ft_printf
LIBFT_DIR = includes/libft

FT_PRINTF       = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "*******************"
	@echo "PROJET COMPILE HEHE"
	@echo "*******************"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@


clean:
	make -C $(FT_PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re