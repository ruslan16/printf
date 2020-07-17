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

NAME = libftprintf.a

ADDAR = ar rc

RLIB = ranlib

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_W = srcs/argsflags.c srcs/binary.c srcs/char.c srcs/color.c \
	srcs/conversion.c srcs/float2.c srcs/float.c srcs/ft_printf.c \
	srcs/hexa.c srcs/int.c srcs/numer.c srcs/octal.c srcs/parsing.c \
	srcs/pointer.c srcs/string.c srcs/trash_fun.c srcs/unsigned.c srcs/zero_struct.c

SRC_NAME = $(notdir $(SRC_W))

SRC_PATH = srcs

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CFLAGS += -I includes

CFLAGS += -I libft/includes

LIBFT = libft

LDLIBS = -lft

LDFLAGS = -L $(LIBFT)

###############################################################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
#	CFLAGS += -Wno-unused-but-set-variable
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
################################################################################

all	: $(NAME)

fast	:
	@$(MAKE) -s -j$(NUMPROC)

libft.a	:
	@echo "$(RED)Making libft...$(EOC)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT) all

$(OBJ_PATH) : libft.a
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@echo "$(GRN)Compiling with \"$(CFLAGS)\" :$(EOC)\n"

$(NAME)	: $(OBJS)
	@echo "$(GRN)%-50s$(EOC)\n" "Compilation done"
#	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@cp libft/libft.a $(NAME)
	$(ADDAR) $@ $^
	$(RLIB) $@
	@echo "$(GRN)%-50s$(EOC)\n" "$(NAME) done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@echo "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -o $@ -c $<

#so	: all
#	@echo "$(CC) (...) -shared -o $(NAME:.a=.so)\n"
#	@$(CC) $(OBJS) -shared -o $(NAME:.a=.so)

clean	:
	/bin/rm -rf $(OBJ_PATH)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@echo "$(RED)./$(OBJ_PATH), libft cleaned$(EOC)\n"

fclean	:	clean
	/bin/rm -f $(NAME)
	@echo "$(RED)$(NAME), libft.a removed$(EOC)\n"

ref	:
	/bin/rm -rf $(OBJ_PATH)
	@echo "$(RED)./$(OBJ_PATH), cleaned$(EOC)\n"
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

re	:	fclean
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

.PHONY: all fast libft.a ref clean fclean re

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
