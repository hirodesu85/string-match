

mainNaive: cmp.o naive.o readFile.o

mainKMP: compnext.o readFile.o

clean:
	rm -f *.o mainNaive
