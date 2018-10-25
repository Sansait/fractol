# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 16:02:52 by sklepper          #+#    #+#              #
#    Updated: 2018/10/25 17:18:21 by sklepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fractol
SRC			:=	argument.c burning_ship.c display.c \
				event.c julia.c main.c mandelbrot.c movement.c
HEADERS		:=	fractol.h
# directories :
SRCDIR		:=	srcs
OBJDIR		:=	obj
INCDIR		:=	includes
# libft
LIBFT_NAME	:=	libft.a
LIBFT_PATH	:=	libft/
LIBFT_INC	:=	includes
# **************************************************************************** #
# Compilation :
MYCC		:=	clang
MYCC		+=	-Werror -Wall -Wextra
RM			:=	/bin/rm -f
# **************************************************************************** #
# Automatic variable :
OBJ			:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEAD		:=	$(addprefic $(INCDIR)/, $(HEADERS))
# Include :
INCF_FRAC	:=	$(INCDIR)
INCF_LIBFT	:=	$(LIBFT_PATH)$(LIBFT_NAME)
# Link libft :
LINK_LIBFT	:=	$(LIBFT_PATH)$(LIBFT_NAME)
# Framework :
FRAME_W		:=	-framework OpenGL -framework AppKit
LIB			:=	-L $(LIBFT_PATH) -lft -L /usr/local/lib -lmlx
INC			:=	-I$(INCF_LIBFT) -I$(INCF_LMLX) -I$(INCDIR)
# **************************************************************************** #
# Target rules :
all: $(NAME)
$(NAME): $(OBJ) $(LINK_LIBFT) $(HEAD)
	@$(MYCC) -o $@ $(OBJ) $(INC) $(LIB) $(FRAME_W)
$(LINK_LIBFT):
	@make -C $(LIBFT_PATH)/
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(MYCC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2> /dev/null || true

lclean:
	@make -C $(LIBFT_PATH)/ clean

fclean: clean lclean
	@make -C $(LIBFT_PATH)/ fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re