.PHONY = all clean clean_deps clean_all mem_test run

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
INC += $(addprefix -I,$(dir $(DEPS)))
CFLAGS += $(INC)
LDFLAGS1 += $(addprefix -L, $(dir $(DEPS)))
LDFLAGS2 += $(patsubst lib%,-l%,$(basename $(notdir $(DEPS))))

ifeq ($(suffix $(TARGET)),.so)
	CFLAGS1 += -shared
	CFLAGS2 += -fPIC
else ifeq ($(suffix $(TARGET)),.a)

else

endif

LDFLAGS += $(LDFLAGS1) $(LDFLAGS2)

all: $(TARGET) $(END_ACTION)

$(TARGET): $(OBJ) $(DEPS) 
ifeq ($(suffix $(TARGET)),.a)
	@echo "Compiling static library"
	ar rcs $(TARGET) $^
else ifeq ($(suffix $(TARGET)),.so)
	@echo "Compiling dynamic library"
	$(CC) $(CFLAGS) $(CFLAGS1) $(OBJ) -o $@ $(LDFLAGS)
else
	@echo "Compiling program"
	$(CC) $(CFLAGS) $(CFLAGS1) $(OBJ) -o $@ $(LDFLAGS)
endif

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $(CFLAGS2) $< -o $@ $(LDFLAGS)

$(DEPS):
	$(foreach dir,$(dir $(DEPS)),make -C $(dir);)

clean:
	rm -f *.o $(TARGET)

clean_deps:
	$(foreach dir,$(dir $(DEPS)), $(MAKE) -C $(dir) clean_all;)

clean_all: clean clean_deps

mem_test: $(TARGET)
	@valgrind --leak-check=full ./$(TARGET)

run: $(TARGET)
	./$(TARGET)
