#pragma once


class Sort
{
public:
    int* m_array{};
    int m_size{};
public:

    Sort(int size, int min, int max); // 1
    Sort(); //2
    Sort(const int* v, int size); // 3
    Sort(int count, ...); // 4
    Sort(char* str); // 5

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

    ~Sort()
    {
        delete[] m_array;
    }
};