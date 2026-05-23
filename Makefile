CC     := gcc
CFLAGS := -Wall -Wextra -Werror -I./include

TESTS  := $(patsubst test/%.c, %, $(wildcard test/test_*.c))

all: $(TESTS)

test_%: test/test_%.c
	@$(CC) $(CFLAGS) $< $(wildcard src/$(subst test_,,$*)/*.c) -o $@
	@./$@

clean:
	@rm -f $(TESTS)

.PHONY: all clean