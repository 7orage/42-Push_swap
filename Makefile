# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/21 13:06:52 by lheteau           #+#    #+#              #
#    Updated: 2026/02/21 14:21:41 by lheteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = push_swap

CC = cc
SRC = main.c op_s.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = includes/ft_printf

FT_PRINTF       = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)
	@echo "\n*******************"
	@echo "PROJET COMPILE HEHE"
	@echo "*******************"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -I$(FT_PRINTF_DIR) -c $< -o $@


clean:
	make -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re