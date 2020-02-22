OBJ=input.o primer.o

input.o:input.c
	gcc -c -fpic input.c
primer.o:primer.c
	gcc -c -fpic primer.c
libdemo.so:$(OBJ)
	gcc -shared -o libdemo.so $(OBJ)
demo:demo.c libdemo.so
	gcc demo.c -ldemo -L. -o main
.PHONY:clean
clean:
	rm -f *.o demo *.so *.a main
	echo $(PATH)
