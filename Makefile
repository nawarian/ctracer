CC=clang

MKDIR=mkdir -p
RM=rm -rf

CFLAGS=
LFLAGS=

SRCDIR=src
BUILDDIR=build
TESTSDIR=tests
BIN=ctracer

OBJS=$(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
TOBJS=$(patsubst $(TESTSDIR)/%.c,$(BUILDDIR)/%_test.o, $(wildcard $(TESTSDIR)/*.c))
TBINS=$(patsubst $(TESTSDIR)/%.c,$(BUILDDIR)/%_test, $(wildcard $(TESTSDIR)/*.c))

all: $(BUILDDIR) $(OBJS)
	$(CC) $(OBJS) -o $(BUILDDIR)/$(BIN) $(LFLAGS)

test: $(BUILDDIR) $(TBINS)
	for test in $(TBINS); do \
		./$$test; \
	done

clean:
	$(RM) $(BUILDDIR)
.PHONY: clean

$(BUILDDIR)/%_test: $(BUILDDIR)/%_test.o $(BUILDDIR)/%.o
	$(CC) $? -o $@ $(LFLAGS)

$(BUILDDIR)/%_test.o: $(TESTSDIR)/%.c
	$(CC) -c $? -o $@ $(CLFAGS) -I$(SRCDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $? -o $@ $(CFLAGS)

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

