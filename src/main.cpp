#include<iostream>
#include<iomanip>
#include <fstream>
#include <stddef.h>
#include "AVLAgaci.hpp"
#include "Liste.hpp"
#include "Yigin.hpp"
using namespace std;

void	sayilariEkle(string fileName, Liste *myList)
{
	ifstream okumaDosyasi(fileName);
	okumaDosyasi.seekg(0);
	int	number;
	int x;

	AVLAgaci *a;
	while (!okumaDosyasi.eof())
	{
		string line;
		getline(okumaDosyasi, line);
		a = new AVLAgaci();
		while (line != "")
		{
			number = 0;
			x = line.find_first_of(' ');
			if(x < 0)
				number = stoi(line);
			else
				number = stoi(line.substr(0,x));
			if(x < 0)
				line = "";
			else
				line = line.substr(x+1);
			a->ekle(number);
		}
		myList->ekle(a);
	}

}

int main()
{
	Liste myList;

	sayilariEkle("Veri.txt", &myList);
	
	int c = 1;
	while (c == 1)
	{
		system("cls");
		myList.yazdir();
		c = myList.harfCikar();
	}
	system("cls");
	cout << "==============================" << endl;
	cout << "|                            |" << endl;
	cout << "|                            |" << endl;
	cout << "|     Son Karakter: " << (char)((myList.listDugum->ch % 26) + 65) << "        |" << endl;
	cout << "|     AVL No      : " <<myList.listDugum->avlNo << setw(3) << "      |" << endl;
	cout << "|                            |" << endl;
	cout << "|                            |" << endl;
	cout << "==============================" << endl;
	
	
	
	

}