# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samin <samin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 12:45:02 by ncolomer          #+#    #+#              #
#    Updated: 2021/05/19 22:10:13 by samin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	src/main.c src/engin/* src/parse/* src/util/*\
					src/gnl/get_next_line.c src/gnl/get_next_line_utils.c
					
BONUSE_SRCS		= 	bonus/src/main.c bonus/src/engin/* bonus/src/parse/*\
					bonus/src/util/* src/gnl/get_next_line.c src/gnl/get_next_line_utils.c 

OBJS			= $(SRCS:.c=.o)

LIBFT 			= libft.a
MLX				= libmlx.a

CC				= gcc -o
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -L./ -lmlx -framework OpenGL -framework Appkit

NAME			= cub3D

BONUSE_NAME		= cub3D_bonus

all:			$(NAME)

	
$(NAME):		$(LIBFT) $(MLX)
				$(CC) $(NAME) $(SRCS) $(LIBFT) $(MLX) ${CFLAGS}  ${LIBS}

$(BONUSE_NAME) : $(LIBFT) $(MLX)
				$(CC) $(BONUSE_NAME) $(BONUSE_SRCS) $(LIBFT) $(MLX) ${CFLAGS}  ${LIBS}

$(LIBFT):
	make all -C src/libft
	cp src/libft/$(LIBFT) ./

$(MLX):
	make all -C mlx/minilibx_opengl_custom
	cp mlx/$(MLX) ./

clean:			
				$(MAKE) -C libft fclean
				$(MAKE) -C mlx/minilibx_opengl_custom clean
				
fclean:			
				$(RM) cub3D cub3D_bonus libft.a libmlx.a src/gnl/get_next_line_utils.o src/gnl/get_next_line.o
				$(MAKE) -C src/libft fclean
				$(MAKE) -C mlx/minilibx_opengl_custom clean

re:				fclean $(NAME)

bonus:			$(BONUSE_NAME)

.PHONY:			all clean fclean re