# AR=ar
# CC=gcc
# FLAGS= -Wall -g

# all:	connections lib.a

# #lib.so:	my_mat.o
# #	$(CC) -shared -o lib.so my_mat.o

# connections:	main.o lib.a
# 	$(CC) $(FLAGS) -o connections main.o lib.a -lm

# lib.a:	my_mat.o
# 	$(AR) -rcs lib.a my_mat.o

# main.o:	main.c my_mat.h
# 	$(CC) $(FLAGS) -c main.c

# my_mat.o:	my_mat.c my_mat.h
# 	$(CC) $(FLAGS) -c my_mat.c

# .PHONY: clean all

# clean:
# 	rm -f *.o connections *.a
