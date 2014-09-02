#include <iostream>
#include <set>
#include <random>
#include <time.h>
using namespace std;

#define SIZE 100

class StableMatch
{
	int men[SIZE][SIZE];
	int women[SIZE][SIZE];
	int menmatch[SIZE];
	int womenmatch[SIZE];
    
public:
	void generateCase()
	{
		srand(3);
//		srand((unsigned)time(NULL));
		for (int i = 0; i < SIZE; i++)
		{
			menmatch[i] = -1;
			womenmatch[i] = -1;
			for (int j = 0; j < SIZE; j++)
			{
				men[i][j] = j;
				women[i][j] = j;
			}
			for (int j = SIZE - 1; j > 0; j--)
			{
				int ran = rand() % j;
				int tem = men[i][ran];
				men[i][ran] = men[i][j];
				men[i][j] = tem;
			}
			for (int j = SIZE - 1; j > 0; j--)
			{
				int ran = rand() % j;
				int tem = women[i][ran];
				women[i][ran] = women[i][j];
				women[i][j] = tem;
			}
		}
        
	}
    
	void printCase()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "Line " << i << ":";
			for (int j = 0; j < SIZE; j++)
			{
				cout << " " << men[i][j];
			}
			cout << endl;
		}
	}
    
	void printMatch()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << menmatch[i];
		}
		cout << endl;

		/*for (int i = 0; i < SIZE; i++)
		{
			cout << womenmatch[i];			
		}
		cout << endl;*/
	}
    
	void getMatch()
	{
		while (next(menmatch, 0) >= 0)
		{
			int pos = next(menmatch, 9);
			for (int i = 0; i < SIZE; i++)
			{
				int currentWomen = men[pos][i];
				if (womenmatch[currentWomen] == -1)
				{
					womenmatch[currentWomen] = pos;
					menmatch[pos] = currentWomen;
					break;
				}
				else if (women[currentWomen][pos] < women[currentWomen][womenmatch[currentWomen]])
				{
					menmatch[womenmatch[currentWomen]] = -1;
					womenmatch[currentWomen] = pos;
					menmatch[pos] = currentWomen;
					break;
				}
			}
		}
	}
    
private:
	int next(int a[], int start)
	{
		int cur = -1;
		int index = start;
		for (int i = 0; i < SIZE; i++)
		{
			if (a[(i + index) % SIZE] == -1)
			{
				cur = (i + index) % SIZE;
                break;
			}
		}
		return cur;
	}
};

int main()
{
	StableMatch *sm = new StableMatch();
	sm->generateCase();
//	sm->printCase();
	sm->getMatch();
	sm->printMatch();
	return 0;
}