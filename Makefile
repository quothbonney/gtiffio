CC ?= gcc
CFLAGS_BENCH ?= -std=gnu99 -O3
LFLAGS_BENCH ?= -ltiff -lpng
CFLAGS_CONV ?= -std=c99 -O3

DEPS = src/rqs.h

rqs:
	gcc -o bin/rqs src/main.c ${LFLAGS_BENCH} ${CFLAGS_BENCH} src/rqs_filesystem.c src/rqs_map.c
