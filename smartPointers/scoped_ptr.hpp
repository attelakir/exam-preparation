#ifndef EXAM_PREPARATION_SCOPED_PTR_HPP
#define EXAM_PREPARATION_SCOPED_PTR_HPP

#include <memory>

template<class T>
class scoped_ptr {
public:
    explicit scoped_ptr(T *value = nullptr);

    ~scoped_ptr();

    T *operator->();

    T &operator*();

    T *get() const;

private:
    T *ptr;
};

template<class T>
scoped_ptr<T>::scoped_ptr(T *value) : ptr(value) {}

template<class T>
scoped_ptr<T>::~scoped_ptr() {
    delete ptr;
}

template<class T>
T *scoped_ptr<T>::operator->() {
    return ptr;
}

template<class T>
T &scoped_ptr<T>::operator*() {
    return *ptr;
}

template<class T>
T *scoped_ptr<T>::get() const {
    return ptr;
}

template<typename T, typename... Args>
scoped_ptr<T> make_scoped(Args &&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif //EXAM_PREPARATION_SCOPED_PTR_HPP
