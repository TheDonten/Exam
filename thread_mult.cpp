// thread_mult_matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <chrono>



void create_matrix(int **& other,int size) {
	other = new int*[size];
	for (int i = 0; i < size; ++i) {
		other[i] = new int[size];
		for (int j = 0; j < size; ++j) {
			other[i][j] = rand() % 5 + 1;
		}
	}
}
int** Mult(int param,int size, int **a, int **b, int **c,int* start, int* end)
{
	
	for (int i = start[param]; i < end[param]; i++)
	{
		for (int j = 0; j < size; j++)
		{
			c[i][j] = 0;
			for (int z = 0; z < size; z++)
				c[i][j] += a[i][z] * b[z][j];
		}
	}
	return c;
}
int main()
{
	srand(time(0));

	int** first, **second, **result;
	std::vector<std::thread> ths;
	int  Numbercore = 0;
	std::cout << "write how much core" << std::endl;
	std::cin >> Numbercore;
	int * start = new int[Numbercore];
		int * end = new int[Numbercore];
		start[0] = 0;
	std::cout << "size matrix" << std::endl;
	int size = 0;
	std::cin >> size;
	std::cout << std::endl;
	int q = size / Numbercore;
	int r = size % Numbercore;
	create_matrix(first,size);
	create_matrix(second,size); 
	create_matrix(result,size);
	

	for (int i = 0; i < Numbercore; ++i) {
		end[i] = start[i] + q + (i < r ? 1 : 0);
		std::cout << end[i] << "    ";
		std::cout << start[i] << std::endl;
		ths.push_back(std::thread(&Mult, i, size, std::ref(first), std::ref(second), std::ref(result),start,end));
		if (i < Numbercore - 1)
			start[i + 1] = end[i];
		
	}
	
	auto now = std::chrono::high_resolution_clock::now();
	for (auto& x : ths) {
		x.join();
	}
	auto clos = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; ++i) {		
		for (int j = 0; j < size; ++j) {
			std::cout << result[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(clos - now);
	int time = duration.count();
	std::cout << std::endl;
	std::cout << " Time=  " << time << std::endl;
	for (int i = 0; i < size; ++i)
		delete[] first[i];
		delete[] first;
		for (int i = 0; i < size; ++i)
			delete[] second[i];
		delete[] second;
		for (int i = 0; i < size; ++i)
			delete[] result[i];
		delete[] result;
		system("pause");
		//ths.push_back(std::thread(&foo, i));

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
