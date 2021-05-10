compRecMS: main.o merge.o mergeSort_recursive.o
		gcc main.o merge.o mergeSort_recursive.o -o recuriveMerge

compIterMS: main.o merge.o mergeSort_iterative.o
		gcc main.o merge.o mergeSort_iterative.o -o iterativeMerge

runRecMS: compRecMS
	./recursiveMerge

runIterMS: compIterMS
	./iterativeMerge

main.o: main.c
	gcc -c main.c

mergeRec.o: mergeSort_recursive.c merge.h
	gcc -c mergeSort_recursive.c

mergeIter.o: mergeSort_iterative merge.h
 	gcc -c mergeSort_iterative

merge.o: merge.c
	gcc -c merge.c

comparer.o : compare.c
	gcc -c compare.c

compare : compare.o merge.o mergeSort_recursive.o mergeSort_iterative.o
	gcc compare.o mergeSort_recursive.o mergeSort_iterative.o merge.o -o compareMerge