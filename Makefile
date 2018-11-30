#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 10:43:47 by erli              #+#    #+#              #
#    Updated: 2018/11/30 11:49:02 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	fdf

SRCSDIR			=	srcs

OBJSDIR			=	objs

SRCS			=	main.c

OBJS			=	$(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

INCL			=	-I includes/ -I libft/includes -I minilibx_macos/

LIB				=	-Lminilibx_macos/ -lmlx -Llibft/ -lft

FRAMEWORK		=	-framework OpenGL -framework AppKit

LIBFT			=	libft/libft.a

LIBMLX			=	minilibx_macos/libmlx.a


all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(LIBMLX) $(OBJS) includes/fdf.h
					$(CC) $(CFLAGS) $(INCL) $(LIB) -o $(NAME) $(OBJS) $(FRAMEWORK)

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c 
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAGS) $(INCL) -o $@ $< $(FRAMEWORK)

$(LIBFT)		:	
					make -C libft/ && make -C libft/ clean

$(LIBMLX)		:
					make -C minilibx_macos

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

delsav			:
					$(RM) *~
					$(RM) */*~
					$(RM) \#*
					$(RM) */\#*

.PHONY			:	clean