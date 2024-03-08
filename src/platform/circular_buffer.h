#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <vector>
#include <optional>

template <typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(size_t size) : maxSize(size), head(0), tail(0), full(false) {
        buffer.resize(maxSize);
    }

    void put(T item) {
        buffer[tail] = item;
        tail = (tail + 1) % maxSize;
        full = tail == head;
        if (full) {
            head = (head + 1) % maxSize; // Bufor pełny, nadpisujemy najstarsze dane
        }
    }

    std::optional<std::vector<T>> get() {
        if (isEmpty()) {
            return std::nullopt;
        }
        return buffer;
        // T item = buffer[head];
        // head = (head + 1) % maxSize;
        // full = false;
        // return item;
    }

    bool isEmpty() const {
        return (!full && (head == tail));
    }

    bool isFull() const {
        return full;
    }

    void clear() {
        head = tail;
        full = false;
    }

private:
    std::vector<T> buffer;
    size_t head, tail;
    size_t maxSize;
    bool full;
};

#endif // CIRCULAR_BUFFER_H
