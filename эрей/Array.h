#pragma once
template <typename T>
class Array {
    T* mass;
    int size;
    int capacity;
    int grow;
public:
    Array(int capacity) : mass(new T[capacity]), capacity(capacity), size(0), grow(1) {}
    Array() : mass(nullptr), size(0), capacity(0), grow(1) {}
    Array(const Array& l) : capacity(l.capacity), mass(new T[l.capacity]), size(l.size) {
        for (int i = 0; i < size; i++) {
            mass[i] = l.mass[i];
        }
    }
    ~Array(){
        delete[] mass;
    }
    int GetCapacity() {
        return capacity;
    }
    int SetCapacity(int capa, int grow = 1) {
        bool k = capa < size;
        capacity = capa + (grow - capa % grow);
        T* g = new T[capacity];
        for (int i = 0; i < (k ? capa : size); i++) {
            g[i] = mass[i];
        }
        delete mass;
        mass = g;
        if (k) {
            size = capa;
        }
    }
    void Pushback(const T& per) {
        if (size == capacity) {
            capacity += grow - capacity % grow;
            T* m = new T[capacity];
            for (int i = 0; i < size; i++) {
                m[i] = mass[i];
            }
            delete[] mass;
            mass = m;
        }
        mass[size++] = per;
    }
    bool IsEmpty() {
        return size == 0;
    }
    void FreeExtra() {
        T* m = new T[size];
        capacity = size;
        for (int i = 0; i < size; i++) {
            m[i] = mass[i];
        }
        delete[] mass;
        mass = m;
    }
    void DeleteAll() {
        delete[] mass;
        size = 0;
        capacity = 0;
        grow = 1;
    }
    T aver() {
        T aver = 0;
        for (int i = 0; i < size; i++) {
            aver += mass[i];
        }
        aver /= size;
        return aver;
    }
    T GetAt(int index) {
        return *this[index];
    }
    void SetAt(int index, T smth) {
        *this[index] = smth;
    }
    void Append(const Array& it) {
        T* mas = new T[size + it.size];
        for (int i = 0; i < size; i++) {
            mas[i] = mass[i];
        }
        for (int i = 0; i < it.size; i++) {
            mas[i + size] = it.mass[i];
        }
        delete mass;
        mass = mas;
    }
    void InsertAt(const T& n, int c) {
        Pushback(n);
        for (int i = size - 1; i > c; i--) {
            std::swap(mass[i], mass[i - 1]);
        }
    }
    void RemoveAt(int c) {
        for (int i = c; i < size - 1; i++) {
            std::swap(mass[i], mass[i + 1]);
        }
        size--;
    }
    T& operator [] (int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("ur dumb");
        return mass[index];
    }
    T& operator = (const T& it) {
        capacity = it.capacity;
        size = it.size;
        grow = it.grow;
        T* m = new T[capacity];
        for (int i = 0; i < size; i++) {
            m[i] = mass[i];
        }
        delete[] mass;
        mass = m;
    }
};