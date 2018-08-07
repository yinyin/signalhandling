
CFLAGS := $(CFLAGS) -Iinclude/ -Ideps/recordlogs/include/ -Wall

BASE_CODE_FILES := \
		src/signalhandling.c \
		deps/recordlogs/src/recordlogs_stderrprintf.c

test/ignoresigint: test/ignoresigint.c $(BASE_CODE_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) test/ignoresigint
