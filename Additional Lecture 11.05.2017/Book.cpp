#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Page //Началния клас, страница
{
	int format;
public:
// <Конструктори>
	Page()
	{
		format=4;
	}
	
	Page(int _format)
	{
		format=_format;
	}
	
	Page(const Page& other)
	{
		format=other.format;
	}
// </Конструктори>

// <Сетъри+Гетъри>	
	
	int getFormat() const
	{
		return format;
	}
	
	void setFormat(int _format)
	{
		format=_format;
	}
// <оператор << >	
	friend ostream& operator<<(ostream& os, const Page& other)
	{
		os<<"Format:"<<other.format<<endl;
		return os;
	}
// </оператор << >
};


class Text: public Page // класът Text, наследява Page
{
private:
	char *text; // ще трябва да се оправим с динамичната памет
 	unsigned pagenum;
public:
	
// <ГОЛЯМА четворка + конструктор с параметри>	

Text(): Page()
{
	text= new char[5];
	strcpy(text, "Text");
	pagenum=1;
}

Text(char* _text , unsigned _pagenum, int _format) : Page(_format) 
	{
		text = new char[strlen(_text)+1];
 		strcpy(text, _text);
		pagenum=_pagenum;
	}
	
~Text()
	{
	 	delete [] text;
	}
	
Text(const Text& other) : Page(other)
	{
		text = new char[strlen(other.text)+1];
	 	strcpy(text, other.text);
	 	pagenum=other.pagenum;
	}	
	
Text& operator=(const Text& other)
{	
	if (this != &other)
 		{
 			Page::operator= (other); 
		 	delete [] text;
			text = new char[strlen(other.text)+1];
			strcpy(text, other.text);
			pagenum = other.pagenum;
 		}
 return *this;
}
// </ ГОЛЯМА четворка + конструктор с параметри>

void setPageNum(unsigned _pagenum)
{
	pagenum=_pagenum;
	}	

void setText(char* _text)
{
	delete [] text;
	text= new char[strlen(_text)+1];
	strcpy(text,_text);
}
char* getText() const
{
	return text;
}

int getPageNum() const
{
	return pagenum;
}

friend ostream& operator<<(ostream& os, const Text &other)
{
	os<<"---------------"<<endl;
	os<<other.text<<endl<<"Page: "<<other.pagenum<<endl;
	os<<"---------------"<<endl;
 	return os;
}
};



class Cover: public Page //Заглавна страница
{
private:
	char *title; // аналогично пак трябва да се справим с динамичната памет
public:
	
	
	char* getTitle() const
	{
		return title;
	}
	
	void setTitle(char* _title)
	{
		delete [] title;
		title= new char[strlen(_title)+1];
		strcpy(title,_title);
	}
	
	
Cover(): Page()
{
	title= new char[5];
	strcpy(title, "LOTR");

}

Cover(char *_title ,int _format) : Page(_format) 
	{
		title = new char[strlen(_title)+1];
 		strcpy(title, _title);
	
	}
	
~Cover()
	{
	 	delete [] title;
	}
	
Cover(const Cover& other) : Page(other)
	{
		title = new char[strlen(other.title)+1];
	 	strcpy(title, other.title);
	 
	}	
	
Cover& operator=(const Cover& other)
{	
	if (this != &other)
 		{
 			Page::operator= (other); 
		 	 delete [] title;
			 title = new char[strlen(other.title)+1];
			 strcpy(title, other.title);
		
 		}
 return *this;
}

friend ostream& operator<<(ostream& os, const Cover &other)
{
	os<<"---------------"<<endl;
	os<<other.title<<endl<<endl;
	os<<"---------------"<<endl;
 	return os;
}
};


