
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/basicQuadtree

SRC= main.c buildTree.c writeTree.c reduceTree.c

# generic build details

CC=      gcc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c treeStructure.h buildTree.h writeTree.h reduceTree.h
buildTree.o: buildTree.c buildTree.h treeStructure.h
writeTree.o: writeTree.c writeTree.h treeStructure.h
reduceTree.o: reduceTree.c reduceTree.h treeStructure.h

