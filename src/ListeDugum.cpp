#include "ListeDugum.hpp"

ListeDugum::ListeDugum(AVLAgaci* a, int no)
{
	agac = a;
	avlNo = no;
	yiginGuncelmi = -1;
	ch = 0;
	sonraki = 0;
	yiginGuncelle();
}

ListeDugum::~ListeDugum()
{
	
}

void ListeDugum::yiginGuncelle()
{
	guncelle(agac->kok);
	yiginGuncelmi = 0;
}

void ListeDugum::guncelle(AVLDugum* d)
{
	if (d->sag == 0 && d->sol == 0)
	{
		yigin.ekle(d->veri);
	}
	else
	{
		ch += d->veri;
	}
	if (d->sol != 0)
	{
		guncelle(d->sol);
	}
	if (d->sag != 0)
	{
		guncelle(d->sag);
	}
}

void ListeDugum::yiginGuncelle(int limit)
{
	guncelleSagdan(agac->kok);
	yiginGuncelmi = 0;
}

void ListeDugum::guncelleSagdan(AVLDugum* d)
{
	if (d->sag == 0 && d->sol == 0)
	{
		if (yiginGuncelmi == yigin.uzunluk)
		{
			yigin.ekle2(d->veri);
		}
		else
		{
			yiginGuncelmi++;
		}
	}
	if (d->sol != 0)
	{
		guncelleSagdan(d->sol);
	}
	if (d->sag != 0)
	{
		guncelleSagdan(d->sag);
	}
}

