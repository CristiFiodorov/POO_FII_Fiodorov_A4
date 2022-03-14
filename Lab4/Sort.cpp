#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <cstdarg>
#include <cstring>

void Sort::swap(int* a, int* b)
{
    int t{ *a };
    *a = *b;
    *b = t;
}

int Sort::partition(int arr[], int low, int high, bool ascendent)
{

    int pivot{ arr[high] }; 
    int i{ low - 1 };

    for (int j{ low }; j <= high - 1; ++j)
    {
        if (arr[j] < pivot && ascendent || arr[j] > pivot && !ascendent)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Sort::quick_sort(int arr[], int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pi{ partition(arr, low, high, ascendent) };

        quick_sort(arr, low, pi - 1, ascendent);
        quick_sort(arr, pi + 1, high, ascendent);
    }
}

Sort::Sort(int size, int min, int max) : m_array{ new int[size] }, m_size{ size }
{
    srand(time(NULL));

    for (int i{ 0 }; i < m_size; ++i)
    {
        m_array[i] = min + rand() % (max - min + 1);
    }
}

Sort::Sort() : m_array{ new int[5]{5, 100, 4, 2, 78} }, m_size{5}
{
}

Sort::Sort(const int* v, int size) : m_array{ new int[size] }, m_size{size}
{
    memcpy(m_array, v, m_size * 4);
}

Sort::Sort(int count, ...) : m_array{ new int[count] }, m_size{ count }
{
    va_list v;
    va_start(v, count);

    for (int i{ 0 }; i < count; ++i)
    {
        m_array[i] = va_arg(v, int);
    }

    va_end(v);
}

Sort::Sort(char* str)
{
    int count{ 0 };
    int v[100]{};

    char* p = strtok(str, ",");
    while (p != NULL)
    {
        v[count] = atoi(p);
        p = strtok(NULL, ",");
        ++count;
    }

    m_array = new int[count];
    memcpy(m_array, v, count * 4);

    m_size = count;
}


void Sort::InsertSort(bool ascendent)
{
    for (int i{ 1 }; i < m_size; i++)
    {
        int key{ m_array[i] };
        int j{ i - 1 };



        while (j >= 0 && m_array[j] > key && ascendent || j >= 0 && m_array[j] < key && !ascendent)
        {
            m_array[j + 1] = m_array[j];
            j = j - 1;
        }
        if(j != i-1)
            m_array[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent)
{
    quick_sort(m_array, 0, m_size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i{ m_size - 1 }; i > 0; --i)
    {
        for (int j{ 0 }; j < i; ++j)
        {
            if ((m_array[j] > m_array[j + 1] && ascendent) || (m_array[j] < m_array[j + 1] && !ascendent))
            {
                int temp = m_array[j];
                m_array[j] = m_array[j + 1];
                m_array[j + 1] = temp;
            }
        }
    } 
}

void Sort::Print()
{
    for (int i{ 0 }; i < m_size; ++i)
    {
        std::cout << m_array[i] << " ";
    }
}

int Sort::GetElementsCount()
{
    return m_size;
}

int Sort::GetElementFromIndex(int index)
{
    return m_array[index];
}
