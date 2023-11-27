all: server client

server: server.c
	gcc -Wall -pedantic -std=c99 -o server server.c

client: client.c
	gcc -Wall -pedantic -std=c99 -o client client.c

clean:
	rm server client
