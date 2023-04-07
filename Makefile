# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arincon <arincon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:02:04 by arincon           #+#    #+#              #
#    Updated: 2023/04/07 17:03:36 by arincon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

#---------------------------------------------------#
#	INGREDIENTS										#
#---------------------------------------------------#
# LIBS			libraries to be used
# LIBS_TARGET	libraries to be built
#
# INCS			header file locations
#
# SRC_DIR		source directory
# SRCS			source files
#
# BUILD_DIR		build directory
# OBJS			object files
# DEPS			dependency files
#
# CC			compiler
# CFLAGS		compiler flags
# CPPFLAGS		preprocessor flags
# LDFLAGS		linker flags
# LDLIBS		libraries name

LIBS		:= ft gnl
LIBS_TARGET	:=			\
	lib/libft/libft.a	\
	lib/libgnl/libgnl.a

INCS		:= include	\
	lib/libft/include	\
	lib/libgnl/include

SRC_DIR		:= src
SRCS		:=			\
	pipex.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
#CFLAGS		:= -g
CFLAGS		:= -Wall -Wextra -Werror -g
# -I lib/libft/include -L lib/libft -l libft
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))

LMLX		:= -lXext -lX11 -lm -lz

#---------------------------------------------------#
#	UTENSILS										#
#---------------------------------------------------#
# RM		force remove
# MAKEFLAGS	make flags
# DIR_DUP	duplicate directory tree

RM			:= rm -f

MAKEFLAGS   += --no-print-directory

DIR_DUP		= mkdir -p $(@D)

#---------------------------------------------------#
#	RECIPES											#
#---------------------------------------------------#
# all		default goal
# $(NAME)	link .o -> archive
# $(LIBS)	build libraries
# %.o		compilation .c -> .o
# clean		remove .o
# fclean	remove .o + binary
# re		remake default goal
# run		run the program
# info		print the default goal recipe

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(LMLX) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	for f in $(strip(dir $(LIBS_TARGET))); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

gdb:
	$(MAKE) all
	gdb ./$(NAME)

#---------------------------------------------------#
#	SPEC											#
#---------------------------------------------------#

.PHONY: clean fclean re
.SILENT:
