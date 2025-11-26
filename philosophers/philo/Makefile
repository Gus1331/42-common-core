CC = cc
INCLUDE = -I ./includes
FLAGS = -Wall -Wextra -Werror $(INCLUDE)
NAME = philo

SRC = philosophers.c \
	src/ft_atoi.c \
	src/init_data.c \
    src/get_time.c \
    src/routine.c \
    src/check.c

OBJDIR = objects
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Colors
ESC = \033[
RESET = $(ESC)0m
BOLD = $(ESC)1m
GREEN = $(ESC)32m
YELLOW = $(ESC)33m
BLUE = $(ESC)34m
MAGENTA = $(ESC)35m
CYAN = $(ESC)36m
WHITE = $(ESC)37m

$(NAME) : format $(OBJ)
	@$(CC) $(FLAGS)  $(OBJ) -o $@
	@echo "\n"

$(OBJDIR)/%.o: %.c 
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(call show_progress,$<)

all : $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "$(YELLOW)🧹 .o files cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(BOLD)🧹 $(NAME)$(RESET)$(YELLOW) cleaned\n$(RESET)"

re: fclean all

format:
	@echo "\n made by: gustaoli 2025\n"

.PHONY: all re fclean clean format

# **************************************************************************** #
# Detect terminal width and adjust behavior
# **************************************************************************** #
TERM_WIDTH := $(shell tput cols 2>/dev/null || echo 80)
SAFE_WIDTH := $(shell echo $$(($(TERM_WIDTH) - 10)))
PROGRESS_WIDTH := $(shell echo $$(($(SAFE_WIDTH) > 50 ? 30 : $(SAFE_WIDTH) - 20)))

# **************************************************************************** #
# Define the progress bar and verbose output functions - CLEAN & SIMPLE
# **************************************************************************** #
TOTAL_FILES := $(words $(SRC))
COMPILED_COUNT = 0
VERBOSE ?= 0

define show_progress
    @$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT)+1))))
    @$(eval SHORT_PATH=$(shell echo $(1) | sed 's|^.*/||'))
    @$(eval PERCENT=$(shell echo $$(($(COMPILED_COUNT)*100/$(TOTAL_FILES)))))
    @$(eval BAR_SIZE=20)
    @$(eval BARS=$(shell echo $$(($(COMPILED_COUNT)*$(BAR_SIZE)/$(TOTAL_FILES)))))
    @$(eval REMAINING=$(shell echo $$(($(BAR_SIZE) - $(BARS)))))
    @$(eval PROGRESS=$(shell printf '█%.0s' $$(seq 1 $(BARS))))
    @$(eval EMPTY=$(shell printf '░%.0s' $$(seq 1 $(REMAINING))))

    @if [ $(VERBOSE) -eq 1 ]; then \
        echo "$(CYAN)$(BOLD)📄  Compiling $(RESET)$(CYAN)$(SHORT_PATH)$(RESET) ($(COMPILED_COUNT)/$(TOTAL_FILES))"; \
    else \
        printf "\r\033[K$(YELLOW)$(BOLD)🔄  $(RESET)$(GREEN)$(PROGRESS)$(WHITE)$(EMPTY)$(RESET) $(PERCENT)%% $(CYAN)$(SHORT_PATH)$(RESET)"; \
        if [ $(COMPILED_COUNT) -eq $(TOTAL_FILES) ]; then \
            printf "\n$(GREEN)$(BOLD)\n ✅✅✅ $(NAME) OK ✅✅✅$(RESET)\n\n"; \
        fi; \
    fi
endef
