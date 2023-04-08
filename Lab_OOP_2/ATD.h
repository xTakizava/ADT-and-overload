#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class ATD {     
private:
	char* array;
	int size;
	int current;
	void Resize(int newSize) {
		char* newArray = new char[newSize];
		for (int i = 0; i < current; i++) {
			newArray[i] = array[i];
		}
		delete[]array;
		array = newArray;
		current = newSize;
	}
public:
	//constructors
	ATD(int size) {
		this->array = new char[size];
		this->size = size;
		this->current = 0;
	}
	ATD(const ATD& e) {
		this->size = e.size;
		this->current = e.current;
		this->array = new char[this->size];
		memcpy(this->array, e.array, this->current * sizeof(char));
	}
	~ATD() {
		delete[] this->array;
	}
	//methods
	bool Contains(const char e) const {
		for (int i = 0; i < current; i++) {
			if (array[i] == e) {
				return true;
			}
		}
		return false;
	}
	int IndexOf(const char e) const {
		for (int i = 0; i < current; i++) {
			if (array[i] == e) {
				return i;
			}
		}
		return -1;
	}
	void Insert(const char element) {
		if (!Contains(element)) {
			if (current == size) {
				Resize(size * 2);
			}
			array[current++] = element;
		}
	}
	void Remove(const char element) {
		int index = IndexOf(element);
		if (index != -1) {
			for (int i = index; i < current - 1; i++) {
				array[i] = array[i + 1];
			}
			current--;
		}
	}
	bool Add(char e) {
		if (this->current == this->size)
			return false;
		for (int i = 0; i < this->current; i++)
			if (this->array[i] == e)
				return false;
		this->array[this->current] = e;
		this->current++;
		return true;
	}
	void Print() {
		if (current == 0) {
			cout << "{N}\n" << endl;
			return;
		}
		cout << "{";
		for (int i = 0; i < current - 1; i++)
			cout << array[i] << ", ";
		cout << array[current - 1] << "}\n";
	}
	void Input() {
		cout << "Input size: ";
		int s;
		cin >> s;
		cout << "Input " << s << " element of ATD ex:" << endl;
		for (int i = 0; i < s; i++) {
			char v;
			cin >> v;
			Add(v);
		}
	}
	//operators with overload
	ATD operator+(char e) {
		ATD result(this->size);
		for (int i = 0; i < this->current; i++)
			result.Add(this->array[i]);
		result.Add(e);
		return result;
	}
	ATD operator+(const ATD& e) {
		ATD result(this->size);
		for (int i = 0; i < this->current; i++)
			result.Add(this->array[i]);
		for (int i = 0; i < e.current; i++)
			result.Add(this->array[i]);
		return result;
	}
	bool operator==(const ATD& e) const {
		if (this->current != e.current)
			return false;
		for (int i = 0; i < current; i++) {
			bool flag = false;
			for (int j = 0; j < e.current; j++) {
				if (this->array[i] == e.array[j]) {
					flag = true;
					break;
				}
			}
			if (!flag)
				return false;
		}
		return true;
	}
	ATD& operator=(const ATD& e) {
		if (this != &e) {
			delete[] this->array;
			this->size = e.size;
			this->current = e.current;
			this->array = new char[this->size];
			memcpy(this->array, e.array, this->current * sizeof(char));
		}
		return *this;
	}
	ATD& operator+=(const char e) {
		Insert(e);
		return *this;
	}
	ATD& operator+=(const ATD& e) {
		for (int i = 0; i < e.current; i++) {
			Insert(e.array[i]);
		}
		return *this;
	}
};