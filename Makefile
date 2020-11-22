CC=gcc
AR=ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS= -Wall -g

all: mains #maind
mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
# maind: $(OBJECTS_MAIN) libmyBank.so
# 	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so
libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs -o libmyBank.a $(OBJECTS_LIB)
# libmyBank.so: $(OBJECTS_LIB)
# 	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all
clean:
	rm -f *.o *.a *.so mains
#rm -f *.o *.a *.so mains maind