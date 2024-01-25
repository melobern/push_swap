# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:56:49 by mbernard          #+#    #+#              #
#    Updated: 2024/01/25 09:57:40 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
JUSTC="\n NO FSANITIZE HERE ! DON'T FORGET TO CUT THE CRAP FROM MAKEFILE !\n"
FSAN="\n\n\nOOOH ! It seems you're FSANITIZING again !\n"
CC = echo ${JUSTC} && cc -g3
#CC = echo ${FSAN} && cc -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -MMD -MP 
RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p
SRCS = utils	one_arg_check	push_swap	check	ft_split_set	number_list	swap

# ---------------------------------- Repertories ----------------------------- #
SRCS_DIR = src_push_swap/
OBJS_DIR = .objs/
LIBFT_DIR = Libft/
HEADER_DIR = header/
INCLUDES = -I ${HEADER_DIR}
DEPS = ${${SRCS_DIR}%.c:${OBJS_DIR}%.d}
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
