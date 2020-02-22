compile:
	gcc -c -fpic input.c
	gcc -c -fpic primer.c
lnk:compile
	gcc -shared -o libdemo.so input.o primer.o
demo:lnk
	gcc demo.c -ldemo -L. -o main

clean:
	rm -f *.o demo *.so *.a
