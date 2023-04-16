NAME = libftprintf.a
OBJS = ft_printf_internal_d.o ft_printf_internal_percent.o ft_printf_internal_x.o ft_printf_internal_assign.o ft_printf_internal_i.o ft_printf_internal_c.o ft_printf.o ft_printf_internal_dummy.o ft_printf_internal_uppercase_x.o ft_printf_internal_u.o ft_printf_internal.o ft_printf_internal_step.o ft_printf_internal_p.o ft_printf_internal_normal.o ft_printf_internal_format.o ft_printf_internal_s.o

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -O

all: $(NAME)
.PHONY: all

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(AR) cr $@ $^
