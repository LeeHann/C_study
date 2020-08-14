ex01 : ex01	
	gcc -o $@ $^
ex02 : ex02.c ../engine/util.c ../engine/text_lable.c ../engine/button.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
ex03 : ex03.c ../engine/ui/text_lable.c ../engine/ui/button.c ../engine/ui/input_text.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
mapTool : mapTool.c ../engine/parser.c ../engine/tile.c
	gcc -o $@.exe $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
ex04 : ex04.c 
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
mapTool-2 : mapTool-2.c ../engine/parser.c ../engine/tile.c ../engine/ui/button.c
	gcc -o $@.exe $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf