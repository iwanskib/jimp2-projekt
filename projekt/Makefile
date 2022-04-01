git: main.o struktury.o read_write.o generator.o dijkstra.o 
	$(CC) -o graf main.o struktury.o read_write.o generator.o dijkstra.o 
test: main_test.o struktury.o read_write.o
	$(CC) -o test main_test.o struktury.o read_write.o
	./test mygraph
	

.PHONY: clean

clean:
	-rm *.o *.out test graf
