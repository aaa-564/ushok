#include <iostream>
#include <vector>

// Функция для поддержания свойства кучи (max-heap)
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;   // левый = 2*i + 1
    int right = 2 * i + 2;  // правый = 2*i + 2

    // Проверяем, существует ли левый дочерний элемент и больше ли он корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Проверяем, существует ли правый дочерний элемент и больше ли он корня
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если корень не является наибольшим, меняем его и продолжаем heapify
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Применяем heapify к новому поддереву
    }
}

// Основная функция пирамидальной сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Построение max-heap из входного массива.
    // Начинаем с последнего узла, имеющего потомков (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень (максимальный элемент) в конец
        std::swap(arr[0], arr[i]);
        // Вызываем heapify для уменьшенной кучи (до i-1)
        heapify(arr, i, 0);
    }
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Исходный массив: ";
    printArray(arr);

    heapSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
