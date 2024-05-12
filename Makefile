NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = 	helpers.c \
		utils.c \
		outils.c \
		p_s_helpers.c \
		more_than_5_helpers.c \
		pa_pb.c \
		rr_ra_rb.c \
		rrr_rra_rrb.c \
		ss_sa_sb.c \
		sort_2.c \
		sort_3.c \
		sort_4.c \
		sort_5.c \
		sort_more_than_5.c \
		push_swap.c \

OBJS = $(SRC:.c=.o)

BSRCS = p_s_helpers.c \
		helpers.c \
		utils.c \
		outils.c \
		pa_pb.c \
		rr_ra_rb.c \
		rrr_rra_rrb.c \
		ss_sa_sb.c \
		more_than_5_helpers.c \
		get_next_line.c \
      	get_next_line_utils.c \
		ps_bonus.c

BOBJS = $(BSRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(NAME_BONUS)


$(NAME_BONUS): $(BOBJS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean
	make all

.SECONDARY: