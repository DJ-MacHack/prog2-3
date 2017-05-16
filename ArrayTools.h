/**
* @file: ArrayTools.h
* @author:DJ MacHack
* @date: 16.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
* Partner: Julian Bruna
*/

#ifndef INC_3_ARRAYTOOLS_H
#define INC_3_ARRAYTOOLS_H


#include <iostream>
#include <algorithm>

using namespace std;

/**
 * You can read in your array via cin.
 * @tparam T
 * @param array
 * @param size
 * @return
 */
template<typename T>
T readArray(T array, size_t size){
    cout << "Bitte " << size << " Werte eingeben:" << endl;
    for(size_t i = 0; i < size; i++){
        cout << "tab[" << i <<"] =" << '\t';
        cin >> array[i];
    }
}

/**
 * Prints your array
 * @tparam T
 * @param array
 * @param size
 * @return
 */
template<typename T>
T printArray(T array, size_t size){
    cout << "[ ";
    for(size_t i = 0; i < size-1; i++){
        cout << array[i] << ", ";
    }
    cout << array[size-1] << " ]" << endl;
}

/**
 * Finds the max value of your array.
 * @tparam T
 * @param array
 * @param size
 * @return
 */
template<typename T>
T findMax(T* array, size_t size){
    T max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    cout << "Maximaler Wert: " << max << endl;
    return max;
}

/**
 * Optimized bubble sort
 * https://en.wikipedia.org/wiki/Bubble_sort#Optimizing_bubble_sort
 * @tparam T
 * @param array
 * @param size
 * @return
 */
template<typename T>
T bubbleSort(T array, size_t size) {
    size_t sizec = size;
    while (sizec != 0) {
        int newn = 0;
        for (size_t i = 1; i < sizec; i++) {
            if(array[i-1]>array[i]){
                swap(array[i-1], array[i]);
                newn = i;
            }
        }
        sizec = newn;
    }
}

/**
 * Opens all functions to test the array template
 * @tparam T
 * @param array
 * @param size
 * @return
 */
template<typename T>
T testeArray(T* array, size_t size) {
    readArray(array, size);
    printArray(array, size);
    findMax(array, size);
    bubbleSort(array, size);
    printArray(array, size);

}
#endif //INC_3_ARRAYTOOLS_H
