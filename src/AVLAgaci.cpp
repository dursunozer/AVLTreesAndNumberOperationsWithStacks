#include "AVLAgaci.hpp"
#include <cmath>
#include <iomanip>
#include<iostream>
#include<queue>

using namespace std;

AVLAgaci::AVLAgaci()
{
	kok = nullptr;
}
AVLAgaci::~AVLAgaci()
{

}

void AVLAgaci::ekle(int veri)
{
	kok = ekle(veri, kok);
}

AVLDugum *AVLAgaci::solaDondur(AVLDugum *buyukEbeveyn)
{
	AVLDugum* sagCocuk = buyukEbeveyn->sag;
	buyukEbeveyn->sag = sagCocuk->sol;
	sagCocuk->sol = buyukEbeveyn;
	return sagCocuk;
}

AVLDugum *AVLAgaci::sagaDondur(AVLDugum *buyukEbeveyn)
{
	AVLDugum *solCocuk = buyukEbeveyn->sol;
	buyukEbeveyn->sol = solCocuk->sag;
	solCocuk->sag = buyukEbeveyn;
	return solCocuk;
}

int		AVLAgaci::yukseklik(AVLDugum *aktifDugum)
{
	if (aktifDugum)
	{
		return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
	}
	return (-1);
}

AVLDugum*	AVLAgaci::ekle(int veri, AVLDugum* aktifDugum)
{
	if(aktifDugum==0)
        return new AVLDugum(veri);

	else if(aktifDugum->veri<veri)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(veri>aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri>veri)
    {
        aktifDugum->sol = ekle(veri,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(veri<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}