#pragma once
#include "MyException.h"
#include "Compare.h"
#include "ArrayIterator.h"

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray); // constructor de copiere

	T& operator[] (int index); // arunca exceptie daca index este out of range
	const T& operator[] (int index) const;

	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator=(const Array<T>& otherArray);

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

	int GetSize();
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();

	ArrayIterator<T> begin();
	ArrayIterator<T> end();
};

template<class T>
inline Array<T>::Array() : List{ nullptr }, Capacity{ 0 }, Size{0}
{
}

template<class T>
inline Array<T>::~Array()
{
	for (int i{ 0 }; i < Size; ++i)
	{
		delete List[i];
	}

	delete[] List;
}

template<class T>
inline Array<T>::Array(int capacity)
{
	if (capacity <= 0)
		throw MyException{ "Eroare: Capacitatea nu poate fi negativa!!" };

	Capacity = capacity;
	Size = 0;
	List = new T * [capacity];
}

template<class T>
inline Array<T>::Array(const Array<T>& otherArray) : Array{otherArray.Capacity}
{
	for (int i{ 0 }; i < otherArray.Size; ++i)
	{
		List[i] = new T{ *(otherArray.List[i]) };
	}

	Size = otherArray.Size;
}

template<class T>
inline T& Array<T>::operator[](int index)
{
	if (index >= Size)
		throw MyException{ "Eroare: Index is out of range" };

	return *(List[index]);
}

template<class T>
inline const T& Array<T>::operator[](int index) const
{
	if (index >= Size)
		throw MyException{ "Eroare: Index is out of range" };

	return *(List[index]);
}

template<class T>
inline const Array<T>& Array<T>::operator+=(const T& newElem)
{
	if (Size + 1 > Capacity)
		throw MyException{ "Eroare: Ati atins limita de elemente!!" };

	List[Size] = new T{newElem};
	++Size;
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	if(Size + 1 > Capacity)
		throw MyException{ "Eroare: Ati atins limita de elemente!!" };

	for (int i{ Size - 1 }; i >= index; --i)
	{
		List[i + 1] = List[i];
	}

	List[index] = new T{ newElem };
	++Size;
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	for (int i{ 0 }; i < otherArray.Size; ++i)
	{
		Insert(index+i, otherArray[i]);
	}
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Delete(int index)
{
	if (index >= Size)
		throw MyException{ "Index out of range" };

	delete List[index];

	for (int i{ index }; i < Size - 1; ++i)
	{
		List[i] = List[i + 1];
	}

	--Size;

	return *this;
}

template<class T>
inline bool Array<T>::operator=(const Array<T>& otherArray)
{
	delete[] List;
	Capacity = otherArray.Capacity;
	Size = otherArray.Size;
	List = new T * [Capacity];

	for (int i{ 0 }; i < otherArray.Size; ++i)
	{
		List[i] = new T{ *(otherArray.List[i]) };
	}
	return true;
}

template<class T>
inline void Array<T>::Sort()
{
	for (int i{ 0 }; i < Size - 1; ++i)
	{
		for (int j{ 0 }; j < Size -1 ; ++j)
		{
			if (*(List[j]) > *(List[j+1]))
			{
				T* temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
		}
	}
}

template<class T>
inline void Array<T>::Sort(int(*compare)(const T&, const T&))
{
	for (int i{ 0 }; i < Size - 1; ++i)
	{
		for (int j{ 0 }; j < Size - 1; ++j)
		{
			if (compare(*(List[j]), *(List[j+1])) < 0)
			{
				T* temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
		}
	}
}

template<class T>
inline void Array<T>::Sort(Compare* comparator)
{
	for (int i{ 0 }; i < Size - 1; ++i)
	{
		for (int j{ 0 }; j < Size - 1; ++j)
		{
			if (comparator.CompareElements(*(List[j]), *(List[j+1])) < 0)
			{
				T* temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
		}
	}
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem)
{
	Sort();

	int l{ 0 };
	int r{ Size - 1 };

	while (l <= r) 
	{
		int m = l + (r - l) / 2;

		if (*(List[m]) == elem)
			return m;

		if (*(List[m]) < elem)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	Sort();

	int l{ 0 };
	int r{ Size - 1 };

	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (compare(*(List[m]), elem) == 0)
			return m;

		if (compare(*(List[m]), elem) > 0)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	Sort();

	int l{ 0 };
	int r{ Size - 1 };

	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (comparator->CompareElements(*(List[m]), elem) == 0)
			return m;

		if (comparator->CompareElements(*(List[m]), elem) > 0)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem)
{
	for (int i{ 0 }; i < Size; ++i)
	{
		if (elem == *(List[i]))
			return i;
	}
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	for (int i{ 0 }; i < Size; ++i)
	{
		if (compare(elem, *(List[i])) == 0)
			return i;
	}
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, Compare* comparator)
{
	for (int i{ 0 }; i < Size; ++i)
	{
		if (comparator->CompareElements(elem, *(List[i])) == 0)
			return i;
	}
	return -1;
}

template<class T>
inline int Array<T>::GetSize()
{
	return Size;
}

template<class T>
inline int Array<T>::GetCapacity()
{
	return Capacity;
}

template<class T>
inline ArrayIterator<T> Array<T>::GetBeginIterator()
{
	return begin();
}

template<class T>
inline ArrayIterator<T> Array<T>::GetEndIterator()
{
	return end();
}

template<class T>
inline ArrayIterator<T> Array<T>::begin()
{
	ArrayIterator<T> tmp{};
	tmp.p = List;
	tmp.Last = Size;

	return tmp;
}

template<class T>
inline ArrayIterator<T> Array<T>::end()
{
	ArrayIterator<T> tmp{};
	tmp.p = List;
	tmp.Last = Size;
	tmp.Current = Size - 1;
	return tmp;
}
