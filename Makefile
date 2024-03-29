##
## EPITECH PROJECT, 2023
## Libmy
## File description:
## Makefile for my printf
##

# ↓ Basic variables
CC := gcc -std=gnu11
CFLAGS := -W -Wall -Wextra -Wunused -Wpedantic
CFLAGS += -Wundef -Wshadow -Wcast-align
CFLAGS += -Wstrict-prototypes -Wmissing-prototypes
CFLAGS += -Waggregate-return -Wcast-qual
CFLAGS += -Wunreachable-code
CFLAGS += -U_FORTIFY_SOURCE
CFLAGS += -iquote ./include

# ↓ Tests flags
COVERAGE_FLAGS := -g3 --coverage
TESTS_FLAGS := $(COVERAGE_FLAGS) -lcriterion
CFLAGS += $(TESTS_FLAGS)

# ↓ Asan
ASAN_FLAGS := -fsanitize=address,leak,undefined -g3

# ↓ Binaries
TEST_NAME := unit_tests
ASAN_NAME := asan

# Libmy
LIBMY := lib/libmy.a
CFLAGS += -L./$(dir $(LIBMY)) -lmy

# Source files
VPATH := .
VPATH += tests
SRC := test_int.c
SRC += test_char.c
SRC += test_string.c
SRC += test_purcent.c
SRC += test_octal.c
SRC += test_unsigned.c
SRC += test_hexa_min.c
SRC += test_hexa_maj.c
SRC += test_pointer.c
SRC += test_len.c
SRC += test_padding.c
SRC += test_float.c

# ↓ Objects
BUILD_DIR := .build
OBJ := $(SRC:%.c=$(BUILD_DIR)/source/%.o)
ASAN_OBJ := $(SRC:%.c=$(BUILD_DIR)/asan/%.o)

# ↓ Dependencies for headers
DEPS_FLAGS := -MMD -MP
DEPS := $(OBJ:.o=.d)

DIE := exit 1
# ↓ Colors
ECHO := echo -e
C_RESET := \033[00m
C_BOLD := \e[1m
C_RED := \e[31m
C_GREEN := \e[32m
C_YELLOW := \e[33m
C_BLUE := \e[34m
C_PURPLE := \e[35m
C_CYAN := \e[36m

all: $(LIBMY)

.PHONY: all

# ↓ Compiling libmy
$(LIBMY):
	@ $(MAKE) -s -C $(dir $(LIBMY))/my

libmy: $(LIBMY)

.PHONY: libmy

# ↓ Compiling
$(BUILD_DIR)/source/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CC${C_RESET}] $^"
	@ $(CC) -o $@ -c $< $(CFLAGS) $(DEPS_FLAGS) || $(DIE)

$(TEST_NAME): $(LIBMY) $(OBJ)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}CC${C_RESET}] ${C_GREEN}$@${C_RESET}"
	@ $(CC) -o $@ $(OBJ) $(CFLAGS) || $(DIE)

tests_run: fclean $(TEST_NAME)
	@ ./$(TEST_NAME)

.PHONY: unit_tests tests_run

# ↓ Asan
$(BUILD_DIR)/asan/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CC${C_RESET}] $^"
	@ $(CC) -o $@ -c $< $(CFLAGS) $(DEPS_FLAGS) || $(DIE)

$(ASAN_NAME): CFLAGS += $(ASAN_FLAGS)
$(ASAN_NAME): $(LIBMY) $(ASAN_OBJ)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}CC${C_RESET}] ${C_GREEN}$@${C_RESET}"
	@ $(CC) -o $@ $(ASAN_OBJ) $(CFLAGS) || $(DIE)

tests_asan: fclean $(ASAN_NAME)
	@ ./$(ASAN_NAME)

.PHONY: tests_asan

# ↓ Cleaning
clean:
	@ $(RM) -r $(BUILD_DIR)

fclean: clean
	@ $(RM) $(TEST_NAME) $(ASAN_NAME)
	@ $(MAKE) -s -C $(dir $(LIBMY))/my fclean

.PHONY: clean fclean

re: fclean all

.PHONY: re

-include $(DEPS)
