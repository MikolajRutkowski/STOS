
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <iostream>
using namespace std;

int lenghtt  ;

void display(int** number, int up , int down) {
	cout << endl;
	
	for (int j = 0; j < down; j++)
	{


		for (int i = 0; i < up; i++)
		{
			
			if (number[i][j] > -1) {
				cout <<" " << number[i][j] << "|";
			}
			else {
				cout << number[i][j] << "|";
			}
		}
		cout << endl;
		
	}
	char x;
	//cin >> x;
}

void ChoseGraph(int xxx) {
	
	int copy;
	int krokomierz;
	int licznik = 0;
	
	switch (xxx) {
	case 0: {
		cin >> krokomierz;
		lenghtt = 3;
		
		for (int i = 2; i < krokomierz + 1; i++)
		{
			lenghtt = lenghtt * 3;
		}
		int** tab = new int* [lenghtt];
		for (int i = 0; i < lenghtt; i++)
		{
			tab[i] = new int[lenghtt];

		}
		for (int i = 0; i < lenghtt; i++)
		{
			for (int j = 0; j < lenghtt; j++)
			{

				tab[i][j] = 0;


			}
		}
		//cout << "BarabasiRavaszVicsek"; 


		copy = 1;

		//krok 0 i 1
		tab[0][0] = -2;
		tab[0][1] = 1;
		tab[0][2] = 1;
		tab[1][0] = 1;
		tab[1][1] = -1;
		tab[1][2] = 2;
		tab[2][2] = -1;
		tab[2][0] = 1;
		tab[2][1] = 2;


		//display(tab, lenghtt, lenghtt);
		//kroki 2,3,4......
		 //krokomierz
		for (int k = 2; k <= krokomierz; k++)
		{
			copy = copy * 3;
			//pierwsze kopiowanie
			for (int i = copy; i < copy * 2; i++)
			{
				for (int j = copy; j < copy * 2; j++)
				{
					
					tab[i][j] = tab[i - copy][j - copy];
					if (tab[i][j] < 0 ) {
						
						tab[i][0] = tab[i][j] * -1;
						tab[0][j] = tab[i][j] * -1;
						if (i - copy != 0) {
							tab[i - copy][j - copy] = 0;
						}
						if (tab[i][j] == -2) {
							tab[i][j] = 0;
						}
						
					}
					
					
					
				}
			}
			//display(tab, lenghtt, lenghtt);
			// uzupe�nianie pozosta�ych d�ugo�ci
			for (int i = copy + 1; i < copy * 2; i++)
			{
				if (tab[i][i] == 0 ) {
					for (int z = i; z < copy * 2; z++)
					{
						if (tab[z][z] == -1) {
							tab[i][0] = tab[z][i] + 1;
							tab[0][i] = tab[z][i] + 1;
							break;
						}
						
					}
				}
			}
			
			//drugie kopiwoanie
			for (int i = copy + copy; i < copy + copy + copy; i++)
			{
				tab[i][0] = tab[i - copy][0];
				for (int j = copy + copy; j < copy + copy + copy; j++)
				{
					
					tab[0][j] = tab[0][j - copy]; ;
					tab[i][j] = tab[i - copy][j - copy];
				}
			}
			//display(tab, lenghtt, lenghtt);
		
			for (int i = 1; i < copy + copy + copy; i++)
			{
				for (int j = 1; j < copy + copy + copy; j++)
				{
					if (i != j) {
						if (tab[i][j] == 0) {
							tab[i][j] = tab[0][j] + tab[0][i];
						}
					}
				}
			}
			//display(tab, lenghtt, lenghtt);
			int x;
		}
		//zliczanie 
		for (int i = 0; i < copy + copy + copy; i++)
		{
			for (int j = 0; j < copy + copy + copy; j++)
			{
				if (tab[i][j] < 0) {
					continue;
				}
				else {
					licznik += tab[i][j];
				}

			}
		}
		//display(tab, lenghtt, lenghtt);
		cout << licznik / 2;
		cout << "\n";
		for (int i = 0; i < lenghtt; i++)
		{
		//	cout << tab[i][0];
		//	cout << " ";

		}
		for (int i = 0; i < lenghtt; i++)
		{
			delete[] tab[i];

		}
		delete[]  tab;


		break;
	}
	case 1: {
		// Lu Su go
		cin >> krokomierz;
		lenghtt = 1;
		int potegowacz = 1;
		for (int i = 2; i < krokomierz + 1; i++)
		{
			potegowacz = potegowacz * 2;
			lenghtt += potegowacz;
		}
		
		int** tab = new int* [lenghtt];
		for (int i = 0; i < lenghtt; i++)
		{
			tab[i] = new int[lenghtt];

		}
		for (int i = 0; i < lenghtt; i++)
		{
			for (int j = 0; j < lenghtt; j++)
			{

				tab[i][j] = 0;


			}
		}
		 // k bedzie zapisany w ukosie
		// krok 0 i 1
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				tab[i][j] = 1;
				
			}
		}
		tab[0][0] =0 ;
		tab[1][1] =-1 ;
		tab[2][2] =-1 ;
		// kroki 2 3 4 ..
		potegowacz = 2;
		int deep = -2;
		//display(tab, lenghtt, lenghtt);
		for (int k = 2; k < krokomierz; k++)
		{
			potegowacz = potegowacz * 2;
			for (int i = k -1; i < lenghtt; i++)
			{
				//cout << i;
				// ka�dy k -1 z nowymi wez�ami
				if (tab[i][i] ==deep + 1 ) {
					for (int j = i; j < lenghtt; j++)
					{
						if (tab[j][j] == 0) {
							tab[j][j] = deep;
							tab[i][j] = 1;
							tab[j][i] = 1;
							tab[j + 1][j+1] = deep;
							tab[i ][j + 1] = 1;
							tab[j + 1][i ] = 1;
							
							break;
						}
					}
				}
				//display(tab, lenghtt, lenghtt);
				// ten popierdlony krok
				if (tab[i][i] == deep) {
					// szukamy przodka
					int przodek = (i - 1) / 2;
					przodek = przodek % (deep + 1);
					tab[i][przodek] = 1;
					tab[przodek][i] = 1;
				}


			}
			
			deep--;
		}



		//zliczanie 
		for (int i = 0; i < lenghtt; i++)
		{
			for (int j = 0; j < lenghtt; j++)
			{
				if (tab[i][j] < 0) {
					continue;
				}
				else {
					licznik += tab[i][j];
				}

			}
		}
		display(tab, lenghtt, lenghtt);
		cout << licznik / 2;
		cout << "\n";

		//display(tab, lenghtt, lenghtt);
		for (int i = 0; i < lenghtt; i++)
		{
			delete[] tab[i];

		}
		delete[]  tab;
		break; }
	default: {
		cout << "NIE MA TAKIEGO GRAFU";
		cout << "\n"; }
	}
	
}


int main()
{
	
		
		//display(tablica, lenghtt, lenghtt);
	
		int x = 0;
		
		while (cin >> x) {
			ChoseGraph(x);
		}



		

	return 0;
}









