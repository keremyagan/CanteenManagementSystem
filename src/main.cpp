#include <iostream>
#include "AddProduct.h"
#include "EditProduct.h"
#include "ShowProduct.h"
#include <fstream>
#include <dirent.h>
#include <sys/types.h>
#include <vector>
using namespace std;

bool is_file_exist(const char *fileName)//File presence is checked
{
    std::ifstream infile(fileName);
    return infile.good();
}
struct Data{
	string name,type,price;
};
vector<string> list_dir(const char *path) {
   struct dirent *entry;
   vector<string> paths;
   DIR *dir = opendir(path);
   

   while ((entry = readdir(dir)) != NULL) {
   paths.push_back(entry->d_name);
   }
   closedir(dir);
   return paths;
}

int main(int argc, char** argv) {
	cout<<"Welcome to Canteen Management System"<<endl;
	for(int i=0;i<1;i++){
		cout<<"1-Add Product\n"<<"2-Edit Product\n"<<"3-See Product\n"<<"4-Delete Product"<<endl<<"5-Exit\n"<<"Please Enter Transaction Number:";
		int option;
		cin>>option;
		if(option==1){
			string name,type;
			double price;
			cout<<"Please Enter Product Name:";
			cin>>name;
			cout<<"Please Enter Product Type:";
			cin>>type;
			cout<<"Please Enter Product Price:";
			cin>>price;
			AddProduct add;
			add.add_product(name,type,price);
			i=i-1;
		}
		if(option==2){
			i=i-1;
			string name,new_data;
			int edit_type_no;
			cout<<"Please Enter The Product Name You Want To Edit:";
			cin>>name;
			string file_name=name+".txt";
			bool check_file=is_file_exist(file_name.c_str());
			if(check_file==1){
				cout<<"What Do You Want To Change"<<endl<<"1-Name"<<endl<<"2-Type"<<endl;
				cout<<"3-Price"<<endl<<"Please Enter Transaction Number As Integer:";
				cin>>edit_type_no;
				cout<<"Please Enter New Data:";
				cin>>new_data;
				EditProduct edit;
				if(edit_type_no<4 && edit_type_no>-1){
					edit.edit_product(name,edit_type_no,new_data);
				}
				else{
					cout<<"Please Enter Value Between 1-3 and try again."<<endl;
				}
			}
			else{
				cout<<"Product Not Available. Please Select Add Product from Main Menu to Add Product."<<endl;
			}

		}
		if(option==3){
			i=i-1;
			cout<<"1-See A Product Details"<<endl<<"2-See All Products"<<endl<<"Please Enter Transaction Number:";
			int a_all;
			cin>>a_all;
			if(a_all==1){//see a product details
				cout<<"Please Enter Product Name Which You Want To See Details:";
				string name;
				cin>>name;
				string file_name=name+".txt";
				bool check_file=is_file_exist(file_name.c_str());
				if(check_file==1){
					ShowProduct show_product;
					typedef struct Data Struct;
					Struct data=show_product.show_product(name);
					cout<<"Product Name:"<<data.name<<endl;
					cout<<"Product Type:"<<data.type<<endl;
					cout<<"Product Price:"<<data.price<<endl;
				}
				if(check_file==0){
					cout<<"Product Not Available. Please Select Add Product from Main Menu to Add Product."<<endl;
					i=i-1;
				}

			}
			if(a_all==2){//all products details
				char tmp[256];
			    getcwd(tmp, 256);	
				vector<string> paths= list_dir(tmp);
				int product_no=0;
				   for(unsigned i= 0; i<paths.size(); i++)
				    {
				      if (paths[i].find(".txt") != string::npos) {
				      		product_no++;
							ShowProduct show_product;
							typedef struct Data Struct;
							size_t lastindex = paths[i].find_last_of("."); 
							string name = paths[i].substr(0, lastindex);
							Struct data=show_product.show_product(name);
							cout<<product_no<<".Product"<<endl;
							cout<<"Product Name:"<<data.name<<endl;
							cout<<"Product Type:"<<data.type<<endl;
							cout<<"Product Price:"<<data.price<<endl<<endl;
						} 
				    } 
				}
			        
			
			if(a_all!=2 && a_all!=1){
				cout<<"Please Enter 1 or 2 and try again later."<<endl;
			}

			
		}
		
		if(option==4){//delete product
			i=i-1;
			cout<<"Please Enter Product Name Which You Want to Delete:";
			string name;
			cin>>name;
			string file_name=name+".txt";
			bool check_file=is_file_exist(file_name.c_str());
			if(check_file==1){
				remove(file_name.c_str());
				cout<<"Product Deletion Successful"<<endl;
			}
			else{
				cout<<"The Requested Item Not Found. Please Check It And Try Again."<<endl;
			}
		}
		
		if(option==5){
			cout<<"Exit Succesfull";
		}
	}
	
	return 0;
}
