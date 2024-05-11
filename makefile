NAME			= miniRT

FILE_PATH		= ./src
OBJS_PATH		= ./obj
LIBFT_PATH		= ./lib/libft

HEADERS			= inc/minirt.h

LIBFT			= $(LIBFT_PATH)/libft.a

FILES			= \
				main.c 					\
				camera.c 				\
				color.c 				\
				color_conversion.c				\
				file_handling.c				\
				material.c				\
				matrix.c				\
				matrix_determinant.c				\
				matrix_transform.c				\
				matrix_transform_rotation.c				\
				object.c				\
				object_processing.c				\
				parsing_utilities.c				\
				pattern_at.c				\
				pattern.c				\
				pixel_color_definition.c				\
				ray.c				\
				render.c				\
				scene_light.c				\
				scene_processing.c				\
				shape.c				\
				shape_discriminant_aux.c				\
				shape_discriminant.c				\
				shape_map.c				\
				shape_normal_at.c				\
				shape_set.c				\
				tuple.c				\
				tuple_comparison.c				\
				tuple_operation_advanced.c				\
				tuple_operation_basic.c


IFLAGS			= -I./lib/libft
LFLAGS			= -L./lib/libft
CFLAGS			= -Wall -Wextra -Werror -g
LD_LIBS 		= -lmlx -lXext -lX11 -lft -lm

CC				= gcc
RM				= rm -rf

OBJS			= $(addprefix $(OBJS_PATH)/, $(FILES:.c=.o))

all:			$(NAME)
$(NAME):		$(LIBFT) $(OBJS_PATH) $(OBJS)
				@$(CC) $(OBJS) $(LFLAGS) $(LD_LIBS) -o $(NAME)
				@echo "MiniRT created!!"

$(OBJS_PATH):
				@mkdir -p $(OBJS_PATH)


$(OBJS_PATH)/%.o: $(FILE_PATH)/%.c $(HEADERS)
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
				@make -C $(LIBFT_PATH)

clean:
				@$(RM) $(OBJS)
				@rm -rf $(OBJS_PATH)
				@echo "clean Done!"

fclean:			clean
				@make -C $(LIBFT_PATH) fclean
				@$(RM) $(NAME) $(OBJS_PATH)
				@echo "fclean Done!"

re:				fclean all

.PHONY: 		all clean fclean re

VALGRIND 		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --trace-children=yes --suppressions=readline.supp --log-file=valgrind-out.txt -s

valgrind:
	$(VALGRIND) ./minirt
