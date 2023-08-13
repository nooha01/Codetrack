#include <vector>

/*basically like array but with dynamic size
Accessing members of the vector or appending to the vector takes 0(1) time. Locating a specific value or inserting elements
takes linear time.
*/

// default vector constructor has no arguments and creates an empty instance of the vector.
vector();

// default copy constructor that can be used to create a new vector that is a copy of given vector c.
vector(const vector &c);

// creates a vector with space for num objects. If val is specified, each of those objects will be given that value.
vector(size_type num, const T &val = T());
eg : vector<int> v(2, 3);
2->size 3->value
    v[0] = v[1] = 3

    vector(input_iterator start, input_iterator end);
eg : vector<int> v(it1, it2);
all contents between it1 and it2 are copied to v.

// All c++ operators are overloaded. 
== and != :Two vectors are equal iff their size is same, Each member in location i is equal to the member in location i of the other vector.
>, <, <=, >= : comparisons are done lexicographically.in dictionary order. 


# at()
======
at == []
syntax:
TYPE& at (size_type loc);
const TYPE& at (size_type loc) const;

at is better than [] because with [] we are able to access elements that are out of bounds.
at() throws an exception if the index is out of bounds.

eg:
vector<int> v(2, 3);
for (int i=0;i<5;i++)
    cout << v.at(i) << endl;


# Begin() and end()
====================
syntac: 
iterator begin();       const_iterator begin() const;
iterator end();         const_iterator end() const;




eg: 
vector<int> ::iterator it;
for(it=v1.begin();it!=v1.end();it++)
    cout << *it << endl;

# front() and back()

TYPE& front();      const TYPE& front() const;
TYPE& back();       const TYPE& back() const;

The front() function returns a reference to the first element of the vector and runs in constant time.
The back() function returns a reference to the last element of the vector and runs in constant time.

eg:
cout<<v.front()<<endl;
cout<<v.back()<<endl;

# rbegin() and rend()