all:
	gcc main.c db.c -o список
	./список
clean:
	rm -f список
