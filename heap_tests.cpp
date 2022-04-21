#include <iostream>
#include <vector>
#include <deque>

#include "heap.h"

using std::cout;
using std::endl;

int main() {
    // Example test case
    std::vector<int> heap{150,80,40,30,10,70,110,100,20,90,60,50,120,140,130};

    cout << "before heapify: ";
    for (int i : heap) { cout << i << " "; }
    cout << endl;

    heapify(&heap);

    cout << "after heapify: ";
    for (int i : heap) { cout << i << " "; }
    cout << endl;

    for (unsigned j = 0; j < 4; j++) {
        cout << "minimum is " << heap_get_min(heap) << endl;
        
        cout << "delete min" << endl;
        heap_delete_min(&heap);
        
        cout << "heap: ";
        for (int i : heap) { cout << i << " "; }
        cout << endl;
    }

    int values[] = {47,54,57,43,120,3};
    for (unsigned j = 0; j < 6; j++) {
        cout << "insert " << values[j] << endl;
        heap_insert(&heap, values[j]);

        cout << "heap: ";
        for (int i : heap) { cout << i << " "; }
        cout << endl;
    }


    std::vector<int> myvector{150};
    heapify(&myvector);

    cout << "after heapify: ";
    for (int i : myvector) { cout << i << " "; }
    cout << endl;
    // TODO(student): write tests

    return 0;
}
