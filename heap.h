#ifndef HEAP_H
#define HEAP_H

#include <functional>

template <class Container, class Compare=std::less<typename Container::value_type>>
void percolate_down(Container* container, size_t index, Compare less=std::less<typename Container::value_type>{}) {
    // TODO(student): implement percolate_down
    size_t child;
    if (index >= container->size() || index < 1) {
        throw std::invalid_argument("Index not valid");
    }

    // find last parent index to use for breaking loop early
    size_t last = container->size() - 1;
    size_t parent = last / 2;

    for ( ; index * 2 < container->size(); index = child) {
        if (index > parent) {
            break;
        }
        child = index * 2;

        if (child != container->size() - 1 && less(container->at(child + 1), container->at(child))) {
            child += 1;
        }

        if (less(container->at(child), container->at(index))) {
            std::swap(container->at(child), container->at(index));
        }

    }
}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heapify(Container* container, Compare less=std::less<typename Container::value_type>{}) {
    // TODO(student): implement heapify

    // if empty do nothing
    if (container->size() < 1) {
        return;
    }

    // make container heap
    container->resize(container->size() + 1);
    for (int i = container->size() - 1; i >= 1; i--) {
        
        std::swap(container->at(i), container->at(i-1));
    }
    //container->at(0) = 0;

    int last = container->size() - 1;
    int parentIndex = last / 2;
    while (parentIndex > 0) {
        percolate_down(container, parentIndex, less);
        parentIndex--;
    }

    
}


// GIVEN: The functions below are given to you in the starter code
// you should NOT need to modify these

template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_insert(Container* container, const typename Container::value_type& value, Compare less=std::less<typename Container::value_type>{}) {
    if (container->size() <= 1) {
        container->resize(2);
        container->at(1) = std::move(value);
        return;
    }
    size_t index = container->size();
    container->push_back(value);
    size_t parent = index / 2;
    while (parent > 0 && less(value, container->at(parent))) {
        container->at(index) = std::move(container->at(parent));
        index = parent;
        parent = index / 2;
    }
    container->at(index) = std::move(value);
}

template <class Container>
const typename Container::value_type& heap_get_min(const Container& container) {
    if (container.size() <= 1) {
        throw std::invalid_argument(__FUNCTION__);
    }
    return container[1];
}

template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_delete_min(Container* container, Compare less=std::less<typename Container::value_type>{}) {
    if (container->size() <= 1) {
        throw std::invalid_argument(__FUNCTION__);
    }
    if (container->size() == 2) {
        container->pop_back();
        return;
    }
    container->at(1) = std::move(container->back());
    container->pop_back();
    percolate_down(container, 1, less);
}

#endif  // HEAP_H