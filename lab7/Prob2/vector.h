#pragma once

#include <string.h>
#include <iostream>

template <class T>
class Vector
{
private:
	T* m_vector;
	int m_size;
	int m_allocated_space;

public:

	Vector();

	void push(const T& el);
	T pop();
	void remove(int index);
	void insert(int index, const T& el);
	void sort(bool (*function)(T, T));

	const T& get(int index);
	void set(int index, const T& el);

	int count();
	int first_index_of(const T& obj, bool (*function)(T, T) = nullptr);

};

template<class T>
inline Vector<T>::Vector()
{
	m_vector = new T[10];
	m_size = 0;
	m_allocated_space = 10;
}

template<class T>
inline void Vector<T>::push(const T& el)
{
	if (m_size + 1 > m_allocated_space)
	{
		m_allocated_space *= 2;
		T* new_v = new T[m_allocated_space];

		memcpy(new_v, m_vector, m_size * sizeof(T));
		delete[] m_vector;
		m_vector = new_v;
		new_v = nullptr;
	}

	m_vector[m_size] = el;
	++m_size;

}

template<class T>
inline T Vector<T>::pop()
{
	if (m_size > 0)
	{
		--m_size;
		T el = m_vector[m_size];
		return el;
	}

	return 0;
}

template<class T>
inline void Vector<T>::remove(int index)
{
	if (m_size <= 0)
		return;

	memmove(m_vector + index, m_vector + (index + 1), (m_size - index - 1) * sizeof(T));


	--m_size;
}

template<class T>
inline void Vector<T>::insert(int index, const T& el)
{
	if (m_size + 1 > m_allocated_space)
	{
		m_allocated_space *= 2;
		T* new_v = new T[m_allocated_space];

		memcpy(new_v, m_vector, m_size * sizeof(T));
		delete[] m_vector;
		m_vector = new_v;
		new_v = nullptr;
	}

	memmove(m_vector + index + 1, m_vector + index, (m_size - index - 1) * sizeof(T));

	m_vector[index] = el;
	++m_size;

}

template<class T>
inline void Vector<T>::sort(bool(*function)(T, T))
{
	for (int i{ 0 }; i < m_size - 1; i++)
		for (int j{ 0 }; j < m_size - i - 1; j++)
		{
			if (function == nullptr)
			{
				if (m_vector[j + 1] < m_vector[j])
				{
					T sw = m_vector[j + 1];
					m_vector[j + 1] = m_vector[j];
					m_vector[j] = sw;
				}
			}
			else
			{
				if (function(m_vector[j + 1], m_vector[j]))
				{
					T sw = m_vector[j + 1];
					m_vector[j + 1] = m_vector[j];
					m_vector[j] = sw;
				}
			}
		}
}

template<class T>
inline const T& Vector<T>::get(int index)
{
	if (index >= m_size)
		return -1;

	return m_vector[index];
}

template<class T>
inline void Vector<T>::set(int index, const T& el)
{
	if (index >= m_size)
		return;

	m_size[index] = el;
}

template<class T>
inline int Vector<T>::count()
{
	return m_size;
}

template<class T>
inline int Vector<T>::first_index_of(const T& obj, bool(*function)(T, T))
{
	for (int i{ 0 }; i < m_size; ++i)
	{
		if (function != nullptr)
		{
			if (function(obj, m_vector[i]))
				return i;
		}
		else
		{
			if (obj == m_vector[i])
				return i;
		}
	}

	return -1;
}
