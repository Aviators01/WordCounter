CC = g++
EXE = WordCounter
OBJ = WordCounter.o
CFLAGS =
DEPS =

%.0 : %.cpp $(DEPS)
	$(CC) -c -o $@ $^ $(CFLAGS)

$(EXE) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE)