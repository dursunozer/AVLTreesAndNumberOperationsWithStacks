#ifndef Yigin_hpp
#define Yigin_hpp
#include "YiginDugum.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

class Yigin
{
public:
	Yigin();
	void ekle(int veri);
	void ekle2(int veri);
	void cikar();
	int getir();
	void yazdir();
	int uzunluk;
	YiginDugum* tepe;
private:
	
};

#endif