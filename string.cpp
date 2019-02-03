// class_string.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
class string {
private:
	std::size_t size;
	char * str;
	
public:
	string() = default;
	string(const string & other) {
		if (other.size > 0) {
			str = new char[other.size];
			str = other.str;
	  }
	}
	string(const char * s) {
		if (sizeof(s) > 0) {
			size = strlen(s);
			str = new char[strlen(s)];
			for (auto i = 0; i < strlen(s); ++i) {
				str[i] = s[i];
			}
			
		}
	}
	string & operator = (const string& other) {
		if (other.size > 0) {
			delete[] str;
			size = other.size;
			str = new char[other.size];
			str = other.str;
			
		}
		return *this;
	}
	string & operator = (const string && other) {
		if (other.size > 0) {
		
			size = other.size;
			str = std::move(other.str);
			
		}
		return *this;
	}
	char& operator [] (const std::size_t & n) const {
		if (n > size)
			std::cout << "out put of range" << std::endl;
		else return str[n];
	}
	char* & begin() {
		char * p = &str[0];
		return p;
	}
	char *& end() {
		char * p = &str[size - 1];
		return p;
	}
	template <typename Iterator>
	string & append(Iterator first, Iterator second) {
		char * mas = new char[size + (second - first)];
	
		for (int i = 0; i < size; ++i) {
			mas[i] = str[i];
		}
		delete[] str;
		str = mas;
		int k = 0;
		
	
		while (first != second) {
			str[size + k] = *first;
			++first;
			++k;
		}
		size = size + k;
		for (int i = 0; i < size; ++i) {
			std::cout << str[i] << std::endl;
		}
		return *this;
	}
	template <typename Iterator>
	string & replace(const Iterator f1, const Iterator s1, Iterator f2, Iterator s2) {
		std::size_t now = size - (s1-f1) - 1;
		char* mas = new char[now + (s2 - f2)];
		std::cout << now << std::endl;
		for (auto i = 0; i < now ; ++i) {
			mas[i] = str[i];
		}
		delete[] str;
		str = mas;
		int k = 0;
		while(f2 != s2) {
			str[now + k] = *f2;
			++f2;
			++k;
		}
		size = now + k;
		for (int i = 0; i < size; ++i) {
			std::cout << str[i];
		}
		return *this;
	}
	~string() {
		std::cout << "Destructor" << std::endl;
		size = NULL;
		delete[] str;
		std::cout << "Destructor was good" << std::endl;
	}
};
int main()
{
	char s[6] = { "abcd" };
	//std::cout << sizeof(s);
	string A("abcdet");
	string B("suka you");
	A.append(B.begin(), B.end());
	A.replace(A.begin() + 2, A.end(), B.begin(), B.end() - 2);
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
