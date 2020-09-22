bin/vida: obj/util.o obj/main.o
	gcc -fsanitize=address,undefined -pthread obj/main.o obj/util.o -o $@
obj/main.o: src/main.c
	gcc -c -Wall -I include/ src/main.c -o $@

obj/util.o: src/util.c
	gcc -c -Wall -I include/ src/util.c -o $@

clean:
	rm obj/*
	rm bin/*
