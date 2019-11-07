source = $(wildcard *.cpp)
object = $(patsubst %.cpp, %.o, $(source))

main: $(object)
	g++ -o $@ $(object)

%.o : %.cpp
	g++ -c $<

debug: $(source)
	g++ -o main $(source) -g

clean:
	rm *.o main test *.exe html latex -fr
