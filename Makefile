CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -I./include

TEST_FILE := $(wildcard test/test_*.c)
TEST      := $(patsubst test/%.c, %, $(TEST_FILE))
all: $(TESTS)

test_%: test/test_%.c
	@$(CC) $(CFLAGS) $< $(wildcard src/$*/*.c) -o $@
	@./$@
	@rm -f $@

clean:
	@rm -f $(TESTS)

.PHONY: all clean