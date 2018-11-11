#include <bits/stdc++.h>


using namespace std;

pair <long long, long long> data [1000000];
//in first priority key
//in second value


    long long size = 0;
    long long sizeMax = 0;


    void siftDown(long long index) {
        long long left = 2 * index ;
        long long right = 2 * index + 1;

        long long smallest = index;
        if (left <= size && data[left].first <= data[index].first)
            smallest = left;
        if (right <= size && data[right].first <= data[smallest].first)
            smallest = right;

        if (smallest == index)
            return;
        swap(data[index], data[smallest]);
        siftDown(smallest);
    }

    void siftUp(long long index) {
        while (index > 1) {
            long long parent = (index) / 2;
            if (data[index].first > data[parent].first)
                return;
            swap(data[index], data[parent]);
            index = parent;
        }
    }

    void push(long long priority, long long value) {
        size++;
        data[size].second = value;
        data[size].first = priority;
        siftUp(size);
    }

    bool extractMin(long long& priority, long long& value) {
        if (size < 1)
            return false;
        priority = data[1].first;
        value = data[1].second;

        data[1] = data[size];
        size--;
        siftDown(1);
        return true;
    }

    void decreaseKey(long long value, long long priority_new) {
        for (long long i = 1; i <= size; i++) {
            if (data[i].second == value) {
                if (priority_new < data[i].first) {
                    data[i].first = priority_new;
                    siftUp(i);
                }
                break;
            }
        }
    }


int main() {
    freopen ("priorityqueue.in","r",stdin);
    freopen ("priorityqueue.out","w",stdout);
    string command;
    long long counter = 1;
    while (cin >> command) {


        if (command == "push") {
            long long priority;
            cin >> priority;
            push(priority, counter);
        }

        if (command == "decrease-key") {
            long long priority;
            long long value;
            cin >> value >> priority;
           decreaseKey(value, priority);

        }

        if (command == "extract-min") {
            long long priority;
            long long value;
            if (!extractMin(priority, value))
                cout << '*' << endl;
            else
                cout << priority << endl;
        }
        counter++;
    }

    return 0;
}
