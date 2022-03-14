#pragma once


class Sort
{
private:
    int* m_array{};
    int m_size{};

    void swap(int* a, int* b);
    int partition(int arr[], int low, int high, bool ascendent);
    void quick_sort(int arr[], int low, int high, bool ascendent);

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