class Illustration: public Page //Клас за страница с илюстрация
{
private:
	char *picture; // пак ...
 	unsigned pagenum;
public:
	
Illustration(): Page(4)
{
	picture= new char[5];
	strcpy(picture, "LADA");
	pagenum=1;
}

Illustration(char *m , unsigned y, int f) : Page(f) 
	{
		picture = new char[strlen(m)+1];
 		strcpy(picture, m);
		pagenum=y;
	}
	
~Illustration()
	{
	 	delete [] picture;
	}
	
Illustration(const Illustration& c) : Page(c)
	{
		picture = new char[strlen(c.picture)+1];
	 	strcpy(picture, c.picture);
	 	pagenum=c.pagenum;
	}	
	
Illustration& operator=(const Illustration& c)
{	
	if (this != &c)
 		{
 			Page::operator= (c); 
		 	 delete [] picture;
			 picture = new char[strlen(c.picture)+1];
			 strcpy(picture, c.picture);
			 pagenum = c.pagenum;
 		}
 return *this;
}

friend ostream& operator<<(ostream& os, const Illustration &other)
{
	os<<"---------------"<<endl;
	os<<other.picture<<endl<<"Page: "<<other.pagenum<<endl;
	os<<"---------------"<<endl;
 	return os;
}
};

template<typename T> 
class Book //Шаблонен клас, за Книга
{
	Cover coverpage; //Корица
	T* pages; //Всички останали страници
	int current; // брой страници в момента
	int capacity; // максимален капацитет на масива от страници
	
	void resize() //Функция, която запазва всички страници, но прави масива ни по-голям, за да има повече място за страници
	//все пак кой обича кратки книги
	//Ще използваме на няколко места по-надолу в кода функцията, внимавайте
	{
		T* helper;// помощен масив, тук ще пазим страниците, докато оразмеряваме
		helper = new T[capacity];
		for(int i=0; i<=current; i++) helper[i]=pages[i];
		
		delete [] pages; // ще се отървем от малкия масив за нуждите ни, чак след като сме копирали всичко. Все пак не искаме да губим данни
		
		capacity*=2;
		pages= new T[capacity]; // вече двойно по-голям
		
		for(int i=0; i<=current; i++) pages[i]=helper[i]; //запълваме новия масив със запазените данни
		
		delete [] helper;//освобождаваме се от така полезния помощен масив
	}
	
public:
	
	Book()
	{
		Cover a("Title",4);
		coverpage=a;
		pages = new T[10];
		current=-1;
		capacity=10;
	}
	
	Book(Cover _cover)
	{
		coverpage=_cover;
		pages = new T[10];
		current=-1;
		capacity=10;
	}
	
	Book(const Book& other)
	{
		coverpage=other.coverpage;
		capacity=other.capacity;
		current=other.current;
		pages= new T[capacity];
		for(int i=0; i<=current; i++) pages[i]=other.pages[i];
	}
	
	Book& operator=(const Book& other)
	{	
		if(this!=&other)
		{
			delete [] pages;
			coverpage=other.coverpage;
			capacity=other.capacity;
			current=other.current;
			pages= new T[capacity];
			for(int i=0; i<=current; i++) pages[i]=other.pages[i];
		}
		return *this;
	}
	
	~Book()
	{
		delete [] pages;
	}
	
	
	void add(T& itemtoadd) //добавяме елемент
	{
		if(current== capacity-1)
		{
			resize();
		}
		
		current++;
		pages[current]=itemtoadd;
	}
	
	friend ostream& operator<<(ostream& os, const Book& other)
	{
		
		os<<other.coverpage;
		for(int i=0; i<=other.current; i++) os<<other.pages[i];
		return os;
		
	}
	
};




int main(int argc, char** argv) {

//Проверки за всеки един клас



	Page page;
	cout<<page;
	page.setFormat(3);
	cout<<page;
	Page page2(2);
	cout<<page2;
	
    Text text;
	cout<<text;
	text.setText("Hello, world!");
	text.setPageNum(777);
	cout<<text;
	Text text2("All the way up!",3,4);
	cout<<text2;
	text=text2;
	cout<<text;
	cout<<text2.getText();
	
	Cover cover;
	cout<<cover;
	cover.setTitle("The lord of the rings");
	cover.setFormat(5);
	cout<<cover;
	Cover cover2(cover);
	cout<<cover;
	
	
	Book<Text> book(cover);
	cout<<book;
	for(int i=0; i<15; i++) // Проверяваме дали масива се оразмерява нормално
	book.add(text);
	
	cout<<book;
	return 0;
}