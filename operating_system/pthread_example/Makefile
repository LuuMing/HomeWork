num = 0
eg0 = pthread_example_$(num)
$(eg0): $(eg0).o
	cc -o $(eg0) $(eg0).o -lpthread
$(eg0).o : $(eg0).cpp
	cc -c $(eg0).cpp -o $(eg0).o
clean:
	rm `ls *|egrep -v '*.cpp' | egrep -v 'Makefile'`
