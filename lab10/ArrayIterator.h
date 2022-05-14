#pragma once

template<class T>
class ArrayIterator
{
public:
	T** p;
	int Current;
	int Last;
public:
	ArrayIterator();
	ArrayIterator& operator++ ()
	{
		++Current;
		return *this;
	}
	ArrayIterator& operator-- ()
	{
		--Current;
		return *this;
	}
	bool operator= (ArrayIterator<T>& tmp);
	bool operator!=(ArrayIterator<T>& tmp);
	T* GetElement();
	T* operator* ();
};


template<class T>
inline ArrayIterator<T>::ArrayIterator() : Current{0}
{
}

template<class T>
inline bool ArrayIterator<T>::operator=(ArrayIterator<T>& tmp)
{
	return false;
}

template<class T>
inline bool ArrayIterator<T>::operator!=(ArrayIterator<T>& tmp)
{
	return Current != Last;
}

template<class T>
inline T* ArrayIterator<T>::GetElement()
{
	return p[Current];
}

template<class T>
inline T* ArrayIterator<T>::operator*()
{
	return GetElement();
}
