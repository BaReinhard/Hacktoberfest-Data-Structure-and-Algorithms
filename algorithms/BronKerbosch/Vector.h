#ifndef __Vector__
#define __Vector__
#include <iostream>

using namespace std;

template <class T>
class Vector
{
public:

	typedef T* iterator; //iterator

	Vector();
	/* Constructor fara argument */
	Vector(unsigned int size); // Constructor cu argument
	Vector(const Vector<T> &v); // Copy constructor
	~Vector();

	unsigned int myCapacity() const;
	/* returneaza capacitatea
	(cate elemente incap in vector)
	*/
	unsigned int mySize() const;
	/* returneaza marimea
	*(numarul de elemente din vector)
	*/
	bool empty();

	iterator begin();
	iterator end();

	T& front();
	T& back();

	void push_back(const T& value); //adauga un nou element
	void pop_back(); // sterge ultimul element din vector

	T& operator[](unsigned int i);
	Vector<T> & operator=(const Vector<T> &v);

private:
	unsigned int capacity;
	unsigned int size;
	T *array;
};

template <class T>
Vector<T>::Vector()
{
	capacity = 0;
	size = 0;
	array = NULL;
}

template<class T>
Vector<T>::Vector(const Vector<T> &v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	array = new T[capacity];

	for(int i = 0 ; i< size; ++i)
	{
		array[i] = v.array[i];
	}
}

template <class T>
Vector<T>::Vector(unsigned int size)
{
	this->capacity = size;
	this->size = 0;
	array = new T[this->capacity];
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return array;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
	return array + mySize();
}

template <class T>
unsigned int Vector<T>::mySize()const
{
	return this->size;
}

template <class T>
unsigned int Vector<T>::myCapacity()const
{
	return this->capacity;
}

template <class T>
void Vector<T>::push_back(const T & value)
{
	if( size == capacity)
	{
		T *tmpArray = new T[ 2*capacity ];

		for(int i = 0; i < size; i++)
		{
			tmpArray[i] = array[i];
		}

		if(array != NULL)
			delete[] array;

		array = tmpArray;
		capacity = 2 * capacity;

		if(capacity == 0)
		{
			capacity = 1;
		}
	}

	array[size] = value;
	size++;
}

template <class T>
void Vector<T>::pop_back()
{
	this->size--;
}

template <class T>
bool Vector<T>::empty()
{
	if(size == 0)
		return 1;
	return 0;
}

template <class T>
Vector<T>::~Vector()
{
	delete[] array;
}

template <class T>
Vector<T> & Vector<T>::operator=(const Vector<T> &v)
{
	delete[] array;
	this->size =  v.size;
	this->capacity = v.capacity;
	array = new T[this->capacity];

	for(int i = 0; i < this->size; i++)
	{
		array[i] = v.array[i];
	}

	return *this;
}

template <class T>
T& Vector<T>::operator[](unsigned int i)
{
	return array[i];
}
#endif
