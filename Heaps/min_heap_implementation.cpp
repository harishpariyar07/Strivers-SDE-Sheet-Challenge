#include <bits/stdc++.h>

void heapify(int i, vector<int> &heap)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] < heap[i])
    {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    if (i != smallest)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest, heap);
    }

    return;
}

void insertInHeap(int num, vector<int> &heap)
{
    heap.push_back(num);
    int i = heap.size() - 1;
    int parent = (i - 1) / 2;
    while (heap[i] < heap[parent])
    {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = (parent - 1) / 2;
        if (parent < 0)
            break;
    }
}

int extractMin(vector<int> &heap)
{
    int n = heap.size();
    int top = heap[0];
    swap(heap[0], heap[n - 1]);
    heap.pop_back();
    heapify(0, heap);
    return top;
}

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    // Write your code here.
    vector<int> heap;
    vector<int> res;
    for (auto i : q)
    {
        if (i[0] == 0)
        {
            insertInHeap(i[1], heap);
        }
        else
        {
            int minEl = extractMin(heap);
            res.push_back(minEl);
        }
    }

    return res;
}
