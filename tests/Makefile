# SAR Library makefile

all:
	gcc-5 tests.c -o tests.out -I/usr/local/include/ -L/Users/thomasguyot/libascii -lsar

cpp:
	g++-5 tests.cpp -o testscpp.out -I/usr/local/include/ -L/Users/thomasguyot/libascii -lsar

mingc: # gotta link static lib libsdlmain.a for -lSDL2main. The other functions are in the dlls
	gcc -std=c11 tests.c -o testc.exe -IC:\libs\SDL2\include -IC:\libs\SDL2_image\i686-w64-mingw32\include\SDL2 -IC:\c_stuff\SAR -L. -lsar -LC:\libs\SDL2\lib\x86 -lSDL2main -lSDL2 -lSDL2_image

clean:
	rm *.out *.exe
