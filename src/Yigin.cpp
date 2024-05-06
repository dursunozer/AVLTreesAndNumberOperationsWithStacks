#include "Yigin.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

Yigin::Yigin()
{
    tepe=0;
	uzunluk = 0;
}
void Yigin::ekle(int veri)
{
	YiginDugum* yeni = new YiginDugum(veri);
	if(tepe!=0)
	{
		yeni->sonraki=tepe;
	}
	uzunluk++;
	tepe = yeni;
}

void Yigin::ekle2(int veri)
{
	YiginDugum* yeni = new YiginDugum(veri);
	if(tepe!=0)
	{
		yeni->sonraki=tepe;
	}
	tepe = yeni;
}



void Yigin::cikar()
{
	if(tepe!=0)
	{
		YiginDugum* silinecek = tepe;
		tepe=tepe->sonraki;
		delete silinecek;
	}
}

void Yigin::yazdir()
{
	YiginDugum* tmp = tepe;
	while (tmp != 0)
	{

		cout << tmp->veri << " ";
		tmp = tmp->sonraki;
	}
}

int Yigin::getir()
{
    if(tepe!=0)
        return tepe->veri;
    throw out_of_range("Yigin::Getir(): Yigin Bos");
}
