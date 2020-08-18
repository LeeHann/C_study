all : ex01 ex01_run

ex01 : ex01.c
	gcc -g -o ../out/$@ $^
ex01_run :
	../out/ex01.exe

ex02 : ex02.c ../engine/core.c 
	gcc -g -o ../out/$@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

mapTool-3 : mapTool-3.c ../engine/core.c ../engine/tile.c
	gcc -g -o ../out/$@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
