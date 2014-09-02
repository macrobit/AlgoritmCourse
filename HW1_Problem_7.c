#include <iostream>
#include <time.h>
using namespace std;
#define SIZE 16 * 1024
#define STEP 64 * 1024 * 1024

int a[SIZE];

int main()
{
	clock_t start, finish; 
	for (int i = 0; i < SIZE; i++)
	{
		a[i] = 0;
	}
	start = clock();
	for (int i = 0; i < STEP; i++)
	{
		a[i & SIZE]++;
	}
	finish = clock();
	double duration =  (double)(finish - start) / CLOCKS_PER_SEC;  
	cout << " running time is " << duration << endl;
/*	for (int r = 1; r < 1024; r *= 2)
	{
		start = clock();
		for (int i = 0; i <= SIZE; i++)
		{
			a[i] = a[i] * a[i];
		}
		finish = clock();
		double duration =  (double)(finish - start) / CLOCKS_PER_SEC;  
		cout << "For step " << STEP + r << " running time is " << duration << endl;
	}*/

	return 0;
}