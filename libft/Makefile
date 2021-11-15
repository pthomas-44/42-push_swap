# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 08:57:58 by pthomas           #+#    #+#              #
#    Updated: 2021/11/13 22:49:00 by dev              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#========================================#
#=============== VARIABLES ==============#
#========================================#

#~~~~ Output ~~~~#

NAME		=	libft.a

#~~~~ Paths ~~~~#

VPATH		=	src/gnl/:src/mem/:src/num/:src/put/:src/str/
PATH_OBJ	=	obj/
PATH_INC	=	include/

#~~~~ Files ~~~~#

SRCS		=	get_next_line.c			\
				get_next_line_utils.c	\
				ft_bzero.c				\
				ft_calloc.c				\
				ft_free.c				\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memcpy.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_atonb.c				\
				ft_convertbase.c		\
				ft_framing.c			\
				ft_swap.c				\
				ft_put.c				\
				ft_chrtype.c			\
				ft_split.c				\
				ft_strchr.c				\
				ft_strcmp.c				\
				ft_strcpy.c				\
				ft_strdup.c				\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlen.c				\
				ft_strrev.c				\
				ft_strtrim.c			\
				ft_strtype.c			\
				ft_substr.c

OBJ			=	$(addprefix $(PATH_OBJ), $(SRCS:.c=.o))

INC			=	$(addprefix $(PATH_INC), libft.h)

#~~~~ Macros ~~~~#

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all:				$(NAME)

$(NAME):			$(OBJ)
					ar rcs $(NAME) $?

#~~~~ Compilation Rule ~~~~#

$(PATH_OBJ)%.o :	%.c $(INC)
					@mkdir -p $(dir $@);
					${CC} ${CFLAGS} -c $< -o $@ -I $(PATH_INC)

#~~~~ Cleaning Rules ~~~~#
		
clean:
					$(RM) -r $(PATH_OBJ)

fclean:				clean
					$(RM) $(NAME)

#~~~~ Other Rules ~~~~#

re:					fclean all

#~~~~ Eugene ~~~~#

eugene :	
			@ echo "               _,........__"
			@ echo "            ,-'            \"\`-."
			@ echo "          ,'                   \`-."
			@ echo "        ,'                        \\"
			@ echo "      ,'                           ."
			@ echo "      .'\\               ,\"\".       \`"
			@ echo "     ._.'|             / |  \`       \\"
			@ echo "     |   |            \`-.'  ||       \`."
			@ echo "     |   |            '-._,'||       | \\"
			@ echo "     .\`.,'             \`..,'.'       , |\`-."
			@ echo "     l                       .'\`.  _/  |   \`."
			@ echo "     \`-.._'-   ,          _ _'   -\" \\  .     \`"
			@ echo "\`.\"\"\"\"\"'-.\`-...,---------','         \`. \`....__."
			@ echo ".'        \`\"-..___      __,'\\          \\  \\     \\"
			@ echo "\\_ .          |   \`\"\"\"\"'    \`.           . \\     \\"
			@ echo "  \`.          |              \`.          |  .     L"
			@ echo "    \`.        |\`--...________.'.        j   |     |"
			@ echo "      \`._    .'      |          \`.     .|   ,     |"
			@ echo "         \`--,\\       .            \`7\"\"' |  ,      |"
			@ echo "            \` \`      \`            /     |  |      |    _,-'\"\"\"\`-."
			@ echo "             \\ \`.     .          /      |  '      |  ,'          \`."
			@ echo "              \\  v.__  .        '       .   \\    /| /              \\"
			@ echo "               \\/    \`\"\"\\\"\"\"\"\"\"\"\`.       \\   \\  /.''                |"
			@ echo "                \`        .        \`._ ___,j.  \`/ .-       ,---.     |"
			@ echo "                ,\`-.      \\         .\"     \`.  |/        j     \`    |"
			@ echo "               /    \`.     \\       /         \\ /         |     /    j"
			@ echo "              |       \`-.   7-.._ .          |\"          '         /"
			@ echo "              |          \`./_    \`|          |            .     _,'"
			@ echo "              \`.           / \`----|          |-............\`---'"
			@ echo "                \\          \\      |          |"
			@ echo "               ,'           )     \`.         |"
			@ echo "                7____,,..--'      /          |"
			@ echo "                                  \`---.__,--.'"
								  
.PHONY:		all clean fclean re
