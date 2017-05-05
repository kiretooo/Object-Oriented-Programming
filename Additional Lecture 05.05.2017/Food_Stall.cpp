#include <iostream>
#include <cstring>

using namespace std;

class Drinkable{ //нещо за пиене, казваме единствено колко милилитра е
	
	int milliliters;
	
public:
	
	Drinkable()
	{
		 milliliters=0;
	}
	
	Drinkable(int _milliliters)
	{
		 milliliters=_milliliters;
	}
	
	int getMilliliters() const
	{
		return milliliters;
	}
	
	void setMilliliters(int _mil)
	{
		milliliters=_mil;
	}
	
	friend ostream& operator<<(ostream& os, const Drinkable& smthtodrink)
	{
		os<<"Quantity: "<<smthtodrink.milliliters<<" milliliters. ";	
		return os;
	}
	
};

class Beer:  public Drinkable{ //нещото за пиене го правим Бира, като наследяваме класа Drinkable
	
	double alc; //Добавяме променлива, която ще показва какво е алкохолното съдържание в бирата
	
public:
	
	Beer(): Drinkable() // използваме дефолтния конструктор на Drinkable
	{
		alc=4.5;
	}
	
	Beer(int _milliliters, double _alc): Drinkable(_milliliters) // използваме конструктора с параметри на Drinkable
	{
		alc=_alc;
	}
	
	double getAlc() const
	{
		return alc;
	}
	
	void setAlc(double _alc)
	{
		alc=_alc;
	}
	
	friend ostream& operator<<(ostream& os, const Beer& beer)
	{
		os<<"Beer-> ";
		os<<(Drinkable)beer;//Казваме нещо от сорта на "Я ми принтирай тая бира, както принтираш Drinkable
		os<<"alc: "<<beer.alc<<endl;
		return os;
	}
	
};

class Water: public Drinkable{ //правим си вода от нещото за пиене като наследяваме класа Drinkable
	
	int pH; //добавяме член данна за pH на водата
	//разбрах, че колкото по-малко е, толкова по-зле, така че внимавайте
	
public:
	
	Water(): Drinkable()  // използваме дефолтния конструктор на Drinkable
	{
		pH=7; // така май имаме здравословна вода!
	}
	
	Water(int _milliliters, int _pH): Drinkable(_milliliters) // използваме конструктора с параметри на Drinkable
	{
		pH=_pH;
	} 
	
	int getpH() const
	{
		return pH;
	}
	
	void setpH(int _pH)
	{
		pH=_pH;
	}
	
	friend ostream& operator<<(ostream& os, const Water& water)
	{
		os<<"Water-> ";
		os<<(Drinkable)water;//Казваме нещо от сорта на... най-вероятно схванахте какво казваме :D
		os<<"pH: "<<water.pH<<endl;
		return os;
	}
	
};

class Eatable{ //Правим си клас нещо за ядене

	int grams; // Характеризираме го с колко грама е
	
public:
	
	Eatable()
	{
		 grams=0;
	}
	
	Eatable(int _grams)
	{
		 grams=_grams;
	}
	
	int getGrams() const
	{
		return grams;
	}
	
	void setGrams(int _grams)
	{
		grams=_grams;
	}
	
	friend ostream& operator<<(ostream& os, const Eatable& smthtoeat)
	{
		os<<smthtoeat.grams<<" grams ";	
		return os;
	}
	
};

class Pizza: public Eatable{ //Нещото за ядене става пица с помоща на наследяване
	
	bool veggie; // тя може да е вегетарианска
	bool spicy; // може да е люта
	//а може и двете едновременно
	
public:
	
	Pizza(): Eatable()
	{
		veggie= false; // по-дефолт обаче ще си направим една "скучна" не-веджи 
		spicy= false; //и не-люта пица
	}
	
	Pizza(int _grams, bool _veggie, bool _spicy): Eatable(_grams)
	{
		veggie=_veggie;
		spicy=_spicy;
	}
	
	bool getVeggie() const
	{
		return veggie;
	}
	
	bool getSpicy() const
	{
		return spicy;
	}
	
	void setVeggie(bool _veggie)
	{
		veggie=_veggie;
	}
	
	void setSpicy(bool _spicy)
	{
		spicy=_spicy;
	}
	
	void setBothVeggieAndSpicy(bool _veggie, bool _spicy)
	{
		veggie=_veggie;
		spicy=_spicy;
	}
	
