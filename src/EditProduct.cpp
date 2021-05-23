#include <iostream>
#include "EditProduct.h"
#include "ShowProduct.h"
#include <fstream>

using namespace std;

struct Data{
	string name,type,price;
};

void EditProduct::edit_product(string name,int edit_type_no,string new_data){
	ShowProduct show_product;
	typedef struct Data Struct;
	show_product.name=name;
	Struct data=show_product.show_product(name);
	string file_name=name+".txt";		
	if(edit_type_no==1){			
		remove(file_name.c_str());
		ofstream EditFile;	
		string new_file=new_data+".txt";
		EditFile.open(new_file.c_str());
		EditFile<<"Name:"<<new_data<<endl<<"Type:"<<data.type<<endl<<"Price:"<<data.price;		
	}
	if(edit_type_no==2){
		ofstream EditFile;
		EditFile.open(file_name.c_str());
		EditFile<<"Name:"<<data.name<<endl<<"Type:"<<new_data<<endl<<"Price:"<<data.price;
	}	
	if(edit_type_no==3){
		ofstream EditFile;
		EditFile.open(file_name.c_str());
		EditFile<<"Name:"<<data.name<<endl<<"Type:"<<data.type<<endl<<"Price:"<<new_data;
	}	
	cout<<"Product Information Successfully Changed."<<endl;
	
}
