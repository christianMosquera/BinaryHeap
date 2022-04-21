#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
#include <functional>
#include "heap.h"

template <class Comparable, class Container=std::vector<Comparable>, class Compare=std::less<Comparable>>
class PriorityQueue {
private:
    // Member Types - do not modify
    using container_type = Container;
    using value_compare = Compare;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    // Member Types - do not modify
    // you can modify below here

    Compare compare;
    Container container;

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& other);
    PriorityQueue(const Compare& _compare);
    PriorityQueue(const Container& _container);
    PriorityQueue(const Compare& _compare, const Container& _container);
    ~PriorityQueue();
    PriorityQueue& operator=(const PriorityQueue& other);

    const_reference top() const;

    bool empty() const;
    size_type size() const;

    void make_empty();
    void push(const value_type& value);
    void pop();

    void print_queue(std::ostream& os=std::cout) const;
};

#endif  // PRIORITY_QUEUE_H