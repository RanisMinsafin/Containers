# Containers Library (C++)

## Overview

The Containers Library, implemented in `s21_containers.h`, provides a collection of essential container classes designed to simplify data manipulation and storage in C++ programs. The library includes a range of containers such as lists, maps, queues, sets, stacks, and vectors, each serving specific purposes.

## Part 1: Main Containers

### List

The `list` container represents a doubly-linked list, providing efficient insertion and deletion operations. This container is implemented using a list structure.

### Map

The `map` container represents an associative container that stores key-value pairs. It is implemented using a tree-like structure, allowing for quick key-based access to values.

### Queue

The `queue` container represents a FIFO (First-In-First-Out) data structure. It is ideal for scenarios where elements are processed in the order they are added.

### Set

The `set` container is an ordered collection of unique elements. It uses a binary search tree to maintain element order and uniqueness.

### Stack

The `stack` container is a LIFO (Last-In-First-Out) data structure. It is useful for managing elements in a last-in-first-out manner.

### Vector

The `vector` container represents a dynamic array, allowing elements to be efficiently stored and accessed. This container is implemented using an array structure.

## Part 2: Bonus - Additional Containers

### Array

The `array` container is an ordered collection of elements. It is similar to the `vector` but has a fixed size specified at compile-time.

### Multiset

The `multiset` container is an ordered collection that allows duplicate elements. It is implemented using a binary search tree and maintains element order.

## Part 3: Bonus - `insert_many` Method

The library introduces the `insert_many` method for various container classes. This method allows multiple elements to be inserted into the container in a flexible manner:

- `iterator insert_many(const_iterator pos, Args&&... args)`: Inserts new elements into the container directly before the specified position `pos`. This method is available for `list` and `vector` containers.

- `void insert_many_back(Args&&... args)`: Appends new elements to the end of the container. This method is available for `list`, `vector`, and `queue` containers.

- `void insert_many_front(Args&&... args)`: Appends new elements to the beginning of the container. This method is available for `list` and `stack` containers.

- `vector<std::pair<iterator, bool>> insert_many(Args&&... args)`: Inserts new elements into the container. This method is available for `map`, `set`, and `multiset` containers.

The `Args&&... args` parameter pack allows a variable number of parameters to be passed to these methods, offering flexibility when inserting elements.

## Building and Testing

To build and test the library, a Makefile is provided with standard targets:

- `clean`: Removes build artifacts.
- `test`: Executes tests to ensure the library functions correctly.

## Conclusion

The Containers Library (`s21_containers.h`) is a versatile collection of container classes designed to simplify data management in C++ programs. With a range of container types, including main and additional containers, and the introduction of the `insert_many` method, this library provides valuable tools for developers working on data manipulation and storage tasks in C++ programs.