	friend ostream& operator<<(ostream& os, const Pizza& pizza)
	{
		os<<(Eatable)pizza; //разбрахте го това, нали?
		if(pizza.veggie and pizza.spicy) os<<"of spicy and veggie pizza."<<endl;
		else if(pizza.veggie) os<<"of veggie pizza."<<endl;
		else if (pizza.spicy) os<<"of spicy pizza."<<endl;
		else os<<"of pizza.";
		
		return os;
	}
	
};

class  Broccoli: public Eatable{ //правим си и любимите ни от детството(а и не само) броколи
	bool boiled;//вари ги
	bool roasted;//печи ги
	//все са супер
public:
	 Broccoli(): Eatable()
	{
		boiled=false;
		roasted=false;
		//И сурови стават... май
	}
	
	 Broccoli(int _grams, bool _boiled, bool _roasted): Eatable(_grams)
	{
		boiled=_boiled;
		roasted=_roasted;
	} 

	bool getBoiled() const
	{
		return boiled;
	}
	
	bool getRoasted() const
	{
		return roasted;
	}
	
	void setBoiled(bool _boiled)
	{
		boiled=_boiled;
	}
	
	void setRoasted(bool _roasted)
	{
		roasted=_roasted;
	}
	
	void setBothBoiledAndRoasted(bool _boiled, bool _roasted)
	{
		boiled=_boiled;
		roasted=_roasted;
	}
	
	friend ostream& operator<<(ostream& os, const Broccoli& bro)
	{
		os<<(Eatable)bro;
		if(bro.boiled and bro.roasted) os<<"of boiled and roasted broccoli."<<endl;
		else if(bro.boiled) os<<"of boiled broccoli."<<endl;
		else if (bro.roasted) os<<"of roasted broccoli."<<endl;
		else os<<"of raw broccoli";
		
		return os;
	}
};


template<typename T>
class Food_Stall //дефинираме количка с място за само един вид продукт, който е от тип Т
{
	T* product; // масив от продукти с тип Т
	int current;//текущия брой на елементи в масива
	int capacity; //текущата големина на масива

	void copy(Food_Stall<T> const& other) // помощна функция, която прави нашата количка да е същата като тази която сме подали като аргумент
	{
		current = other.current;
		capacity = other.capacity;

		product = new T[capacity];//динамично си заделяме масив
		for (int i = 0; i <= current; i++)
			product[i] = other.product[i];
	}
	
	void remove() //трием динамично заделения масив
	{
		delete[] product;
	}
  
  	void resize() //resize-ваме големината на масива от продукти
	{
		T *product2 = new T[capacity]; // първо си правим помощен масив
		
		for (int i = 0; i <= current; i++)
		{
			product2[i] = product[i]; // копираме всички елементи на масива-член-данна в помощния
		}
		
		remove(); // трием член данната
		// П.С.: Виж функцията remove
		
		product = new T[capacity*2]; //правим си масива-член-данна да е два пъти по-голям отколкото е бил
		// Боговете на програмирането са открили, че това е най, ама най-добрия метод
		//или както биха казали Ъпсурт- "Дъ бйест оф дъ бйест"
		
		for(int i = 0; i <= current; i++)
		{
				product[i] = product2[i]; // копираме в новия, вече два пъти по-голям масив данните от помощния
				//данните които копираме си бяха и преди в членн-данната-масив но трябваше да го реконструираме
		}
		
		capacity*=2;//вече имаме двойно по-голяма големина на масива-член-данна и е хубаво да го покажем
		
		delete [] product2; // трием помощния масив
		//използвахме го, вече не ни трябва и чао
		//не правете така с приятелите си
	}

public:
	
	Food_Stall<T>() // по подразбиране ще имаме масив с големина 10
	{
		current = -1;
		capacity = 10;
		product = new T[capacity];
	}

	void add(T const& toadd) //функция за добавяне на нов елемент
	{
		if(current==capacity-1) //ако масива е вече пълен
		{
			resize(); // го уголемяваме
		}

		current++;
		product[current] = toadd;
	}
	
	
	
	int getCurrent() const
	{
		return current;
	}
	
	int getCapacity() const
	{
		return capacity;	
	}
	
