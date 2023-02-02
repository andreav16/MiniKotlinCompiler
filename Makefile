TARGET=mini-kotlin
all: ${TARGET}

${TARGET}: ${TARGET}_lexer.o main.o
	g++ -g -o $@ $^

main.o: main.cpp
	g++ -g -c -o $@ $<

${TARGET}.o: ${TARGET}_lexer.cpp
	g++ -g -c -o $@ $<

${TARGET}_lexer.cpp: ${TARGET}.l
	flex -o $@ $<

clean:
	rm -f *.o
	rm -f ${TARGET}_lexer.cpp
	rm -f ${TARGET}