A+BProblem: A+BProblem.o Debug.o
	gcc A+BProblem.o Debug.o -std=c99 -o A+BProblem -g 
A+BProblem.o: A+BProblem.c Debug.h
	gcc -c A+BProblem.c -std=c99 -o A+BProblem.o -g 
Debug.o: Debug.c Debug.h
	gcc -c Debug.c -std=c99 -o Debug.o -g
clean:
	rm A+BProblem A+BProblem.o Debug.o -f
