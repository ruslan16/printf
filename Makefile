# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etristan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:32:13 by etristan          #+#    #+#              #
#    Updated: 2020/01/27 16:37:50 by etristan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_NAME = $(wildcard *.c)

#SRC_PATH = srcs
SRC_PATH = ./

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CFLAGS += -I ./

CFLAGS += -I libft/includes

#CFLAGS += -I minilibx_macos/

LIBFT = libft

#LIBMX = minilibx_macos

LDLIBS = -lft #-lmlx

LDFLAGS = -L $(LIBFT) #-L $(LIBMX)

###############################################################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -Wno-unused-but-set-variable
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
#	LDLIBS += -framework OpenGL -framework AppKit
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
################################################################################

all	: $(NAME)

fast	:
	@$(MAKE) -s -j$(NUMPROC)

libft.a	:
	@printf "$(RED)Making libft...$(EOC)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT) all

#libmlx.a :
#	@echo "$(RED)Making libmlx...$(EOC)\n"
#	@$(MAKE) --no-print-directory -C $(LIBMX) all	

$(OBJ_PATH) : libft.a #libmlx.a
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf "$(GRN)Compiling with \"$(CFLAGS)\" :$(EOC)\n"

$(NAME)	: $(OBJS)
	@printf "$(GRN)%-50s$(EOC)\n" "Compilation done"
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@printf "$(GRN)%-50s$(EOC)\n" "$(NAME) done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -o $@ -c $<

#so	: all
#	@echo "$(CC) (...) -shared -o $(NAME:.a=.so)\n"
#	@$(CC) $(OBJS) -shared -o $(NAME:.a=.so)

clean	:
	/bin/rm -rf $(OBJ_PATH)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
#	@$(MAKE) --no-print-directory -C $(LIBMX) clean
	@printf "$(RED)./$(OBJ_PATH), libft libmlx cleaned$(EOC)\n"

fclean	:	clean
	/bin/rm -f $(NAME)
	@printf "$(RED)$(NAME), libft.a libmlx.a removed$(EOC)\n"

ref	:
	/bin/rm -rf $(OBJ_PATH)
	@printf "$(RED)./$(OBJ_PATH), cleaned$(EOC)\n"
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

re	:	fclean
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

.PHONY: all fast libft.a libmlx.a clean fclean re

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
