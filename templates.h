#pragma once
#include <iostream>
using namespace std;

template <typename T>
T findHighestPrice(T arr[], int size) {
    T highest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i]->getPrice() > highest->getPrice()) {
            highest = arr[i];
        }
    }
    return highest;
}

template <typename T>
void swapProducts(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
