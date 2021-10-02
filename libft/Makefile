# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 08:57:58 by pthomas           #+#    #+#              #
#    Updated: 2021/06/07 19:25:01 by pthomas          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#========================================#
#=============== VARIABLES ==============#
#========================================#

#~~~~ Output ~~~~#

NAME		= libft.a

#~~~~ Paths ~~~~#

PATH_INCS	=	includes
PATH_SRCS	=	srcs
PATH_OBJS	=	objs

#~~~~ Sources ~~~~#

SRCS		=	ft_mem1.c \
				ft_mem2.c \
				ft_strinfo1.c \
				ft_strinfo2.c \
				ft_chrtype.c \
				ft_strtype.c \
				ft_num.c \
				ft_convertbase.c \
				ft_misc.c \
				ft_strmodif.c \
				ft_stralloc.c \
				ft_strjoin.c \
				ft_split.c \
				ft_put.c \
				ft_lst1.c \
				ft_lst2.c \
				get_next_line.c \
				get_next_line_utils.c \

#~~~~ Objects ~~~~#

OBJS		=	$(addprefix $(PATH_OBJS)/, $(SRCS:.c=.o))

#~~~~ HEADERS ~~~~#

INCS		= $(addprefix $(PATH_INCS)/, libft.h)

#~~~~ Macros ~~~~#

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all:		init $(NAME)

init:		$(shell mkdir -p $(PATH_OBJS))

$(NAME):	$(OBJS)
			ar rcs $(NAME) $?

#~~~~ Compilation Rule ~~~~#

$(PATH_OBJS)/%.o :	$(PATH_SRCS)/%.c  $(INCS)
					${CC} ${CFLAGS} -O3 -I $(INCS) -c $< -o $@

#~~~~ Norminette ~~~~#

norminette :
			norminette $(PATH_SRCS) $(PATH_INCS)

#~~~~ Cleaning Rules ~~~~#
		
clean:
			$(RM) -r $(PATH_OBJS)

fclean:		clean
			$(RM) $(NAME)

#~~~~ Other Rules ~~~~#

re:			fclean all

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
