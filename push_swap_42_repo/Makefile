# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:56:49 by mbernard          #+#    #+#              #
#    Updated: 2024/02/09 15:36:05 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP 
RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p

# ---------------------------------- Sources ----------------------------------#
vpath %.c src src/checking	src/commands	src/sort	src/utils

SRCS = push_swap	push_into_b					\
       swap	push	rotate	reverse					\
       calculs	combined	search_assign	fill_pile		\
       check	one_arg_check	ft_split_set				\
       utils	list_utils	sort_utils	swap_utils		\
       sort_three

# ---------------------------------- Repertories ----------------------------- #
OBJS_DIR = .objs/
LIBFT_DIR = Libft/
HEADER_DIR = header/
INCLUDES = -I ${HEADER_DIR}
DEPS = ${OBJS:.o=.d}
# ---------------------------------- Addpredix and suffix -------------------- #
LIBFT = $(addprefix ${LIBFT_DIR}, libft.a)
HEADER = $(addprefix ${HEADER_DIR}, push_swap.h)
OBJS = $(addprefix ${OBJS_DIR}, $(addsuffix .o, ${SRCS}))
 
# ---------------------------------- Compilation ----------------------------- #
all:	${NAME}

libs:
	$(MAKE) -C ${LIBFT_DIR}

${LIBFT}: libs

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o $@

${OBJS_DIR}%.o: %.c ${HEADER} | ${OBJS_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

-include ${DEPS}

# ---------------------------------- Create Repertory ---------------------- #
${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}

# ---------------------------------- Clean ----------------------------------- #
clean:
	${RMDIR} ${OBJS_DIR}
	${MAKE} clean -C $(LIBFT_DIR)

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBFT}

re:    fclean
	${MAKE} ${NAME}

# ---------------------------------- Phony ----------------------------------- #
.PHONY: all libs clean fclean re
