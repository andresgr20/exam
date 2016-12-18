#include <string>
#include <iostream>
using namespace std;


class Mistake{
	int x;
public:
	Mistake(int x);
	int What(){
		return x;
	}
};

void foo(){
	int x=4;
	throw x;
}

void foo1(){
	string s="hey";
	throw s;
}

void foo2(){
	string s="BYE";
	string *d=&s;
	throw d;
}

void foo3(){
	string s="Hello World";
	throw s;
	cout << "After throw" << endl; // after the throw this is not runx
}



int main(){
	try{
		//foo();
		//foo1();
		//foo2();
		foo3();
	}catch(int x){
		cout << "Caught foo " << x << endl; // works
	}catch(string &s){
		cout << "Caught foo1 " << s << endl; // works can catch by & s both work
	}catch(string *s){
		cout << "Caught foo2 " << s << endl; // sending s sends the address need to do *s returns a segmentation fault because it is derefencing to a pointer that has been pooped
	}catch(string &s){
		cout << "Caught foo3 " << s << endl;
	}

	cout << "This is over" << endl;
}
