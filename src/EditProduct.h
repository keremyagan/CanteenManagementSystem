#ifndef EditProduct_H
#define EditProduct_H
#include <iostream>
#include "ShowProduct.h"
using namespace std;
class EditProduct {
	// Private section
	public:
		string name,new_data;
		int edit_type_no;
		void edit_product(string name,int edit_type_no,string new_data);
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
