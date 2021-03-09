#include<iostream>
using namespace std;

void towerOfHanoi(int n, char from_road, char to_road, char aux_road)
{
	if (n == 1)
	{
		cout << "Move Disk 1 From Road" << from_road << "To Road" << to_road;	
		return;		
	}
	towerOfHanoi(n - 1, from_road, aux_road, to_road);
	cout << "Move disk" << n << "From Road" << from_road << "To Road" << to_road;
	towerOfHanoi(n - 1,aux_road , to_road,from_road );
}

int main()
{
	int discs_number;
	cout << "How many discs do you have : ";
	cin >> discs_number;

	towerOfHanoi(discs_number, 'A', 'B', 'C'); // A,B and C are names of road.
	return 0;
}