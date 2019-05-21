main: PizzaOrder.o stdafx.o 
    gcc -o main PizzaOrder.o stdafx.o

PizzaOrder.o: PizzaOrder.cpp 

stdafx.o: stdafx.cpp stdafx.h

clean:
    rm main PizzaOrder.o stdafx.o *.o
