git: main.o struktury.o read_write.o generator.o dijkstra.o 
	$(CC) -o graf main.o struktury.o read_write.o generator.o dijkstra.o 
plik: ../testowanie/main_test.o struktury.o read_write.o
	$(CC) -o test ../testowanie/main_test.o struktury.o read_write.o
	./test ../dane/mygraph
	rm ../testowanie/main_test.o struktury.o read_write.o test
kolejka: ../testowanie/main-kolejka.o struktury.o	
	$(CC) -o kolejka ../testowanie/main-kolejka.o struktury.o
	./kolejka
	rm ../testowanie/main-kolejka.o struktury.o kolejka	
.PHONY: clean

clean:
	-rm *.o *.out test graf
