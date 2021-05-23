#include <iostream>
#include "ShowProduct.h"
#include <fstream>
using namespace std;
struct Data{
	string name,type,price;
};


string main_word(string word){
    int counter=0;
    string new_word;
    for(int i=0;i<=word.length();i++){
        if(word[i]==':'){
            counter=i+1;
        }
    }
    for(;counter<=word.length();counter++){
        new_word=new_word+word[counter];
    }
    return new_word;
}

typedef struct Data Struct;
Struct ShowProduct::show_product(string name){
	Data data;
	ifstream ShowProduct;
	string file_name=name+".txt";
	ShowProduct.open(file_name.c_str());
	string line;
	
	getline(ShowProduct,line);
	data.name=main_word(line);
	
	getline(ShowProduct,line);
	data.type=main_word(line);
	
	getline(ShowProduct,line);
	data.price=main_word(line);
	return data;
}

