#include <iostream>
#include <string>
#include "../LZ77/LZ77.h"
#include "../Huffman/huffman.h"
#include "../puff/puff.c"

using namespace std;

int main(){
	ifstream test1, test2;
	array<string,10> test = {"../testcases/test1.txt", "../testcases/test2.txt", "../testcases/test3.txt", "../testcases/test4.txt", "../testcases/test5.txt", "../testcases/test6.txt", "../testcases/test7.txt", "../testcases/test8.txt", "../testcases/test9.txt", "../testcases/test10.txt"};
	array<string,10> truth = {"../testcases/truth1.txt", "../testcases/truth2.txt", "../testcases/truth3.txt", "../testcases/truth4.txt", "../testcases/truth5.txt", "../testcases/truth6.txt", "../testcases/truth7.txt", "../testcases/truth8.txt", "../testcases/truth9.txt", "../testcases/truth10.txt"};
	array<bool,10> grade = {false};
	char string1[256], string2[256];
	for (int i = 0; i < test.size(); i++)
	{
		Deflate deflate(truth[i]);
		if (!(deflate.compress()))
		{
			continue;
		}
		else
		{
			test1.open(test[i]);
			test2.open(truth[i]);
			while(!test1.eof())
			{
				test1.getline(string1, 256);
				test2.getline(string2, 256);
				if (strcmp(string1, string2) == 0)
				{
					grade[i] = true;
				}
			}
		}
	}


	return 0;
}