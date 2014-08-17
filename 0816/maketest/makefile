./bin/main.exe: ./src/main.o ./src/div.o ./src/sub.o ./src/add.o ./src/mul.o
	gcc -o ./bin/main.exe ./src/main.o ./src/div.o ./src/mul.o ./src/add.o ./src/sub.o -I ./include

./src/main.o: ./src/main.c ./include/func.h
	gcc -c ./src/main.c -o ./src/main.o -I ./include
./src/div.o: ./src/div.c ./include/func.h
	gcc -c ./src/div.c -o ./src/div.o -I ./include
./src/mul.o: ./src/mul.c ./include/func.h
	gcc -c ./src/mul.c -o ./src/mul.o -I ./include
./src/add.o: ./src/add.c ./include/func.h
	gcc -c ./src/add.c -o ./src/add.o -I ./include
./src/sub.o: ./src/sub.c ./include/func.h
	gcc -c ./src/sub.c -o ./src/sub.o -I ./include