	bool checkEmpty() const //помощна функцийка за проверка дали количката е празна... ще ни трябва по-нататък
	{
		if(current==-1) return true;
		else return false;
	}
	
	Food_Stall<T>(Food_Stall<T> const& other) // копи-конструктор
	{
		copy(other);//ХА- явно вече имаме функция за това
		//П.С.: Виж функцията copy
	}
	
	Food_Stall<T>& operator=(Food_Stall<T> const& other) // оператор =
	{

		if (this != &other)//тривиална проверка
		{
			//ако влезем тук
			remove();//първо ще изтрием масива от продукти
			//П.С.: Виж функцията remove
			copy(other); // копирането отново се появява, явно е било полезно да го напишем
			//ПС.: Виж функцията copy, ако не си, крайно време е...
		}

		return *this; //трябва да го "върнем"
	}


	~Food_Stall<T>() //стандартен деструктор
	{
		remove();//нали разбра какво прави вече...
	}
	
	friend ostream& operator<<(ostream& os, const Food_Stall<T>& stall) // трябва ни и оператор <<
	{
		if(stall.current<0) os<<"Empty food stall!"<<endl; // ако количката е празна ще си кажем
		else
		{	//ако не е
			os<<"Food stall:"<<endl;
			for(int i=0; i<=stall.current; i++) 
			os<<i+1<<". "<<stall.product[i];		
			//ще принтираме всички елементи от нея
		}
		
		return os;
	}
	
};



template<typename T, typename K>
class Food_Stall_D //вариант с два вида продукти. Почти като да сме умножили предишния клас по 2
{
	T* productT; //единия вид
	int currentT; 
	int capacityT; 
	
	K* productK;//другия вид
	int currentK;
	int capacityK;

	void copy(Food_Stall_D<T,K> const& other) //отново копираща функция, само че този път ще се справим и с двата масива
	{
		currentT = other.currentT;
		capacityT = other.capacityT;

		productT = new T[capacityT];
		for (int i = 0; i <= currentT; i++)
			productT[i] = other.productT[i];
			
		currentK = other.currentK;
		capacityK = other.capacityK;

		productK = new K[capacityK];
		for (int i = 0; i <= currentK; i++)
			productK[i] = other.productK[i];
	}
	
	

	void removeT()//remove за единия масив
	{
		delete[] productT;
	}
	
	void removeK() //remove за другия масив
	{
		delete[] productK;
	}
  
  	void resizeT() //resize за единия масив
	{
		//същата схема
		T *productT2 = new T[capacityT];
		
		for (int i = 0; i <= currentT; i++)
		{
			productT2[i] = productT[i];
		}
		
		productT = new T[capacityT*2];
		
		for(int i = 0; i <= currentT; i++)
		{
				productT[i] = productT2[i];
		}
		
		capacityT*=2;
		delete [] productT2;
	}
	
	
	void resizeK() //resize за другия масив
	{
		K *productT2 = new K[capacityK];
		
		for (int i = 0; i <= currentK; i++)
		{
			productT2[i] = productK[i];
		}
		
		productK = new K[capacityK*2];
		
		for(int i = 0; i <= currentK; i++)
		{
				productK[i] = productT2[i];
		}
		
		capacityK*=2;
		delete [] productT2;
	}
public:
	
	
	
	Food_Stall_D<T,K>() // и двата масива ще ги правим с големина 10
	{
		currentT = -1;
		capacityT = 10;
		productT = new T[capacityT];
		
		currentK = -1;
		capacityK = 10;
		productK = new K[capacityK];
	}

	void add(T const& item) // добавяне на елемент от тип Т
	{
		if(currentT==capacityT-1)
		{
			resizeT();
		}

		currentT++;
		productT[currentT] = item;
	}
	
	
	void add(K const& item) // добавяне на елемент от тип К
	{
		if(currentK==capacityK-1)
		{
			resizeK();
		}

		currentK++;
		productK[currentK] = item;
	}
	
	//Надявам се читателя да не е крайно изненадан от двете функции с едно и също име...
	
	int getCurrent() const
	{
		return (productT.getCurrent() + productK.getCurrent());
	}
	
	int getCurrentT() const
	{
		return productT.getCurrent();
	}
	
	int getCurrentK() const
	{
		return productK.getCurrent();
	}
	
	Food_Stall_D<T,K>(Food_Stall_D<T,K> const& other) // копи конструктор
	{
		copy(other);
	
	}
	
