#include<iostream>
#include<stack>
#include<cstdio>

int main(int argc, char *argv[])
{
    std::stack<char> A;
    char c;
    bool flag = true;
    while ((c = getchar()) != '\n')
    {
	if (c == '(' || c == '{' || c == '[')
	    A.push(c);
	else if (c == ')')
	{
	    if (A.top() != '(')
		flag = false;
	    else
		A.pop();
	}
	else if (c == ']')
	{
	    if (A.top() != '[')
		flag = false;
	    else
		A.pop();
	}
	else if (c == '}')
	{
	    if (A.top() != '{')
		flag = false;
	    else
		A.pop();
	}
	if (flag == false)
	    break;
    }
    if (flag && A.empty())
	std::cout << "Match." << std::endl;
    else
	std::cout << "Not match." << std::endl;
    return 0;
};
