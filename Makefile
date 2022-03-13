CFLAGS = -Wall -Werror -g -I

OBJS = c_beautifier.o

EXEC = c_beautifier

$(EXEC): $(OBJS)
    gcc $(OBJS) -o $(EXEC)
  
clean:
    rm -f $(OBJS) $(EXEC)

run: $(EXEC)
    ./(EXEC)
