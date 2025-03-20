

run: build
	./main | sox -t raw -r 44100 -e signed -b 16 -c 1 - -d


build: main.c
	gcc main.c -o main -lm -g

