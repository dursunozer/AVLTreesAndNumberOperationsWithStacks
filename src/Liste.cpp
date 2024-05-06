#include "Liste.hpp"

Liste::Liste(){
	listDugum = 0;
}

Liste::~Liste(){}

void Liste::ekle(AVLAgaci *a)
{
	if (listDugum == 0)
		listDugum = new ListeDugum(a, 1);
	else
	{
		int i = 1;
		ListeDugum *tmp = listDugum;
		while (i++, tmp->sonraki != 0)
			tmp = tmp->sonraki;
		tmp->sonraki = new ListeDugum(a, i);
	}
}

void Liste::yazdir()
{
	ListeDugum *tmp = listDugum;
	while (tmp != 0)
	{

		cout << (char)((tmp->ch % (90-65+1)) + 65);
		//tmp->yigin.yazdir();
		tmp = tmp->sonraki;
	}
	cout << endl;
	
}

void Liste::yazdirYigit()
{
	ListeDugum *tmp = listDugum;
	while (tmp != 0)
	{

		cout << (char)((tmp->ch % (90-65+1)) + 65);
		tmp = tmp->sonraki;
	}
	cout << endl;
}

void Liste::tumYiginGuncelle()
{
	ListeDugum* tmp = listDugum;
	while (tmp != 0)
	{
		if (tmp->yiginGuncelmi != 0)
		{
			tmp->yiginGuncelle(tmp->yiginGuncelmi);
		}
		tmp = tmp->sonraki;
	}
}

int Liste::harfCikar()
{
	int c = 0;
	if (listDugum->sonraki == 0)
		return (0);
	while (c == 0)
	{
		c = enkucuk();
		if (c == 1)
			break;
		c = enBuyuk();
		if (c == 1)
			break;
	}
	tumYiginGuncelle();
	return (1);

}

int	Liste::enkucuk()
{
	ListeDugum *tmp = listDugum;
	int min = tmp->yigin.getir();
	ListeDugum *silinecek = tmp;
	while (tmp->sonraki != 0)
	{
		if (min > tmp->sonraki->yigin.getir())
		{
			min = tmp->sonraki->yigin.getir();
			silinecek = tmp;
		}
		tmp = tmp->sonraki;
	}
	if (min == listDugum->yigin.getir())
	{
		listDugum->yigin.cikar();
		listDugum->yiginGuncelmi += 1;
		if (listDugum->yigin.tepe == 0)
		{
			tmp = listDugum;
			listDugum = listDugum->sonraki;
			delete tmp;
			return (1);
		}
		return (0);
	}
	else
	{
		silinecek->sonraki->yigin.cikar();
		silinecek->sonraki->yiginGuncelmi += 1;
		if (silinecek->sonraki->yigin.tepe == 0)
		{
			ListeDugum *tmp2 = silinecek->sonraki;
			silinecek->sonraki = tmp2->sonraki;
			delete tmp2;
			return (1);
		}
	}
	return (0);
}

int	Liste::enBuyuk()
{
	ListeDugum *tmp = listDugum;
	int max = tmp->yigin.getir();
	ListeDugum *silinecek = tmp;
	while (tmp->sonraki != 0)
	{
		if (max < tmp->sonraki->yigin.getir())
		{
			max = tmp->sonraki->yigin.getir();
			silinecek = tmp;
		}
		tmp = tmp->sonraki;
	}
	if (max == listDugum->yigin.getir())
	{
		listDugum->yigin.cikar();
		listDugum->yiginGuncelmi += 1;
		if (listDugum->yigin.tepe == 0)
		{
			tmp = listDugum;
			listDugum = listDugum->sonraki;
			delete tmp;	
			return (1);
		}
		return (0);
	}
	else
	{
		silinecek->sonraki->yigin.cikar();
		silinecek->sonraki->yiginGuncelmi += 1;
		if (silinecek->sonraki->yigin.tepe == 0)
		{
			ListeDugum *tmp2 = silinecek->sonraki;
			silinecek->sonraki = tmp2->sonraki;
			delete tmp2;
			return (1);
		}
	}
	return (0);
}