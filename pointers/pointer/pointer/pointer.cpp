// pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define RX_BUF_SIZE 1024
uint8_t** dataz;
void f(void)
{
	uint8_t* data = (uint8_t*)malloc(RX_BUF_SIZE + 1);
	memset(data, (uint8_t)'1', (sizeof(uint8_t) * RX_BUF_SIZE));
	dataz = &data;
}

int main()
{

	
	f();
	cout << *dataz;
    cout << "Hello World!\n";
}

