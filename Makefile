# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:56:49 by mbernard          #+#    #+#              #
#    Updated: 2023/11/30 15:24:02 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -MMD -MP 
RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p
SRCS = push_swap	check	

# ---------------------------------- Repertories ----------------------------- #
SRCS_DIR = src_push_swap/
OBJS_DIR = .objs/
LIBFT_DIR = Libft/
HEADER_DIR = header/
INCLUDES = -I ${HEADER_DIR}
DEPS = ${SRCS_DIR%.c:OBJS_DIR%.d}

# ---------------------------------- Addpredix and suffix -------------------- #
LIBFT = $(addprefix ${LIBFT_DIR}, libft.a)
HEADER = $(addprefix ${HEADER_DIR}, push_swap.h)
OBJS = $(addprefix ${OBJS_DIR}, $(addsuffix .o, ${SRCS}))
 
# ---------------------------------- Compilation ----------------------------- #
all: libs ${NAME}

libs :
	$(MAKE) -C ${LIBFT_DIR}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o $@

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER} | ${OBJS_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

-include ${DEPS}

# ---------------------------------- Create Repertory ---------------------- #
${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}

# ---------------------------------- Clean ----------------------------------- #
clean:
	${RMDIR} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re:    fclean
	${MAKE} ${NAME}

# ---------------------------------- Phony ----------------------------------- #
.PHONY: all libs clean fclean re
