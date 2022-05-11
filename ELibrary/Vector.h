//#pragma once
//#include <iostream>
//#include <fstream>
//#include "Library.h"
//
//typedef Library element;
//
//class Vector {
//private:
//	int size_;
//	int capacity_;
//	element* array_;
//
//public:
//	Vector(int capacity_ = 0);
//	Vector(const Vector& other);
//	Vector& operator = (const Vector& other);
//	~Vector();
//
//	//Methods:
//	inline int size() const;
//	inline int capacity() const;
//	inline element& at(int index);
//	inline const element& at(int index) const;
//
//	void push_back(const element& element_);
//	void erase(int index);
//	void reserve(int capacity);
//	void serialize(std::ofstream& out) const;
//	void deserialize(std::ifstream& in);
//
//	//Operators
//	element& operator[](int index);
//	const element& operator[](int index) const;
//	Vector& operator+=(const element& elem_);
//	Vector& operator+=(const Vector& other);
//
//private:
//	void copy(const Vector& other);
//	void clear();
//};
//
//std::ostream& operator<<(std::ostream& out, const Vector& object);
