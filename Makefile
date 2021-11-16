# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 15:10:53 by bmangin           #+#    #+#              #
#    Updated: 2021/11/16 13:42:21 by dev              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#========================================#
#=============== VARIABLES ==============#
#========================================#

#~~~~ Output ~~~~#

PUSH_SWAP	= push_swap
CHECKER		= checker

#~~~~ Paths ~~~~#

VPATH		=	src/
PATH_INC	=	include/
PATH_OBJ	=	obj/
PATH_LIBFT	=	libft/

#~~~~ Files ~~~~#

SRCS		=	main.c \
				init.c \
				operations.c \
				sort.c \
				utils.c \
				hundred.c \
				thousand.c

BSRCS		=	checker.c \
				init.c \
				operations.c

OBJ			=	$(addprefix $(PATH_OBJ), $(SRCS:.c=.o))
BOBJ		=	$(addprefix $(PATH_OBJ), $(BSRCS:.c=.o))

INC			=	$(addprefix $(PATH_INC), push_swap.h)

#~~~~ Macros ~~~~#

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
LIB			=	$(PATH_LIBFT)libft.a

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all :			lib $(PUSH_SWAP)

$(PUSH_SWAP) :	$(OBJ) $(LIB)
				$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@ -I $(PATH_INC)

bonus :			libs $(BOBJ) $(LIB)
				$(CC) $(CFLAGS) $(BOBJ) $(LIB) -o $(CHECKER) -I $(PATH_INC)

lib :		
				$(MAKE) -C $(PATH_LIBFT)

re :			fclean all

#~~~~ Compilation Rules ~~~~#

$(PATH_OBJ)%.o :	%.c $(INC)
					@ mkdir -p $(PATH_OBJ)
					$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INC)

#~~~~ Cleaning Rules ~~~~#

clean :
				$(MAKE) clean -C $(PATH_LIBFT)
				$(RM) $(PATH_OBJ)

fclean :		
				$(MAKE) fclean -C $(PATH_LIBFT)
				$(RM) $(PATH_OBJ) $(PUSH_SWAP) $(CHECKER)

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
								  
.PHONY:		all lib clean fclean re eugene
