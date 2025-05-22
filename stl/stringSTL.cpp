#include <bits/stdc++.h>
using namespace std;

// ✅ Constructors
string s;                         // Default: creates an empty string
string s2("hello");                // Creates string from a C-style string
string s3 = "world";              // Creates string from a string literal
string s4(s2);                     // Copy constructor: duplicate from another string
string s5(5, 'x');                 // Creates string with 5 copies of 'x' → "xxxxx"
string s6 = move(s5);         // Move constructor: takes ownership from another string

// ✅ Assignment
s = "new string";                       // Assigns new value from string literal
s = s2;                                 // Assigns value from another string
s = std::move(s2);                      // Move assignment: transfers data from s2

// ✅ Capacity
s.size();               // Returns number of characters in the string
s.length();             // Same as size(); both give the string length
s.max_size();           // Returns the maximum size the string can grow to
s.resize(n);            // Changes the string size to `n`; fills or truncates
s.resize(n, 'a');       // Same as above, fills new chars with 'a' if expanding
s.capacity();           // Returns number of characters currently allocated
s.reserve(n);           // Reserves space for at least `n` characters
s.shrink_to_fit();      // Reduces capacity to fit size (optional optimization)
s.clear();              // Erases all content and makes string empty
s.empty();              // Checks if string is empty (true if size is 0)

// ✅ Element Access
s[i];                   // Accesses character at index `i` (no bounds check)
s.at(i);                // Accesses character at `i` with bounds checking
s.front();              // Returns first character of the string
s.back();               // Returns last character of the string
s.data();               // Returns pointer to internal char array (not null-terminated in C++11+)
s.c_str();              // Returns C-style null-terminated string (for printf, etc.)

// ✅ Modifiers
s += "world";                       // Appends "world" to the string
s.append("abc");                   // Appends C-string "abc"
s.append("abc", 2);                // Appends first 2 characters of "abc" → "ab"
s.append(s2);                      // Appends another string object
s.push_back('!');                  // Appends single character at the end
s.insert(pos, "xyz");              // Inserts "xyz" starting at index `pos`
s.insert(pos, 3, 'x');             // Inserts 3 copies of 'x' at `pos`
s.erase(pos, len);                 // Removes `len` characters starting at `pos`
s.erase(it);                       // Removes character at iterator `it`
s.erase(it1, it2);                 // Removes characters in range `[it1, it2)`
s.replace(pos, len, "new");        // Replaces `len` characters from `pos` with "new"
s.swap(s2);                        // Swaps contents with `s2`
std::swap(s, s2);                  // Same as above, non-member version

// ✅ String Operations
s.copy(buffer, len);               // Copies `len` characters into buffer (not null-terminated)
s.substr(pos);                     // Returns substring from `pos` to end
s.substr(pos, len);                // Returns substring of `len` characters starting at `pos`

// ✅ Searching
s.find("abc");                     // Finds first occurrence of "abc"; returns position or npos
s.find("abc", pos);                // Same, but starts searching from `pos`
s.find('a');                       // Finds first occurrence of character 'a'
s.rfind("abc");                    // Finds last occurrence of "abc"
s.rfind('a');                      // Finds last occurrence of character 'a'
s.find_first_of("aeiou");          // Finds first occurrence of any char in "aeiou"
s.find_first_not_of("xyz");        // Finds first char not in "xyz"
s.find_last_of("aeiou");           // Finds last occurrence of any char in "aeiou"
s.find_last_not_of("xyz");         // Finds last char not in "xyz"

// ✅ Comparison
s == s2;                           // Checks if two strings are equal
s != s2;                           // Checks if two strings are not equal
s < s2;                            // Lexicographically compares strings (like dictionary)
s.compare(s2);                     // Returns 0 if equal, <0 if less, >0 if greater
s.compare(pos, len, s2);           // Compares substring of `s` with `s2`
s.compare(pos, len, s2, pos2, len2); // Compares substring of `s` with substring of `s2`

// ✅ Iterators
s.begin(), s.end();                // Returns iterators to start and end
s.rbegin(), s.rend();              // Reverse iterators (end to start)
s.cbegin(), s.cend();              // Constant iterators (read-only)
s.crbegin(), s.crend();            // Constant reverse iterators

// ✅ Input/Output
std::cin >> s;                     // Reads word from input (stops at space/newline)
std::getline(std::cin, s);         // Reads entire line into string
std::cout << s;                    // Outputs string to console

// ✅ C++20 Additions (compiler support required)
s.starts_with("abc");              // Returns true if string starts with "abc"
s.ends_with("xyz");                // Returns true if string ends with "xyz"
s.contains("foo");                 // Returns true if substring "foo" is found

// ✅ Constants
std::string::npos;                 // Special constant for "not found" (value = -1)
