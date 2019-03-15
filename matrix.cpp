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
    std::vector<std::vector<int> > A(n);
    for (int i = 0; i < n; i++)
    {
      A[i].resize(n);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	fs >> A[i][j];

    std::cout << "A = [" << std::endl;
    std::vector<std::vector<int> >::iterator row_iterator = A.begin();
    std::vector<std::vector<int> >::iterator row_end = A.end();
    for (; row_iterator != row_end; ++row_iterator)
    {
      std::vector<int>::iterator ele_iterator = row_iterator->begin();
      std::vector<int>::iterator ele_end = row_iterator->end();
      for (; ele_iterator != ele_end; ++ele_iterator)
	std::cout << *ele_iterator << " ";
      std::cout << "\b" << std::endl;
    }
    std::cout << "]" << std::endl;
    fs.close();
    return 0;
};
