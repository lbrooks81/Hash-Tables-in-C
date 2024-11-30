# Hash Tables

Specifications

Translate the MyHashtable class made in class to C++.

Your implementation should use a buckets array, where each element is an
std::vector<std::tuple<TKey, TValue>>. The types TKey and TValue will be class
templates. Remember, vectors and tuples are part of the C++ Standard Library (the std namespace).
Additionally, since arrays in C++ need dynamic sizing, they should be represented as pointers.

Syntax help for tuples: https://www.geeksforgeeks.org/tuples-in-c/#

You must do the following:
• Override the indexing ([]) operator.
• Implement both a default constructor and a constructor that takes capacity as an argument.
• Implement an add() method to insert items into the hash table.
• Implement a remove() method to delete items from the hash table.
• Implement a clear() method to reset the hash table.
• Implement a toString() method to return a string representation of the hash table.
• Implement a containsKey() method that returns true if the specified key exists in the hash
table, and false otherwise.

These methods should function the same way as in the original C# implementation. Make sure to test
your class thoroughly in the main() function.

Constraints
• Utilize a constant for the default capacity. You can define and initialize this in your header file.
Have it be type size_t.
• The variable that keeps count of how many items are in the Hashtable should be private,
however, there should be a public getter for it.
◦ You do not need a variable or method for returning how large a bucket is.
• You must not have memory leaks. Utilize a destructor for this.
• Test all of your methods in your main. Make a menu of food items and put them into your hash
table the same way we did in C#.
• All methods defined in your source file must have its header in the header file (.h).
• C++ uses camelCase. Name variables and methods using camelCase. Classes should be named
with PascelCase. See the tips for help.
• If a method will not affect the state of the object, mark the method as constant.
