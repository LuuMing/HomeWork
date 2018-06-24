
src=$(shell ls *.c)
src=$(wildcard *.c)
a.out:$(src)
	gcc $(src) -lpthread -o a.out 
clean:
	rm `ls | egrep -v '*.cpp' | egrep -v 'Makefile'| egrep -v '*.c'`
