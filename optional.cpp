// something.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
class Naxui {
public:
	Naxui() {
		heh = nullptr;
	}

	Naxui(std::string &&a)  {
		heh = new daughter_class(a);
	}
	class Base_class {


	public:
		std::string meh;
		Base_class() {
			std::cout << "base_class" << std::endl;
		}
		Base_class(std::string name) : meh(name) {
			//meh = name;
			std::cout << "base_class" << std::endl;
		}
		virtual void write(std::string name) {
			std::cout << name << std::endl;
		
		}
		virtual void out() const {
			std::cout << meh << std::endl;
		}
		//	 virtual void out() const = 0;
		~Base_class() {
			std::cout << "delete base_class" << std::endl;
		}
	};
	class daughter_class : public Base_class {


	public:
		std::string meheh;
		daughter_class() {
			std::cout << "daughter_class" << std::endl;
		}
		daughter_class(std::string name) : Base_class(name)
		{
			std::cout << "daughter_class" << std::endl;
		
		}
		void write(std::string name)  override {
			std::cout << name << std::endl;
			//meheh = name;
		}
		void out() const {
			std::cout << meheh << std::endl;
		}
		~daughter_class() {
			std::cout << "delete daughter" << std::endl;
		}
	};
private:
	Base_class* heh;
};
int main()
{
	Naxui a("sukas");
	
	//std::string name = { "kek" };
	
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