	Food_Stall_D<T,K>& operator=(Food_Stall_D<T,K> const& other) // ии оператор =
	{
		if (this != &other)
		{
			removeT();
			removeK();
			copy(other);
		}

		return *this;
	}



	~Food_Stall_D<T,K>() // ще трябва и двата масива да изтрием
	{
		removeT();
		removeK(); 
	}
	
	
	
	friend ostream& operator<<(ostream& os, const Food_Stall_D<T,K>& stall) //Тук ще принтираме последователно двата вида
	//Ще изглежда като нещо от 
	//1. нещо от тип 1
	//2. нещо друго от тип 1
	//3. нещо от тип 2
	//... и тн
	{

		if(stall.currentT<0 and stall.currentK<0) os<<"Empty food stall!"<<endl;
		else
		{
			os<<"Food stall:"<<endl;
			for(int i=0; i<=stall.currentT; i++) 
				os<<i+1<<". "<<stall.productT[i];

			for(int i=0; i<=stall.currentK; i++) 
				os<<i+2+stall.currentT<<". "<<stall.productK[i];		
		}
		return os;
	}

};

template<typename T, typename K>
class Food_Stall_2 //Тук ще реализаме количка с два вида продукти като използваме вече готовата структура Food_Stall (Малко по-нагоре)
{
	Food_Stall<T> stallT;//единия тип продукт
	Food_Stall<K> stallK;//втория тип продукт
	
public:
	
	Food_Stall_2<T,K>()
	{
		//защо ли нямаме нищо в конструктора
		//трябва ли да имаме нещо?
	}
	
	void add(T const& itemT) //добавяне на елемент от единия тип
	{
		stallT.add(itemT);
	}
	
	void add(K const& itemK) //добавяне на нещо от втория тип
	{
		stallK.add(itemK);
	}
	
	int getCurrent() const
	{
		return (stallT.getCurrent() + stallK.getCurrent());
	}
	
	int getCurrentT() const
	{
		return stallT.getCurrent();
	}
	
	int getCurrentK() const
	{
		return stallK.getCurrent();
	}
	
	friend ostream& operator<<(ostream& os, const Food_Stall_2<T,K>& stall) //Тук ще принтираме по различен начин от предишната реализация
	//нека любопитния читател да провери как
	{
		if(stall.stallT.checkEmpty() and stall.stallK.checkEmpty()) os<<"Empty food stall!"<<endl;
		else if(stall.stallT.checkEmpty()) os<<stall.stallK;
		else if(stall.stallK.checkEmpty()) os<<stall.stallT;
		else
		{
			os<<"Food stall:"<<endl;
			os<<"First section of ";
			os<<stall.stallT;
			os<<"Second section of ";
			os<<stall.stallK<<endl;
			
		}
		
		return os;
	}

};

int main() {

//проверки на каквото се сетите
Water w;
w.setpH(6);
w.setMilliliters(500);
cout<<w<<endl;

Beer b(500,3);
cout<<b<<endl;
b.setAlc(4);
cout<<b<<endl;

Broccoli br;
cout<<br<<endl;
br.setGrams(777);
br.setBoiled(true);
cout<<br<<endl;

Pizza p(900,false,false);
cout<<p<<endl;
p.setBothVeggieAndSpicy(true,true);
cout<<p<<endl;

Food_Stall<Broccoli> fb;
cout<<fb<<endl;
fb.add(br);
cout<<fb;
for(int i=0; i<15; i++) fb.add(br); //целта ни е да проверим дали масива се разширява "като хората"
cout<<fb<<endl;


Food_Stall_D<Broccoli,Pizza> fdp;
cout<<fdp<<endl;
fdp.add(br);
cout<<fdp<<endl;
fdp.add(p);
cout<<fdp<<endl;

for(int i=0; i<12; i++) fdp.add(br);//същата цел като предишната
cout<<fdp<<endl;

for(int i=0; i<12; i++) fdp.add(p);
cout<<fdp<<endl;

Food_Stall_2<Water,Pizza> fd2;// и отново
cout<<fd2;
fd2.add(w);
cout<<fd2;
fd2.add(p);
cout<<fd2;

for(int i=0; i<12; i++) //интересна цел сме си избрали
{
	fd2.add(w);
	fd2.add(p);
}
cout<<fd2;

	return 0;
}