# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 15:10:53 by bmangin           #+#    #+#              #
#    Updated: 2021/09/09 13:48:13 by pthomas          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#========================================#
#=============== VARIABLES ==============#
#========================================#

#~~~~ Output ~~~~#

NAME		= push_swap

#~~~~ Paths ~~~~#

PATH_INCS	=	includes
PATH_SRCS	=	srcs
PATH_OBJS	=	objs
PATH_LIBFT	=	libft

#~~~~ Sources ~~~~#

SRCS		=	main.c \
				ft_exit.c \
				init.c \
				operations.c \
				

#~~~~ Objects ~~~~#

OBJS		=	$(addprefix $(PATH_OBJS)/, $(SRCS:.c=.o))

#~~~~ Includes ~~~~#

INCS		=	$(addprefix $(PATH_INCS)/, push_swap.h)


#~~~~ Macros ~~~~#

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIBS		=	libft.a
RM			=	rm -f

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all :		libs $(NAME)

$(NAME) :	$(OBJS) $(LIBS)
			$(CC) $(CFLAGS) -I $(INCS) $(OBJS) $(LIBS) -o $(NAME)

libs :		
			$(MAKE) -C $(PATH_LIBFT)
			ln -sf $(addprefix $(PATH_LIBFT)/, libft.a) .

re :			fclean all

#~~~~ Compilation Rules ~~~~#

$(PATH_OBJS)/%.o :	$(PATH_SRCS)/%.c $(INCS) $(LIBS)
					mkdir -p $(PATH_OBJS)
					$(CC) $(CFLAGS) -O3 -I $(INCS) -c $< -o $@

#~~~~ Norminette ~~~~#

norminette :
			$(MAKE) norminette -C $(PATH_LIBFT)
			norminette $(PATH_SRCS) $(PATH_BSRCS) $(PATH_INCS)

#~~~~ Cleaning Rules ~~~~#

clean :
			$(MAKE) clean -C $(PATH_LIBFT)
			$(RM) -r $(PATH_OBJS)

fclean :		
			$(MAKE) fclean -C $(PATH_LIBFT)
			$(RM) -r $(PATH_OBJS) $(NAME) $(LIBS)

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
								  
.PHONY:		all libs norminette clean fclean re eugene
