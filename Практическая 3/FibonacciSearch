import java.util.Arrays;

public class FibonacciSearch {

    // Метод для генерации чисел Фибоначчи до тех пор, пока не найдётся F[m] >= n
    public static int findFib(int n) {
        int fib_m2 = 0; // F(m-2)
        int fib_m1 = 1; // F(m-1)
        int fib_m = fib_m2 + fib_m1; // F(m)

        // Находим m такое, что F[m] >= n
        while (fib_m < n) {
            fib_m2 = fib_m1;
            fib_m1 = fib_m;
            fib_m = fib_m2 + fib_m1;
        }
        return fib_m; // Возвращаем F[m] >= n
    }

    // Метод поиска Фибоначчи
    public static int fibonacciSearch(int[] arr, int x) {
        int n = arr.length;

        // Находим наименьшее число Фибоначчи, большее или равное n
        int fib_m2 = 0; // F(m-2)
        int fib_m1 = 1; // F(m-1)
        int fib_m = fib_m2 + fib_m1; // F(m)

        while (fib_m < n) {
            fib_m2 = fib_m1;
            fib_m1 = fib_m;
            fib_m = fib_m2 + fib_m1;
        }

        // Маркер для элементов, которые не входят в массив (смещение)
        int offset = -1;

        // Поиск
        while (fib_m > 1) {
            // Проверяем возможный индекс
            // i = min(offset + F[m-2], n-1)
            int i = Math.min(offset + fib_m2, n - 1);

            // Если x больше элемента, переходим к правому подмассиву
            if (arr[i] < x) {
                fib_m = fib_m1;
                fib_m1 = fib_m2;
                fib_m2 = fib_m - fib_m1;
                offset = i;
            }
            // Если x меньше элемента, переходим к левому подмассиву
            else if (arr[i] > x) {
                fib_m = fib_m2;
                fib_m1 = fib_m1 - fib_m2; // F[m-1] = F[m] - F[m-2]
                fib_m2 = fib_m - fib_m1; // F[m-2] = F[m] - F[m-1]
                // offset остается прежним
            }
            // Элемент найден
            else {
                return i;
            }
        }

        // Проверяем последний элемент, если F[m-1] != 0 и элемент существует
        if (fib_m1 == 1 && offset + 1 < n && arr[offset + 1] == x) {
            return offset + 1;
        }

        return -1; // Элемент не найден
    }

    public static void main(String[] args) {
        int[] arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
        int x = 85; // Искомое значение

        System.out.println("Массив: " + Arrays.toString(arr));
        System.out.println("Ищем: " + x);

        int result = fibonacciSearch(arr, x);

        if (result != -1) {
            System.out.println("Элемент найден на позиции: " + result);
        } else {
            System.out.println("Элемент не найден");
        }
    }
}
