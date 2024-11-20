# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 23:40:20 by edubois-          #+#    #+#              #
#    Updated: 2024/11/20 01:04:06 by lospacce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	so_long  

DIR_LIB 		:= 	LIB
LIBFT_DIR 		:=	$(DIR_LIB)/libft
PRINTF_DIR 		:=	$(DIR_LIB)/printf
GNL_DIR 		:=	$(DIR_LIB)/gnl

LIBFT_LIB 		:= $(LIBFT_DIR)/libft.a
PRINTF_LIB 		:= $(PRINTF_DIR)/libftprintf.a
GNL_LIB 		:= $(GNL_DIR)/gnl.a

DIR_MLX     	:= $(DIR_LIB)/MacroLibX
MLX_INCLUDES    := $(DIR_MLX)/includes
MLX             := $(DIR_MLX)/libmlx.so

IFLAGS          := -I $(MLX_INCLUDES)/

SRCS = main.c											\
	SRCS/parse_map_check_data/parse_map.c				\
	SRCS/get_map/get_map.c								\
	SRCS/get_data/get_data.c							\
	SRCS/parse_map_check_data/check_map.c				\
	SRCS/parse_map_check_data/flood_fill.c				\
	SRCS/parse_map_check_data/parse_getmap_utils.c		\
	SRCS/game/launch_game.c								\
	SRCS/get_data/fill_data_game.c						\
	SRCS/game/destroy_graphic.c							\
	SRCS/game/graphic/put_image.c						\
	SRCS/game/check_action.c							\
	SRCS/game/manage_hook.c								\
	SRCS/game/make_mouvement.c							\
	SRCS/game/print_moov.c								\
	SRCS/game/manage_rhino.c							\

OBJS 			:= $(SRCS:.c=.o)

CC 				:= @cc
FLAGS 			:= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(MLX) $(OBJS)
	$(CC) $(FLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) -lSDL2 -lm -Wl,-rpath,$(PWD)/LIB/MacroLibX
	@echo $(ART)

$(MLX):
	make -s -C $(DIR_MLX)

$(LIBFT_LIB):
	make -s -C  $(LIBFT_DIR)

$(PRINTF_LIB):
	make -s -C  $(PRINTF_DIR)

$(GNL_LIB):
	make -s -C  $(GNL_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -s -C  $(LIBFT_DIR)
	make clean -s -C  $(PRINTF_DIR)
	make clean -s -C  $(GNL_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -s -C  $(LIBFT_DIR)
	make fclean -s -C  $(PRINTF_DIR)
	make fclean -s -C  $(GNL_DIR)
	rm -f

re: fclean all

.PHONY: all clean fclean re
.SILENT:

ART	:= "                                     ░▒▓███████▓▒░░▒▓██████▓▒░░             ▒▓█▓▒░      ░▒▓██████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░                                                                                   ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                                                                  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                                                                                          ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░                                                                                         ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                                                                         ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░             ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                                                                                  ░▒▓███████▓▒░ ░▒▓██████▓▒░▒ ▓████████▓▒ ▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░                                                                                                                                 ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                           ██                                                                                                                                                                         ██  ██                                                                                                                                                                     ██▒▒  ▒▒██                                                                                                                                                                 ██▒▒▒▒  ▒▒▒▒██                                                                                                                                                             ██▒▒▒▒▒▒  ▒▒▒▒▒▒██                                                                                                                                                       ████▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒████                                                                                                                                                 ██▓▓▒▒▒▒▒▒████  ████▒▒▒▒▒▒▓▓██                                                                                                                                             ██▓▓▓▓▒▒▒▒██▓▓▒▒  ▒▒▓▓██▒▒▓▓▓▓▒▒██                                                                                                                                         ██▓▓▓▓▓▓▓▓██████      ██████▓▓▓▓▓▓▓▓██                                                                                                                                       ██▓▓▓▓▓▓██▒▒▒▒▒▒██  ██▒▒▒▒▒▒██▓▓▓▓▓▓██                                                                                                                                         ██████▒▒▒▒▒▒▒▒██▒▒██▒▒▒▒▒▒▒▒██████                                                                                                                                               ██▒▒▒▒▒▒██▒▒▒▒▒▒██▓▓▒▒▒▒██                                                                                                                                                 ██▒▒▒▒▓▓██▓▓▒▒▒▒▒▒▒▒██▒▒▒▒▒▒██                                                                                                                                               ██▒▒▒▒██▓▓▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒██                                                                                                                                                 ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                     ████▒▒▒▒██████▒▒▒▒████                                                                                                                                                           ████▒▒▒▒▒▒████                                                                                                                                                             ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                         ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                     ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                   ██▒▒▒▒████▒▒▒▒▒▒████▒▒▒▒██                                                                                                                                                   ██▒▒██    ██▒▒██    ██▒▒██                                                                                                                                                   ██▒▒██  ██▒▒▒▒▒▒██  ██▒▒██                                                                                                                                                   ██▒▒████▒▒▒▒▒▒▒▒▒▒████▒▒██                                                                                                                                                   ██▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒██                                                                                                                                                   ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                   ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                     ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██                                                                                                                                                         ████▒▒▒▒▒▒▒▒▒▒████                                                                                                                                                               ██████████                                                                                "