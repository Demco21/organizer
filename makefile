organizer: main.o utils.o videos.o music.o documents.o
	gcc main.o utils.o videos.o music.o documents.o -o organizer

main.o: main.c
	gcc -c main.c

utils.o: utils.c
	gcc -c utils.c

videos.o: videos.c
	gcc -c videos.c

music.o: music.c
	gcc -c music.c

documents.o: documents.c
	gcc -c documents.c

clean:
	rm -f *.o core
