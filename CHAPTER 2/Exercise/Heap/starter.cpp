#include <bits/stdc++.h>
using namespace std;

const int HEAP_SIZE = 10;
int heap[HEAP_SIZE];
int heap_size = 1;

int parent(int i)
{
    return i / 2;
}
int left_child(int i)
{
    return i * 2;
}
int right_child(int i)
{
    return (i * 2) + 1;
}

void insert(int num)
{
    if (heap_size == HEAP_SIZE)
    {
        cout << "OVERFLOW.\n";
        return;
    }
    heap[heap_size] = num;
    heap_size++;
    int i = heap_size - 1;
    while (i != 1 && heap[parent(i)] < heap[i])
    {
        int hold = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = hold;
        i = parent(i);
    }
    return;
}

int max_heapify(int i)
{
    int l = left_child(i);
    int r = right_child(i);
    int largest = i;
    if (l < heap_size && heap[l] > heap[largest])
        largest = l;
    if (r < heap_size && heap[r] > heap[largest])
        largest = r;
    if (largest != i)
    {
        int hold = heap[i];
        heap[i] = heap[largest];
        heap[largest] = hold;
        max_heapify(largest);
    }
}

int extract_max()
{
    if (heap_size <= 1)
    {
        return INT_MAX;
    }
    else if (heap_size == 2)
    {
        heap_size--;
        return heap[1];
    }
    int root = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;
    max_heapify(1);
    return root;
}

int main()
{
    insert(10);
    insert(15);
    insert(5);
    insert(4);
    insert(45);
    for (int i = 1; i < heap_size; i++)
    {
        cout << heap[i] << " ";
    }
    cout << "\n";
    cout << extract_max() << "\n";
    cout << extract_max() << "\n";
    cout << extract_max() << "\n";
    cout << extract_max() << "\n";
    cout << extract_max() << "\n";
    cout << extract_max() << "\n";
    cout << extract_max() << "\n";
}