#include <iostream>
#include "Array.h"
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
int main()
{
	SetConsoleCP(1251); // забезпечення відображення кирилиці
	SetConsoleOutputCP(1251); // забезпечення відображення кирилиці
	const int N1 = 3;
	const int N2 = 8;
	Array<int, N1, N2> a;
	cin >> a;
	Array<int, N1, N2> b(1);
	cout << a;
	cout << a[5] << endl;
	cout << b;
	return 0;
}