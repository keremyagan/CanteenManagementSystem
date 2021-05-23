#include <iostream>
#include <fstream>
#include "AddProduct.h"
using namespace std;

void AddProduct::add_product(string name,string type,double price){
	ofstream AddProduct;
	string file_name=name+".txt";//Since the product name is unique, the files are saved with the product name.
	AddProduct.open(file_name.c_str());
	AddProduct<<"Name:"<<name<<endl<<"Type:"<<type<<endl<<"Price:"<<price;
	AddProduct.close();
	cout<<"Product Registration Successful."<<endl;
}
