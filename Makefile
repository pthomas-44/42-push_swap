# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 15:10:53 by bmangin           #+#    #+#              #
#    Updated: 2021/11/16 00:13:21 by dev              ###   ########lyon.fr    #
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
PATH_INCS	=	include/
PATH_OBJS	=	obj/
PATH_LIBFT	=	libft/

#~~~~ Sources ~~~~#

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

#~~~~ Objects ~~~~#

OBJS		=	$(addprefix $(PATH_OBJS), $(SRCS:.c=.o))
BOBJS		=	$(addprefix $(PATH_OBJS), $(BSRCS:.c=.o))

#~~~~ Includes ~~~~#

INCS		=	$(addprefix $(PATH_INCS), push_swap.h)

#~~~~ Macros ~~~~#

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIBS		=	$(PATH_LIBFT)libft.a
RM			=	rm -f

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all :			libs $(PUSH_SWAP)

$(PUSH_SWAP) :	$(OBJS) $(LIBS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@ -I $(PATH_INCS)

bonus :			libs $(BOBJS) $(LIBS)
				$(CC) $(CFLAGS) $(BOBJS) $(LIBS) -o $(CHECKER) -I $(PATH_INCS)

libs :		
				$(MAKE) -C $(PATH_LIBFT)

re :			fclean all

#~~~~ Compilation Rules ~~~~#

$(PATH_OBJS)%.o :	%.c $(INCS)
					@ mkdir -p $(PATH_OBJS)
					$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCS)

#~~~~ Cleaning Rules ~~~~#

clean :
				$(MAKE) clean -C $(PATH_LIBFT)
				$(RM) -r $(PATH_OBJS)

fclean :		
				$(MAKE) fclean -C $(PATH_LIBFT)
				$(RM) -r $(PATH_OBJS) $(PUSH_SWAP) $(CHECKER)

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
								  
.PHONY:		all libs clean fclean re eugene
