#ifndef LISTE_HPP
# define LISTE_HPP

# include "Yigin.hpp"
# include "AVLAgaci.hpp"
# include "ListeDugum.hpp"

class Liste{
public:
	ListeDugum *listDugum;
	Liste();
	~Liste();

	void ekle(AVLAgaci *a);
	void yazdir();
	void yazdirYigit();
	int harfCikar();
	void tumYiginGuncelle();
	int enkucuk();
	int enBuyuk();
};



#endif