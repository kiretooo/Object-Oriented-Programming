#include <iostream>
#include <cstring>

using namespace std;

class Car //класът реализиращ кола
{
private:
	char *brand; // динамична памет -> голяма четворка
 	unsigned year;
 	unsigned reg_numb;
public:
	
Car()
{
	brand= new char[5];
	strcpy(brand, "LADA");
	year=2017;
	reg_numb=6969;
}

Car(char *_brand , unsigned _year, unsigned _reg_numb)
	{
		brand = new char[strlen(_brand)+1];
 		strcpy(brand, _brand);
		year = _year;
		reg_numb = _reg_numb;
	}
	
~Car()
	{
	 	delete [] brand;
	}
	
Car(const Car& c)
	{
		brand = new char[strlen(c.brand)+1];
	 	strcpy(brand, c.brand);
	 	year = c.year;
	 	reg_numb = c.reg_numb;
	}	
	
Car& operator=(const Car& c)
{	
	if (this != &c)
 		{
		 	 delete [] brand;
			 brand = new char[strlen(c.brand)+1];
			 strcpy(brand, c.brand);
			 year = c.year;
			 reg_numb = c.reg_numb;
 		}
 return *this;
}

friend ostream& operator<<(ostream& os, const Car &other)
{
	os << "Brand: " << other.brand << endl;
 	os << "Brand: " << other.year << endl;
 	os << "Reg. Number: " << other.reg_numb << endl;
 	return os;
}

void display()
{cout << "Mark: " << brand << endl;
 cout << "Year: " << year << endl;
 cout << "Reg. Number: " << reg_numb << endl;
}
};





class Person 
{
private:
 	char * name; // Отново, за пореден път, динамична памет
 	char * pin;
public:

Person(char *str, char *num)
{
	 name = new char[strlen(str)+1];
	 strcpy(name, str);
	 pin = new char[strlen(p.num)+1];
	 strcpy(pin, num);
}
Person(const Person& p)
{
	 name = new char[strlen(p.name)+1];
	 strcpy(name, p.name);
	 pin = new char[strlen(p.pin)+1];
	 strcpy(pin, p.pin);
}
Person& operator=(const Person& p)
{
	if (this != &p)
 	{
	 	 delete name;
 		 delete pin;

		 name = new char[strlen(p.name)+1];
		 strcpy(name, p.name);
		 pin = new char[strlen(p.pin)+1];
		 strcpy(pin, p.pin);
 	}
 	return *this;
}
void display()
{
	 cout << "Ime: " << name << endl;
	 cout << "EGN: " << pin << endl;
}
~Person()
{
	 delete name;
	 delete pin;
}

friend ostream& operator<<(ostream& os, const Person& other)
{
	os<<"Ime: " << other.name<< endl;
	os<<"PIN: " << other.pin<<endl;
	return os;
}


};

class CarPassport: public Car, public Person //по този начин наследяваме и двата класа
{
public:
 
CarPassport(char *brand, unsigned year,unsigned reg_numb, char* name, char *pin) :
	 Car(brand, year, reg_numb), Person(name, pin){}
	 
~CarPassport()
{
	cout <<"WTF is this?"; // Какво изобщо се случва :) ?
}

CarPassport(const CarPassport& cp) : Car(cp),Person(cp) {}

CarPassport& operator=(const CarPassport& cp)
{
	if (this != &cp)
    {
		Car::operator =(cp); // използваме операторите за Car и Person по отделно
 		Person::operator =(cp);
 	}
 	return *this;
}

void display()
{
	Car::display();
	Person::display();
}

friend ostream& operator<<(ostream& os, const CarPassport& other)
{
	os<<(Car)other;
	os<<(Person)other;
	return os;
}
 
};

int main()
{
	//Малко проверки, за да се уверим, че всичко работи
	CarPassport x("FORD FIESTA", 2000, 2295,"Vassil Todorov", "8012174586");
	cout<<x;
	CarPassport y("LADA", 1900, 8817,"Sonia Todorova", "8203314576");
	y = x;
	cout<<y;
 
 
	Car a("LADA", 1900,8817);
	cout<<a;
	Person p("Pavel","1234567898");
	cout<<p;
 return 0;
}
