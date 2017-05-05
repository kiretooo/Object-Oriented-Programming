# Допълнителна лекция по ООП

В тази лекция бяха разгледани реализирането на класове, използването на шаблони, наследяване и предефинирането на опратори

## Във файла Points.cpp 
можете да намерите два семпли класа, реализиращи точки, целящи да опишат възможно най-кратко и ефективно шаблоните и наследяването.
Point е шаблонен клас, реализиращ точка в двумерното пространство, а Point3D е клас, наследяващ Point, в който е включена още една координата на вече двумерната точка.

## Във файла Food_Stall.cpp
можете да намерите реализацията на следната задача:

Раджеш Иванов решил да припечели малко пари и след дълго проучване установил, че най-лесно ще го постигне, ако си отвори „количка за храна“ на Витошка. Прочел, че не е добре да обърква клиентите с прекалено голям избор, и за това се спрял на 4 продукта:
 
 * Вода
 
 * Бира
 
 * Броколи
 
 * Пица
 
За съжаление, обаче, нямал пари за достатъчно добра количка, която да побира от всички продукти и да ги съхранява коректно. За това той продавал по точно един вид продукт всеки ден. 
Предполагам, че сами се досещате, че тази бизнес стратегия не е от най-добрите. Раджеш задлъжнял и трябвало да намери начин да се измъкне от ситуацията. Сетил се за братовчед си Петър Кутрапали, който бил програмист и го помолил заедно да реализират няколко структури, които да са в помощ на „продавачите на колички“...
Да се реализират следните класове:

 * Drinkable- с член данна милилитри, подходящи конструктори, сетъри, гетъри и оператор <<
 
 * Eatable- с член данна грамове, подходящи конструктори, сетъри, гетъри и оператор <<
 
 * Water, Beer- наследяват Drinkable, водата има PH, а бирата алкохолно съдържание
 
 * Broccoli, Pizza- наследяват Eatable, броколите могат да са варени или печени, а пицата да е вегетарианска  или люта
 
 * Food_Stall- шаблонен клас, който съдържа масив от някакъв вид храна или напитка, да се реализира голяма четворка, функция за добавяне на продукт към количката , оператор << и всички останали необходими функционалности като оразмеряване на масива от продукти и т.н.
 
 * Food_Stall2- клас за продавачите, които могат да държат по 2 различни продукта в количките си.

За класа Food_Stall2 има две реализации(* Food_stall_2 * и * Food_stall_D *), като ще оставим на читателя да избере коя е по-добра и има ли изобщо добра реализация на съответната структура в приложения код.