# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:10:08 by vhaefeli          #+#    #+#              #
#    Updated: 2022/05/04 13:23:31 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


UNAME= $(shell uname -s)
ifeq ($(UNAME), Linux)
	MINILIBX_DIR	= ./miniLibX/linux
	EXT_LIBS = -lX11 -lXext -lm
else
	MINILIBX_DIR	= ./miniLibX
	EXT_LIBS += -framework OpenGL -framework AppKit -lz
endif

CFLAGS 			= -Wall -Wextra -Werror #-g -fsanitize=address -fno-omit-frame-pointer
TARGET 			= fractol
SRCS_DIR 		= ./src
OBJS_DIR 		= ./obj
LIBFT_DIR		= ./libft
MLX_TOOLS_DIR	= ./mlx_tools
INCLUDES_DIRS	= $(LIBFT_DIR) $(MINILIBX_DIR) $(MLX_TOOLS_DIR) includes
INCLUDES		= $(addprefix -I,$(INCLUDES_DIRS))
LIBS			= $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
_SRCS 			= draw.c\
					fractal.c\
					hook.c\
					keycontrol.c\
					main.c

				  
OBJS 			= $(patsubst %.c, $(OBJS_DIR)/%.o, $(_SRCS))
SRCS 			= $(patsubst %, $(SRCS_DIR)/%, $(_SRCS))
OBJS_BONUS 		= $(patsubst %.c, $(OBJS_DIR)/%.o, $(_SRCS_BONUS))

.PHONY : all clean fclean re bonus test

all: $(TARGET)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(MLX_TOOLS_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -d $(OBJS_DIR)


fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(MLX_TOOLS_DIR) fclean
	rm -f $(TARGET)

re: fclean all

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) -c $(CFLAGS) -o $@ $^ $(INCLUDES)

$(TARGET): $(MINILIBX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a $(MLX_TOOLS_DIR)/mlx_tools.a $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES) -L$(MINILIBX_DIR) \
		-lmlx $(EXT_LIBS) $(LIBFT_DIR)/libft.a

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -sC $(MINILIBX_DIR)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -sC $(LIBFT_DIR) bonus

$(MLX_TOOLS_DIR)/mlx_tools.a:
	$(MAKE) -sC $(MLX_TOOLS_DIR)

bonus: $(TARGET)



