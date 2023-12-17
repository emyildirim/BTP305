
# Workshop 5: Functions and Error Handling

**In this workshop, I coded a function object and a lambda expression, and handle exceptions.**

I created a class template that manages a family of collection of objects of type T. This template's client can register a callback function (an observer) that will be called every time a new item is added successfully to a collection.

My design works with collections of books and collections of movies, both loaded from files. The file information contains mistakes:

- created a lambda expression that fixes the price information about a book
- created a function object (functor) that fixes some spelling mistakes in the descriptions and titles for books or movies.

In case of exceptional circumstances, my design generates exceptions and subsequently handles them

the functor loads the misspelled words from a file, but if that file is missing, generates an exception.
iterating over the collection using indices, my design generates an exception if an index is invalid.

Demonstarted key points:
- design and code a templated class that allocates and deallocates dynamic memory
- design and code a function object
- design and code a lambda expression
- code a member function that receives the address of a callback function to execute
- throw exceptions of different types
- distinguish exception types from one another
