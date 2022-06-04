#include <iostream>

using namespace std;

int Array[4][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 }; // zero tile is an empty one

void Display() // displays matrix Array
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "	" << Array[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Shuffle() // swaps two random tiles ten times
{
	int Temp = 0;
	int RIO = 0; // RandomIndexOne
	int RIT = 0; // RandomIndexTwo
	for (int i = 0; i < 10; i++)
	{
		RIO = rand() % 16;
		Temp = Array[(int)(RIO / 4)][RIO % 4];
		RIT = rand() % 16;
		Array[(int)(RIO / 4)][RIO % 4] = Array[(int)(RIT / 4)][RIT % 4];
		Array[(int)(RIT / 4)][RIT % 4] = Temp;
	}
}

bool IsSolving() // checks if puzzle can be solved
{
	int Counter = 0;
	int ZerosLine = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = i; j < 16; j++)
		{
			if (Array[(int)(i / 4)][i % 4] > Array[(int)(j / 4)][j % 4])
			{
				Counter++;
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (Array[(int)(i / 4)][i % 4] == 0)
		{
			ZerosLine = (int)(i / 4) + 1;
		}
	}
	if ((Counter + ZerosLine) % 2 == 0)
	{
		return true;
	}
	else
		return false;
}

void Move(int a, int b) // a is line, b is column // moves a tile to empty square if possible (actually swaps two tiles where one of them is zero)
{
	if (!((-1 < a && a < 4) && (-1 < b && b < 4)))
	{
		cout << "Wrong input" << endl;
		return;
	}
	if (-1 < a - 1 && a - 1 < 4)
	{
		if (Array[a - 1][b] == 0)
		{
			Array[a - 1][b] = Array[a][b];
			Array[a][b] = 0;
			return;
		}
	}
	if (-1 < b - 1 && b - 1 < 4)
	{
		if (Array[a][b - 1] == 0)
		{
			Array[a][b - 1] = Array[a][b];
			Array[a][b] = 0;
			return;
		}
	}
	if (-1 < b + 1 && b + 1 < 4)
	{
		if (Array[a][b + 1] == 0)
		{
			Array[a][b + 1] = Array[a][b];
			Array[a][b] = 0;
			return;
		}
	}
	if (-1 < a + 1 && a + 1 < 4)
	{
		if (Array[a + 1][b] == 0)
		{
			Array[a + 1][b] = Array[a][b];
			Array[a][b] = 0;
			return;
		}
	}
	cout << "Can't move this tile" << endl;
}

bool IsSolved() // checks if game is over
{
	for (int i = 0; i < 15; i++)
	{
		if (Array[(int)(i / 4)][i % 4] != i + 1)
		{
			return false;
		}
	}
	return true;
}

void Play() // main function that allows to play until you win, use Ctrl + C to exit the program
{
	do
	{
		Shuffle();
	}
	while (!IsSolving());
	Display();
	int x = 0;
	int y = 0;
	while (!IsSolved())
	{
		cout << "Input line and column" << endl;
		cin >> x >> y;
		x--;
		y--;
		Move(x, y);
		Display();
	}
	cout << "You win!" << endl;
}

int main()
{
	srand(time(NULL));

	Play();

	system("pause");
	return 0;
}