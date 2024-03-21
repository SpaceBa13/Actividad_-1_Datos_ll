#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

//Complejidad O(nlog(n))
int partition(int* arr, int start, int end)
{
    // assuming last element as pivotElement
    int index = 0, pivotElement = arr[end], pivotIndex;
    int* temp = new int[end - start + 1]; // making an array whose size is equal to current partition range...
    for (int i = start; i <= end; i++) // pushing all the elements in temp which are smaller than pivotElement
    {
        if(arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    temp[index] = pivotElement; // pushing pivotElement in temp
    index++;

    for (int i = start; i < end; i++) // pushing all the elements in temp which are greater than pivotElement
    {
        if(arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
    // all the elements now in temp array are order :
    // leftmost elements are lesser than pivotElement and rightmost elements are greater than pivotElement
    index = 0;
    for (int i = start; i <= end; i++) // copying all the elements to original array i.e arr
    {
        if(arr[i] == pivotElement)
        {
            // for getting pivot index in the original array.
            // we need the pivotIndex value in the original and not in the temp array
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex; // returning pivotIndex
}

//Complejidad O(nlog(n))
void quickSort(int* arr, int start, int end)
{
    if(start < end)
    {
        int partitionIndex = partition(arr, start, end); // for getting partition
        quickSort(arr, start, partitionIndex - 1); // sorting left side array
        quickSort(arr, partitionIndex + 1, end); // sorting right side array
    }
    return;
}

//Complejidad O(Log(n))
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

            // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
}



// Complejidad O(n^2)
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

//Complejidad lineal
void o_n(int array[], int N){
    for (int i=0; i < N; ++i){
        int x = 1;
    }
}

//Complejidad exponencial
void o_2_n(int n) {
    if (n == 0) return;
    o_2_n(n - 1);
    o_2_n(n - 1);
}

int main() {
    //Crea un generador de números aleatorios
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister 19937 como motor

    //Definicion del array
    int tamano = 25;
    int *arr = new int[tamano];
    //N bubble sort
    int N = sizeof(int[tamano]) / sizeof(arr[0]);


    //Generador de numeros
    uniform_int_distribution<> dis(0, tamano);
    int random = dis(gen);

    //Para algoritmos de ordenamiento
    //for (int i=0; i < tamano; i++){
    //    arr[i] = dis(gen);
    //}

    //Para binary search
    for (int i=0; i < tamano; i++){
        arr[i] = i;
    }

    //Captura el tiempo actual antes de empezar a ejecutar el programa
    auto start = high_resolution_clock::now();

    //O(n) complejidad lineal
    //o_n(arr, N);

    //Bubble sort Complejidad cuadratica
    //bubbleSort(arr, N);

    //Quick sort Complejidad nLog(n)
    //quickSort(arr, 0, tamano - 1);

    //Binary Search Complejidad Log(n)
    //int n = sizeof(arr) / sizeof(arr[0]);
    //binarySearch(arr, 0, n - 1, random);

    //2^n Complejidad exponencial
    o_2_n(tamano);

    //Captura el tiempo actual después de ejecutar el programa
    auto end = high_resolution_clock::now();

    //Calcula la diferencia de tiempo en nanosegundos
    auto duration = duration_cast<nanoseconds>(end - start);


    //Imprime el tiempo de ejecución
    cout << "Tiempo de ejecucion: " << duration.count() << " nanosegundos" << endl;

    return 0;
}

//se ejecuto solo un algoritmo a la vez y el numero de elementos del array vario segun cada intento
