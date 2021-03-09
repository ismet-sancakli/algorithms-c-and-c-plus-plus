#include<iostream>
#include<string>
#include<process.h>
#include <cstdlib>
#include<cstdio>

using namespace std;

class myarray
{
private:
	int size , *p;

public:
	myarray (int sz)
	{
		p = new int[sz];

		if (!p)		
			exit(1);		
		size = sz;
		cout << "normal contructor kullanilmasi" << endl;
	}
	~myarray() { 
		delete[] p; 
	}
	myarray(const myarray &ob1)
	{
		int i;
		size = ob1.size;
		p = new int[ob1.size];
		if (!p)		
			cout << "allocation error" << endl; exit(1);
		for ( i = 0; i < ob1.size; i++)
		
			p[i] = ob1.p[i];// içerik kopyalnýyor..
		cout << "Using copy constructor" << endl;
	}
	int get(int i)
	{
		return p[i];
	}
	void put(int i, int j)
	{
		if (i >= 0 && i < size, p[i] = j);
	}
};


int main()
{
	 myarray ob(10);
	 myarray ob_1(20);
	 int i,a;
	 for ( i = 0; i <10	; i++)
	 {
		 ob.put(i, i);
	 }
	 for ( i = 0; i < 10; i++)
	 {
		 ob.get(i);
	 }
	 myarray x = ob;
	 for ( i = 0; i < 10; i++)
	 {
		 cout << x.get(i)<<endl;
	 }
	 cin >> a;
	 ob_1 = ob; // Does not call copy constructor..	 
	 return 0;
}