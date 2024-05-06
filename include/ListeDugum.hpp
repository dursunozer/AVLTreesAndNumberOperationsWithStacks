#ifndef LISTEDUGUM_HPP
# define LISTEDUGUM_HPP

# include "AVLAgaci.hpp"
# include "Yigin.hpp"

class ListeDugum
{
public:
	ListeDugum(AVLAgaci *a, int no);
	~ListeDugum();
	void yiginGuncelle();
	void yiginGuncelle(int limit);
	void guncelle(AVLDugum* d);
	void guncelleSagdan(AVLDugum* d);
	int 		avlNo;
	int			ch;
	int			yiginGuncelmi;
	AVLAgaci	*agac;
	Yigin		yigin;
	ListeDugum* sonraki;
};

#endif