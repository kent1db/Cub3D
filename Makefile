# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 18:04:39 by qurobert          #+#    #+#              #
#    Updated: 2021/02/18 10:24:14 by qurobert         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = 		cub3D
FILES =		parse.c error.c fill_struct.c color.c utils.c texture.c check.c\
			raycasting.c move.c camera.c init_raycasting.c input.c open_txt.c\
			tool.c sprite.c init_sprite.c compass.c shade.c bmp.c init.c
INC_FILES = cub.h
INC_PATH = ./includes/
SRC_PATH = ./srcs/
INC 	= 	$(addprefix ${INC_PATH},${INC_FILES})
SRC = 		$(addprefix ${SRC_PATH},${FILES})
CC = 		clang
OBJ = 		${SRC:.c=.o}
FLAGS = 	-Wall -Wextra -Werror -g

all: 		$(NAME)

lib:
		@make -C ./libft
		@make -C ./minilibx
		@cp ./libft/libft.a .
		@cp ./minilibx/libmlx.dylib .	

$(NAME): 	lib $(OBJ)
			@${CC} $(OBJ) main.c libft.a -L. libmlx.dylib -o $(NAME)
			@printf '\033[32m %s\n\033[0m'
			@printf '\033[32m %s\n\033[0m'
			@printf '\033[32m 												 %s\n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿            ____________________________       %s\n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⠛⢩⣴⣶⣶⣶⣌⠙⠫⠛⢋⣭⣤⣤⣤⣤⡙⣿⣿⣿⣿⣿⣿            !\_________________________/!\\     %s\n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⡟⢡⣾⣿⠿⣛⣛⣛⣛⣛⡳⠆⢻⣿⣿⣿⠿⠿⠷⡌⠻⣿⣿⣿⣿            !!                         !! \\    %s\n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⠏⣰⣿⣿⣴⣿⣿⣿⡿⠟⠛⠛⠒⠄⢶⣶⣶⣾⡿⠶⠒⠲⠌⢻⣿⣿            !!                         !! \\   %s\n\033[0m'
			@printf '\033[32m⣿⣿⠏⣡⢨⣝⡻⠿⣿⢛⣩⡵⠞⡫⠭⠭⣭⠭⠤⠈⠭⠒⣒⠩⠭⠭⣍⠒⠈⠛            !! C:\> _ cd Libft          !!  !   %s\n\033[0m'
			@printf '\033[32m⡿⢁⣾⣿⣸⣿⣿⣷⣬⡉⠁⠄⠁⠄⠄⠄⠄⠄⠄⠄⣶⠄⠄⠄⠄⠄⠄⠄⠄⢀            !!                         !!  !   %s\n\033[0m'
			@printf '\033[32m⢡⣾⣿⣿⣿⣿⣿⣿⣿⣧⡀⠄⠄⠄⠄⠄⠄⠄⢀⣠⣿⣦⣤⣀⣀⣀⣀⠄⣤⣾            !! C:\> _ make              !!  !   %s\n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⡶⢇⣰⣿⣿⣟⠿⠿⠿⠿⠟⠁⣾⣿⣿            !!                         !!  !   %s\n\033[0m'
			@printf '\033[32m⣿⣿⣿⣿⣿⣿⣿⡟⢛⡛⠿⠿⣿⣧⣶⣶⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣧⠸⣿⣿            !! C:\> _ ${NAME} : CREATED !!  !   %s\n\033[0m'
			@printf '\033[32m⠘⢿⣿⣿⣿⣿⣿⡇⢿⡿⠿⠦⣤⣈⣙⡛⠿⠿⠿⣿⣿⣿⣿⠿⠿⠟⠛⡀⢻⣿            !!                         !!  /   %s\n\033[0m'
			@printf '\033[32m⠄⠄⠉⠻⢿⣿⣿⣷⣬⣙⠳⠶⢶⣤⣍⣙⡛⠓⠒⠶⠶⠶⠶⠖⢒⣛⣛⠁⣾⣿            !!_________________________!! /    %s\n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠈⠛⠛⠿⠿⣿⣷⣤⣤⣈⣉⣛⣛⣛⡛⠛⠛⠿⠿⠿⠟⢋⣼⣿⣿            !/_________________________\!/     %s\n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⠉⣻⣿⣿⣿⣿⡿⠿⠛⠃⠄⠙⠛⠿⢿⣿               __\_________________/__/!_  	  %s\n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢬⣭⣭⡶⠖⣢⣦⣀⠄⠄⠄⠄⢀⣤⣾⣿             /oooo  oooo  oooo  oooo /!    	  %s\n\033[0m'
			@printf '\033[32m⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢰⣶⣶⣶⣾⣿⣿⣿⣿⣷⡄⠄⢠⣾⣿⣿⣿            /ooooooooooooooooooooooo/ /   	  %s\n\033[0m'
			@printf '\033[32m	                                 /ooooooooooooooooooooooo/ /		  %s\n\033[0m'
			@printf '\033[32m	                                /_______________________/_/		  %s\n\033[0m'
			@printf '\033[32m %s\n\033[0m'
			
%.o: %.c 	$(INC)
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC_PATH}
			@printf '\033[32m [✓] %s\n\033[0m'  "$(notdir $<)"
			
clean:		
			@rm -f ${OBJ}
			@make clean -C ./libft
			@make clean -C ./minilibx
			@printf '\033[32m %s\n\033[0m'
			@printf '\033[33m⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀ ⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿ %s\n\033[0m' 
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀             ⠀⢸⣿⣿ %s\n\033[0m'
			@printf '\033[33m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ FILES DELETED   ⢸⣿⣿ %s\n\033[0m'
			@printf '\033[32m %s\n\033[0m'

fclean:		clean
			@rm -f ${NAME}
			@rm -f libft.a libmlx.dylib
			@cd ./libft && rm -f libft.a
			@cd ./minilibx && rm -f libmlx.dylib
			@printf '\033[31m⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀ ⣿⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿ %s\n\033[0m' 
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀             ⠀⢸⣿⣿ %s\n\033[0m'
			@printf '\033[31m⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ LIBFT.A DELETED ⢸⣿⣿ %s\n\033[0m'
			@printf '\033[32m %s\n\033[0m'
			
re:			fclean all

.PHONY: all clean fclean re lib