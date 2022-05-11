//#include "Vector.h"
//
//const int DEFAULT = 4;
//
//void Vector::copy(const Vector& other)
//{
//	size_ = other.size_;
//	capacity_ = other.capacity_;
//	array_ = new element[capacity_];
//
//	for (int i = 0; i < size_; i++)
//	{
//		array_[i] = other.array_[i];
//	}
//}
//
//void Vector::clear()
//{
//	delete[] array_;
//	array_ = nullptr;
//}
//
//Vector::Vector(int capacity)
//	: size_(0)
//	, capacity_(std::max(capacity, DEFAULT))
//	, array_(new element[capacity_])
//{}
//
//Vector::Vector(const Vector& other)
//{
//	copy(other);
//}
//
//Vector& Vector::operator=(const Vector& other)
//{
//	if (this != &other)
//	{
//		clear();
//		copy(other);
//	}
//	return *this;
//}
//
//Vector::~Vector()
//{
//	clear();
//}
//
//inline int Vector::size() const
//{
//	return size_;
//}
//
//inline int Vector::capacity() const
//{
//	return capacity_;
//}
//
//inline element& Vector::at(int index)
//{
//	return array_[index];
//}
//
//inline const element& Vector::at(int index) const
//{
//	return array_[index];
//}
//
//void Vector::push_back(const element& element_)
//{
//	if (size_ >= capacity_)
//	{
//		reserve(capacity_ * 2);
//	}
//
//	array_[size_] = element_;
//	++size_;
//}
//
//void Vector::erase(int index)
//{
//	--size_;
//	for (int i = index; i < size_; i++)
//	{
//		array_[i] = array_[i + 1];
//	}
//}
//
//void Vector::reserve(int capacity)
//{
//	if (capacity > capacity_)
//	{
//		capacity_ = capacity;
//		element* anotherArray_ = new element[capacity];
//
//		for (int i = 0; i < size_; i++)
//		{
//			anotherArray_[i] = array_[i];
//		}
//
//		delete[] array_;
//		array_ = anotherArray_;
//	}
//}
//
//void Vector::serialize(std::ofstream& out) const
//{
//	out.write((const char*)&size_, sizeof(array_));
//	out.write((const char*)&capacity_, sizeof(capacity_));
//
//	for (int i = 0; i < size_; i++)
//	{
//		array_[i].serialize(out);
//	}
//}
//
//void Vector::deserialize(std::ifstream& in)
//{
//	clear();
//	in.read((char*)&size_, sizeof(size_));
//	in.read((char*)&capacity_, sizeof(capacity_));
//	array_ = new element[capacity_];
//	for (int i = 0; i < size_; i++)
//	{
//		array_[i] = element(in);
//	}
//}
//
//element& Vector::operator[](int index)
//{
//	return at(index);
//}
//
//const element& Vector::operator[](int index) const
//{
//	return at(index);
//}
//
//Vector& Vector::operator+=(const element& elem_)
//{
//	push_back(elem_);
//	return *this;
//}
//
//Vector& Vector::operator+=(const Vector& other)
//{
//	reserve(size_ + other.size_);
//	for (int i = 0; i < other.size_; i++)
//	{
//		*this += other[i];
//	}
//	return *this;
//}
//
//std::ostream& operator<<(std::ostream& out, const Vector& object)
//{
//	out << "[ ";
//
//	if (object.size() >= 1)
//	{
//		out << object[0];
//	}
//
//	for (int i = 1; i < object.size(); i++)
//	{
//		out << ", " << object[i];
//	}
//
//	out << " ]";
//	return out;
//}
