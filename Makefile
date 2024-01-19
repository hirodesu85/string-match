mainNaive: cmp.o naive.o readFile.o

mainKMP: cmp.o compnext.o kmp.o readFile.o

clean:
	rm -f *.o mainNaive mainKMP
