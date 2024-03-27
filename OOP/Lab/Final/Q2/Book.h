#include <iostream>
#include "Page.h"

using namespace std;

class Book{
	private:
		int num_page;

	public:
		Book();
		Book(int np,nl);
		Book(Book &obj);
		~Book();

};
