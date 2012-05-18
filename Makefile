teste_minimax: minimax.h main.cpp connect4.o
	g++ -Wall main.cpp connect4.o -o teste_minimax

connect4.o : connect4.cpp connect4.h
	g++ -Wall -c connect4.cpp -o connect4.o