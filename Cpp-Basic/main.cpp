#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	char *pStr = "hello world";
	char pStr1[] = "hello world";
	char pStr2[32] = "hello world";
	string Str0 = "hello world";
	string Str1 = "hello";
	string Str2 = "world";

	cout << "pStr: " << pStr << endl;
	cout << "pStr1: " << pStr1 << endl;
	cout << "hello world"<<endl;
	cout << Str0 << endl;
	cout << Str1 +' ' + Str2 << endl;
	cout << "Str1 len: " <<Str1.size()<< endl;

	return 0;
}