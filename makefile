

run: build
	#./main | sox -t raw -r 44100 -e signed -b 16 -c 1 - -d
	./main | nc 192.168.178.39 5000

HOST=192.168.178.39 
send: build
	./main | nc $(HOST) 5000

#ncat because of fucking win10 scoop, fuck you microsoft
receive:
	ncat -l 5000 | ffplay -f s16le -ar 16k -ac 1 -


build: main.c
	gcc main.c -o main -lm -g

