#include <iostream>
using namespace std;

void merge(int* arr, int p, int q, int r) {
    int N1 = q - p + 1;
    int N2 = r - q;
    int* mas1 = new int[N1];
    int* mas2 = new int[N2];
    for (int i = 0; i < N1; i++) {
        mas1[i] = arr[p + i]; // Исправлено arr[p + 1] на arr[p + i]
    }
    for (int j = 0; j < N2; j++) {
        mas2[j] = arr[q + 1 + j];
    }
    int i = 0, j = 0, k = p;
    while (i < N1 && j < N2) {
        if (mas1[i] <= mas2[j]) {
            arr[k] = mas1[i];
            i++;
        }
        else {
            arr[k] = mas2[j];
            j++;
        }
        k++;
    }
    while (i < N1) {
        arr[k] = mas1[i];
        i++;
        k++;
    }
    while (j < N2) {
        arr[k] = mas2[j];
        j++;
        k++;
    }
    delete[] mas1;
    delete[] mas2;
}

void mergeSort(int* arr, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void NaturalMergeSort(int* arr, int N) {
    bool f = false;
    while (!f) {
        int p = 0;
        int r = N - 1;
        f = true;
        while (p < r) {
            int q = p;
            while ((q < r) && (arr[q] <= arr[q + 1])) {
                q++;
            }
            if (q < r) {
                merge(arr, p, q, r);
                f = false;
            }
            p = q + 1;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int N;
    cout << "Введите размер массива: ";
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> arr[i];
    }
    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    NaturalMergeSort(arr, N);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    delete[] arr; // Освобождение памяти, выделенной под массив
    return 0;
}
