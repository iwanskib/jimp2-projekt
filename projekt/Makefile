git: main.o struktury.o read_write.o generator.o dijkstra.o bfs.o 
	$(CC) -o graf main.o struktury.o read_write.o generator.o bfs.o  dijkstra.o 
plik: ../testowanie/main_test.o struktury.o read_write.o
	$(CC) -o test ../testowanie/main_test.o struktury.o read_write.o
	./test ../dane/mygraph
	rm ../testowanie/main_test.o struktury.o read_write.o test
kolejka: ../testowanie/main-kolejka.o struktury.o	
	$(CC) -o kolejka ../testowanie/main-kolejka.o struktury.o
	./kolejka
	rm ../testowanie/main-kolejka.o struktury.o kolejka
test: ../testowanie/main-testowanie.o struktury.o dijkstra.o generator.o
	$(CC) -o testowanie ../testowanie/main-testowanie.o struktury.o dijkstra.o generator.o
	./testowanie
	rm 	../testowanie/main-testowanie.o struktury.o dijkstra.o testowanie generator.o	
.PHONY: clean

clean:
	mv *.txt ../dane
	rm *.o *.out test graf
