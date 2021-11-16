# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 15:10:53 by pthomas           #+#    #+#              #
#    Updated: 2021/11/16 15:06:30 by pthomas          ###   ########lyon.fr    #
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
PATH_LIBFT	=	libft/
PATH_OBJ	=	obj/

#~~~~ Files ~~~~#

SRC			=	main.c \
				init.c \
				operations.c \
				sort.c \
				utils.c \
				hundred.c \
				thousand.c

BSRC		=	checker.c \
				init.c \
				operations.c

OBJ			=	$(addprefix $(PATH_OBJ), $(SRC:.c=.o))
BOBJ		=	$(addprefix $(PATH_OBJ), $(BSRC:.c=.o))

INC			=	$(addprefix $(PATH_INC), push_swap.h)

LIB			=	$(PATH_LIBFT)libft.a

#~~~~ Macros ~~~~#

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INCLUDES	=	-I $(PATH_INC) -I $(PATH_LIBFT)$(PATH_INC)
RM			=	rm -rf

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all :			lib $(PUSH_SWAP)

$(PUSH_SWAP) :	$(OBJ) $(LIB)
				$(CC) $(CFLAG) $(OBJ) $(LIB) -o $@ $(INCLUDES)

bonus :			lib $(BOBJ) $(LIB)
				$(CC) $(CFLAG) $(BOBJ) $(LIB) -o $(CHECKER) $(INCLUDES)

lib :		
				$(MAKE) -C $(PATH_LIBFT)

re :			fclean all

#~~~~ Compilation Rules ~~~~#

$(PATH_OBJ)%.o :	%.c $(INC)
					@ mkdir -p $(PATH_OBJ)
					$(CC) $(CFLAG) -c $< -o $@ $(INCLUDES)

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
