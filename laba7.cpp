#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 15
using namespace std;

template <typename T, typename = enable_if<is_same<T, int>::value ||
                                           is_same<T, float>::value || is_same<T, double>::value>>
void ArrayRandomizer(T *arr, const short int size = SIZE)
{
    srand(time(nullptr));

    cout << "Int array consists of " << SIZE << " elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % size;
        if (i == 0)
            cout << arr[i] << " ";
        else if (i == size - 1)
            cout << arr[i] << "." << endl
                 << "==================" << endl;
        else
            cout << " " << arr[i] << " ";
    }
}
void ArrayRandomizer(char *arr1, const short int size = SIZE)
{
    srand(time(nullptr));
    cout << "Char array consists of " << SIZE << " elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        arr1[i] = 'a' + rand() % 10;
        if (i == 0)
            cout << arr1[i] << " ";
        else if (i == size - 1)
            cout << arr1[i] << "." << endl
                 << "==================" << endl;
        else
            cout << " " << arr1[i] << " ";
    }
}
template <typename T>
T FrequentMax(T *some_array, int size)
{
    T maxElement;
    int maxCount = 0;
    for (int i = 0; i < size; i++)
    {
        int coincidences = 0;
        for (int j = 0; j < size; j++)
        {
            if (some_array[j] == some_array[i])
                coincidences++;
        }
        if (coincidences > maxCount)
        {
            maxCount = coincidences;
            maxElement = some_array[i];
        }
    }
    if (maxCount == 0)
        return 0;
    return maxElement;
}

int main()
{
    cout << "==================" << endl;
    const short int size = SIZE;
    int array[size];
    int *p_array = array;
    char array1[size];
    char *p_array1 = array1;
    ArrayRandomizer(p_array, size);
    ArrayRandomizer(p_array1, size);
    if (FrequentMax(p_array, size) == 0)
        cout << "All elements are single" << endl;
    cout << "Most frequent element is:\t" << FrequentMax(p_array, size) << endl;
    return 0;
}
