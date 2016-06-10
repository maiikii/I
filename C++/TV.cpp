#include <iostream>
#include <string.h>
using namespace std;

class TV{
private:
	int size, type, channel,volume;
	bool status;
	char brand[50];
public:
	TV();
	TV(char*,int,int);
	~TV();
	int getSize(){ return size; }
	int getType(){ return type; }
	char* getBrand(){ return brand; }
	void power();
	bool changeChannel(int);
	bool changeVolume(int);
	void display();
};

int main(){

	TV t1;
	TV t2("Samsung",56,3);
	t2.display();
	t1.changeChannel(2);
	t1.changeVolume(50);
	t1.display();
	return 0;
}

TV::TV(char* b,int s, int t){
	cout<<"OverloadedConstruction"<<endl;
	strcpy(brand, b);
	size = s;
	type = t;
	channel = 0;
	status = false;
	volume = 0;
}

TV::~TV(){
    display();
    cout<<"Destroyed."<<endl;
}

void TV::display(){
	cout<<"Brand: "<<brand<<endl;
	cout<<"Size: "<<size<<endl;
	cout<<"Type: "<<type<<endl;
	cout<<"Status: "<<status<<endl;
	cout<<"Channel: "<<channel<<endl;
	cout<<"Volume: "<<volume<<endl;
}

TV::TV(){
	cout<<"Default Construction"<<endl;
	size = 42;
	type = 4;
	strcpy(brand,"Philips");
	status = false;
	channel = 0;
	volume = 0;
}

void TV::power(){
	if(status)
		status = false;
	else
		status = true;
}

bool TV::changeChannel(int c){
	if(status){
		channel = c;
		return true;
	}
	else
		return false;
}

bool TV::changeVolume(int c){
	if(status){
		volume = c;
		return true;
	}
	else
		return false;
}
