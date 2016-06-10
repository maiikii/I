#include <iostream>
using namespace std;

class fraction{
protected:
	int n,d;
public:
	fraction();
	fraction(int,int);
	int getNumerator();
	int getDenominator();
	void display();
	void setFraction(int a,int b){n = a; d= b;}
};

class MixedFraction : public fraction{
private:
	int w;	
public:
	MixedFraction() {w = 0; cout<<n<<endl; setFraction(0,1);}
	MixedFraction(int a) {w = a;setFraction(0,1);}
	MixedFraction(int a,int b,int c) {w=a;setFraction(b,c);}
	MixedFraction(fraction);
	MixedFraction(char *);
	void display(){cout<<w<<" "<<getNumerator()<<"/"<<getDenominator()<<endl;}
};

fraction::fraction(){
	n = 0;
	d = 1;
	cout<<"Default Constructor!"<<endl;
}

fraction::fraction(int n, int d){
	this->n = n;
	this->d = d;
	cout<<"Overloaded Constructor!"<<endl;
}

int fraction::getNumerator(){
	return n;
}

int fraction::getDenominator(){
	return d;
}

void fraction::display(){
	cout<<n<<"/"<<d<<endl;
}

int main(){
	//fraction f, r(4,9);
	//cout<<r.n<<endl;
	MixedFraction m(3,6,17);
	cout<<m.getNumerator()<<endl;
//	f.display();
//	r.display();
	m.display();
	return 0;
}
