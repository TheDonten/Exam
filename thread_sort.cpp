#include "pch.h"
#include <list>
#include <future>
#include <algorithm>
#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <chrono>

void quickSort(std::vector<int>& array, int left, int right) {
	
	int l = left;
	int r = right;
	int main_el = l;
	while (l <= r) {
		while (array[l] < array[main_el]) l++;
		while (array[r] > array[main_el]) r--;
		if (l <= r) {
			std::swap(array[l], array[r]);
			l++;
			r--;
		}
	}

	if (l < right && left == 0 && right == array.size() - 1) {
		std::thread t1(&quickSort,std::ref(array), l, right);
		t1.join();
		//quickSort(array, l, right);
	}
	else if (l < right) {
		quickSort(array, l, right);
	}
	if (r > left) {
		quickSort(array, left, r);
	}
	
}
int main() {
	srand(time(0));
	std::vector<int> v1;
	v1.resize(20000);
	for (int i = 0; i < 20000; ++i) {
		v1[i] = rand() % 10000;
	}
	auto now = std::chrono::high_resolution_clock::now();
	quickSort(v1 , 0, v1.size() - 1);
	auto clos = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(clos - now);
	int time = duration.count();
	std::cout << std::endl;

	std::cout << " Time=  " << time << std::endl;

}
