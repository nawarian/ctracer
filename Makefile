CC=clang

MKDIR=mkdir -p
RM=rm -rf

CFLAGS=
LFLAGS=

SRCDIR=src
BUILDDIR=build
TESTSDIR=tests

OBJS=$(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.c))

all: $(BUILDDIR) $(OBJS)

clean:
	$(RM) $(BUILDDIR)
.PHONY: clean

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $? -o $@ $(CFLAGS)

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

