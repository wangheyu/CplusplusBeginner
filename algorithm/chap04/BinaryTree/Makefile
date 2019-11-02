object = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

main: $(object)
	g++ -o $@ $(object)

%.o : %.cpp
	g++ -c $<

clean:
	rm *.o main test *.exe html latex -fr
