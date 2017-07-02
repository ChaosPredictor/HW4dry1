//============================================================================
// Name        : HW4dry1.cpp
// Author      : kuzi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>

using namespace std;

template<class T>
class Larger {
	T i;
public:
	Larger(T i) : i(i) {};
	bool operator()(const T& i, const T& j) const {
		return i < j;
	}
};


template<class T, class Function>
std::list<T> func1(std::list<T> list1, std::list<T> list2, Function f) {

	typename std::list<T>::iterator it1 = list1.begin();
	typename std::list<T>::iterator it2 = list2.begin();

	std::list<T>* result_list = new std::list<T>;

	while ( it1 != list1.end() || it2 != list2.end()) {
		if ( it2 == list2.end() ) {
			result_list->insert(result_list->end(), *it1);
			++it1;
		} else if ( it1 == list1.end() ) {
			result_list->insert(result_list->end(), *it2);
			++it2;
		} else {
			if ( f(*it1, *it2) ) {
				result_list->insert(result_list->end(), *it2);
				++it2;
			} else {
				result_list->insert(result_list->end(), *it1);
				++it1;
			}
		}
	}

	return *result_list;
}

template<class T>
void print(std::list<T> list) {
	std::cout << std::endl;
	typename std::list<T>::iterator it;
	for(it = list.begin(); it != list.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}



int main() {
	std::list<int> list1 = {99,97,95,93,91,50,10};
	print(list1);

	std::list<int> list2 = {100,98,96,94,92,80,70,7,6,5,4,2};

	std::list<int> result_list;
	//Larger;
	result_list = func1(list1, list2, Larger<int>(1));
	print(result_list);



	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
