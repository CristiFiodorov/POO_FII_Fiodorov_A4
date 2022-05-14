#pragma once

template <class T, class V>
struct pair
{
	T key;
	V value;
	int index;
};

template <class T, class V>
class Map
{
public:
	pair<T, V>* m_pairs;
	int m_count;
	int m_allocated_space;

	void reallocation();

public:
	Map();

	pair<T, V>* begin();
	pair<T, V>* end();

	V& operator[] (T key);

	void Set(const T& key, const V& value);
	bool Get(const T& key, V& value);
	int Count();
	void Clear();
	bool Delete(const T& key);
	bool Includes(const Map<T, V>& map);

};

template<class T, class V>
inline void Map<T, V>::reallocation()
{
	m_allocated_space *= 2;
	pair<T, V>* tmp = new pair<T, V>[m_allocated_space];

	memcpy(tmp, m_pairs, m_count * sizeof(pair<T, V>));
	delete[] m_pairs;
	m_pairs = tmp;
	tmp = nullptr;
}

template<class T, class V>
inline Map<T, V>::Map() : m_count{ 0 }, m_allocated_space{ 8 }
{
	m_pairs = new pair<T, V>[8];
}

template<class T, class V>
inline pair<T, V>* Map<T, V>::begin()
{
	return &m_pairs[0];
}

template<class T, class V>
inline pair<T, V>* Map<T, V>::end()
{
	return &m_pairs[m_count];
}

template<class T, class V>
inline V& Map<T, V>::operator[](T key)
{
	for (int i{ 0 }; i < m_count; ++i)
	{
		if (m_pairs[i].key == key)
			return m_pairs[i].value;
	}

	if (m_count + 1 > m_allocated_space)
		reallocation();

	m_pairs[m_count].key = key;
	m_pairs[m_count].value = nullptr;
	m_pairs[m_count].index = m_count;
	++m_count;

	return m_pairs[m_count-1].value;
}

template<class T, class V>
inline void Map<T, V>::Set(const T& key, const V& value)
{
	for (int i{ 0 }; i < m_count; ++i)
	{
		if (m_pairs[i].key == key)
		{
			m_pairs[i].value = value;
			return;
		}
	}

	if (m_count + 1 > m_allocated_space)
		reallocation();

	m_pairs[m_count].key = key;
	m_pairs[m_count].value = value;
	m_pairs[m_count].index = m_count;
	++m_count;
}

// Trebuie de mai lucrat
template<class T, class V>
inline bool Map<T, V>::Get(const T& key, V& value)
{
	for (int i{ 0 }; i < m_count; ++i)
	{
		if (m_pairs[i].key == key)
		{
			memcpy(&m_pairs[i].value, &value, sizeof(V));
			return true;
		}
	}
	return false;
}

template<class T, class V>
inline int Map<T, V>::Count()
{
	return m_count;
}

template<class T, class V>
inline void Map<T, V>::Clear()
{
	m_count = 0;
	m_allocated_space = 8;
	delete[] m_pairs;
	m_pairs = new pair<T, V>[8];
}

template<class T, class V>
inline bool Map<T, V>::Delete(const T& key)
{
	for (int i{ 0 }; i < m_count; ++i)
	{
		if (m_pairs[i].key == key)
		{
			memmove(&m_pairs[i], &m_pairs[i+1], sizeof(pair<T, V>));
			--m_count;
			return true;
		}
	}
	return false;
}

template<class T, class V>
inline bool Map<T, V>::Includes(const Map<T, V>& map)
{
	for (int i{ 0 }; i < map.m_count; ++i)
	{
		bool incl = false;
		for (int j{ 0 }; j < m_count; ++j)
		{
			if (m_pairs[j].key == map.m_pairs[i].key)
			{
				incl = true;
				break;
			}
		}
		if (!incl)
			return false;
	}

	return true;
}
