#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "AVLDugum.hpp"
using namespace std;

class AVLAgaci
{
public:
	AVLDugum *kok;
	AVLAgaci();
	~AVLAgaci();
	void ekle(int veri);

private:
	AVLDugum	*solaDondur(AVLDugum *dugum);
	AVLDugum	*sagaDondur(AVLDugum *dugum);
	int		yukseklik(AVLDugum *dugum);
	AVLDugum	*ekle(int veri, AVLDugum *dugum);
};
//diger fonksiyonlar eklenecek
#endif