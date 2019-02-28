#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#define N 5

int main(int argc, char* argv[])
{
    // int n = std::atoi(argv[1]);
    // std::vector<int> v1(n);
    // for (int i = 0; i < n; i++)
    // 	v1[i] = std::atoi(argv[i + 2]);
    std::fstream fs;
    fs.open(argv[1]);
    
    int n;
    fs >> n;
    std::vector<int> v1(n);
    for (int i = 0; i < n; i++)
	fs >> v1[i];

    std::cout << "v = [";
    std::vector<int>::iterator v1_iterator = v1.begin();
    std::vector<int>::iterator v1_end = v1.end();
    for (; v1_iterator != v1_end; ++v1_iterator)
	std::cout << *v1_iterator << " ";
    std::cout << "\b]" << std::endl;
    fs.close();
    return 0;
};
