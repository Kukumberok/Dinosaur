#pragma once
template <class T>
class OwningArray {
private:
    T* data = nullptr;
    int n = 0;

public:
    OwningArray() = default;

    explicit OwningArray(int count) : n(count) {
        data = (n > 0) ? new T[n] : nullptr;
    }

    ~OwningArray() {
        delete[] data;
    }

    OwningArray(const OwningArray& other) : n(other.n) {
        data = (n > 0) ? new T[n] : nullptr;
        for (int i = 0; i < n; i++) data[i] = other.data[i];
    }

    OwningArray& operator=(const OwningArray& other) {
        if (this == &other) return *this;

        delete[] data;
        n = other.n;
        data = (n > 0) ? new T[n] : nullptr;
        for (int i = 0; i < n; i++) data[i] = other.data[i];
        return *this;
    }

    int size() const { return n; }

    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
};

