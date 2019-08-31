main: main.cpp initial_interface_list.o initial_interface_para.o
	g++ -o main main.cpp initial_interface_list.o initial_interface_para.o
initial_interface_list.o: initial_interface_list.cpp
	g++ -c initial_interface_list.cpp
initial_interface_para.o:
	g++ -c initial_interface_para.cpp
debug: main.cpp initial_interface_para.cpp initial_interface_list.cpp
	g++ -g -o main main.cpp initial_interface_list.cpp initial_interface_para.cpp
clean:
	rm *.o
	rm main
