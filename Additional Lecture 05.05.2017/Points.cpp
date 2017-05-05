#include <iostream>
#include <cstring>

using namespace std;


template<typename T>
class Point { //дефинираме си точка в двумерното пространство
	T x;
	T y;
public:
	
	Point<T>()
	{
		x=0;
		y=0;
	}
	
	Point<T>(T _x, T _y)
	{
		x=_x;
		y=_y;
	}
	
	Point<T>(T _a)
	{
		x=_a;
		y=_a;
	}
	
	void translate(T add_x, T add_y) // "местим" точката "на някъде" с подадените параметри
	{
		x+=add_x;
		y+=add_y;
	}
	
	void print()
	{
		cout<<"X:"<<x<<" Y:"<<y;
	}
	
};

template<typename T>
class Point3D: Point<T>{ //дефинираме точка в тримерното пространство, като наследяваме тази от двумерното(реализирана по-горе) и и добавяме още една координата

	T z;
	
public:
	
	//правим всички конструктори и функции да са валидни за тримерна точка(вместо за двумерна)
	Point3D<T> (): Point<T> (0,0)
	{
		z=0;
	}
	
	Point3D<T>(T _x, T _y, T _z) : Point<T>(_x, _y) 
	{
		z=_z;
	}
	
	void translate(T tx, T ty, T tz)
	{
		Point<T>::translate(tx, ty);
		z+=tz;
	}
	
	void print()
	{
		Point<T>::print();
		cout<<" Z:"<<z;
	}
	
};


int main() {

Point<double> a;
a.print();
cout<<endl;
a.translate(1,2);
a.print();
cout<<endl;

Point3D<int> b(1,2,3);
b.print();
cout<<endl;
b.translate(1,2,3);
b.print();

return 0;
}
