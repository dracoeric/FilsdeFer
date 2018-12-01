#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 10:43:47 by erli              #+#    #+#              #
#    Updated: 2018/12/01 13:48:23 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	fdf

SRCSDIR			=	srcs

OBJSDIR			=	objs

SRCS			=	main.c				mlx_line_put.c		mlx_colourgiver_uni.c	\
					mlx_line_put_img.c	mlx_pixel_put_img.c	mlx_img_create.c		\
					mlx_iso_proj.c		mlx_para_proj.c		fdf_debug_print_map.c	\
					fdf_read_map.c

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
					$(CC) -c $(CFLAGS) $(INCL) -o $@ $<

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