##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SRC		=	 sources/

SRC_C	=	my_printf.c				\
			func_pointer.c			\
			func_c.c				\
			func_cb.c				\
			func_ce.c				\
			func_cg.c				\
			func_cs.c				\
			func_cx.c				\
			func_e.c				\
			func_f.c				\
			func_g.c				\
			func_o.c				\
			func_p.c				\
			func_s.c				\
			func_u.c				\
			func_x.c				\
			func_id.c				\
			func_module.c			\
			func_minous_plus.c		\
			my_put_nbr.c			\
			my_putstr.c				\
			my_putchar.c			\
			my_revstr.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

OBJ	= 	$(SRCS_C:.c=.o) ##Quitar los .c

NAME	=	libmy.a  ##Nombre archivo

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

all:	$(NAME)

copy:   $(COPY)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all