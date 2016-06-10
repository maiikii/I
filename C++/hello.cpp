#include <iostream>

using namespace std;

class fraction{
public:
	int n,d;
private:
	int z;	
};

void init(fraction &f,int n, int d){
	cout<<&f<<endl;
	f.n = n;
	f.d = d;
}

int main(){
	fraction f, r;
	s = f.add(r);
	f.n = 2;
	f.d = 3;
	f.z = 45;
	init(r,5,9);
	cout<<r.n<<"/"<<r.d<<endl;
	return 0;
}
