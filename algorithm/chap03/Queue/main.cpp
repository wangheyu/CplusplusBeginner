#include <iostream>
#include <cstdio>
#include <queue>

int main(int argc, char *argv[])
{
    std::queue<char> A;
    char c;
    std::queue<char> B;
    while ((c = getchar()) != '\n')
	A.push(c);
    int length = 0;
    do
    {
	length = A.size();
	A.push('\n');
	while (A.front() != '\n')
	{
	    if (B.empty())
	    {
		B.push(A.front());
		A.pop();
	    }
	    else if (B.size() < 3)
	    {
		if (A.front() == B.front())
		{
		    B.push(A.front());
		    A.pop();
		}
		else
		{
		    while (!B.empty())
		    {
			A.push(B.front());
			B.pop();
		    }
		    B.push(A.front());
		    A.pop();
		}
	    }
	    else if (B.size() == 3)
	    {
		while (!B.empty())
		    B.pop();
		B.push(A.front());
		A.pop();
	    }
	}
	A.pop();
	while (!B.empty())
	{
	    A.push(B.front());
	    B.pop();
	}
    } while (length != A.size());
    while (!A.empty())
    {
	std::cout << A.front() << " ";
	A.pop();
    }
    std::cout << std::endl;
    return 0;
};
