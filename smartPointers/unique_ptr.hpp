#ifndef EXAM_PREPARATION_UNIQUEPTR_HPP
#define EXAM_PREPARATION_UNIQUEPTR_HPP
#include <memory>
#include <algorithm>

template<class T>
class unique_ptr {
    T* ptr = nullptr;
public:
    unique_ptr() = default;

    ~unique_ptr() {
        delete ptr;
    }

    unique_ptr(unique_ptr<T>&& other)  noexcept : ptr(nullptr) {
        swap(other);
    }

    unique_ptr<T>& operator=(unique_ptr<T>&& other) noexcept {
        swap(other);
        return *this;
    }

    void reset(T* _ptr = nullptr) {
        delete ptr;
        ptr = _ptr;
    }

    T* release() {
        T* ans = ptr;
        ptr = nullptr;
        return ans;
    }

    void swap(unique_ptr<T>&& other) {
        std::swap(ptr, other.ptr);
    }

    T* operator->() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }

    explicit operator bool() const {
        return ptr;
    }

    T* get() {
        return ptr;
    }
};

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif //EXAM_PREPARATION_UNIQUEPTR_HPP
