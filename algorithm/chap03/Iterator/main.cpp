#include <iostream>
#include <list>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> Vec(10);
    std::list<int> List(10);

    std::vector<int>::iterator Vec_iterator = Vec.begin();
    for (int i = 0; Vec_iterator != Vec.end(); ++Vec_iterator, ++i)
	*Vec_iterator = i;

    for (Vec_iterator = Vec.begin();
	 Vec_iterator != Vec.end();
	 ++Vec_iterator)
	std::cout << *Vec_iterator << "\t";
    std::cout << std::endl;

    std::list<int>::iterator List_iterator = List.begin();
    for (int i = 0; List_iterator != List.end(); ++List_iterator, ++i)
	*List_iterator = i;

    for (List_iterator = List.begin();
	 List_iterator != List.end();
	 ++List_iterator)
	std::cout << *List_iterator << "\t";
    std::cout << std::endl;
    
    return 0;
};


