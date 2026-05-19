#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    int f;  // front
    int b;  // back
    int s;  // current size 
    int c;  // capacity 
    vector<int> arr;

    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        s = 0;
        c = k;
        arr.resize(k);
    }

    bool enQueue(int val) {
        if (s == c) return false;

        arr[b] = val;
        b++;
        if (b == c) b = 0;

        s++;
        return true;
    }
    
    bool deQueue() {
        if (s == 0) return false;

        f++;
        if (f == c) f = 0;

        s--;
        return true;
    }
    
    int Front() {
        if (s == 0) return -1;
        return arr[f];
    }
    
    int Rear() {
        if (s == 0) return -1;
        if (b == 0) return arr[c - 1];
        return arr[b - 1];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        return s == c;
    }
};

int main() {
    int k;
    cout << "Enter capacity of circular queue: ";
    cin >> k;

    MyCircularQueue q(k);

    cout << "\nEnqueue operations:\n";
    cout << q.enQueue(10) << endl;
    cout << q.enQueue(20) << endl;
    cout << q.enQueue(30) << endl;

    cout << "\nFront: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    cout << "\nDequeue operation:\n";
    cout << q.deQueue() << endl;

    cout << "\nFront after dequeue: " << q.Front() << endl;

    cout << "\nIs Empty: " << q.isEmpty() << endl;
    cout << "Is Full: " << q.isFull() << endl;

    return 0;
}