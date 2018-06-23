a.out: a.o
	cc -o a.out a.o -lpthread
a.o : pthread_example.cpp
	cc -c pthread_example.cpp -o a.o
clean:
	rm a.*
