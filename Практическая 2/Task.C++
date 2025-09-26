Бинарная куча
template<typename T>
class MinHeap {
private:
    std::vector<T> heap;  // вектор для хранения элементов


Хэш-таблица
template<typename K, typename V>
class HashMap {
    std::vector<std::list<Pair<K,V>>> buckets;  // вектор списков
    size_t capacity;  // вместимость
