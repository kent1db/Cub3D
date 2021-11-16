# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 18:04:39 by qurobert          #+#    #+#              #
#    Updated: 2021/02/16 16:10:51 by qurobert         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a
FILES =		ft_isalpha.c ft_strlen.c ft_isdigit.c\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c\
			ft_strnstr.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c\
			ft_memccpy.c ft_memmove.c ft_strdup.c ft_memchr.c ft_memcmp.c\
			ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
			ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			ft_swap.c ft_rev_int_tab.c ft_sort_int_tab.c\
			ft_putnbr_base_fd.c ft_atoi_base.c ft_itoa_base.c\
			ft_sort_string_tab.c ft_advanced_sort_string_tab.c\
			ft_swap_str.c ft_whitespace.c ft_check_error.c\
			ft_reverse_string.c get_next_line.c get_next_line_utils.c\
			ft_printf.c parse.c utils.c char.c string.c adress.c int.c\
			unsigned.c hexa.c convert.c percent.c ft_power.c ft_sqrt.c
			
INC_PATH = ./includes/
SRC_PATH = ./srcs/
SRC = 		$(addprefix ${SRC_PATH},${FILES})
CC = 		gcc
OBJ = 		${SRC:.c=.o}
FLAGS = 	-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@ar rcs $(NAME) $(OBJ)
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
			

%.o: %.c $(INC_PATH)libft.h
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC_PATH}
			@printf '\033[32m [✓] %s\n\033[0m'  "$(notdir $<)"
			
clean:		
			@rm -f ${OBJ}
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
