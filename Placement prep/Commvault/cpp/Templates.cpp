// Function templates

/*
We can use function overloading, but we can use function templates because that requires less coding and maintable code
*/

/*
SYNTAX
======
template <class T>
T function (T arg)
{
     
}

Here, T is a template argument that accepts any data type. But for one particular function call T is of same type. 
*/

/*
Example
=======
template <class T>
T Large(T n1, T n2)
{
    return (n1>n2)?n1:n2;
}

int i1,i2;
float f1,f2;
char c1,c2;
cout <<Large(i1,i2);
cout <<Large(f1,f2);
cout <<Large(c1,c2);
*/

// class templates

/*
THey are used when class implementation is same for all classes, only the data types are different
eg: general calculator class

SYNTAX
======
template <class T>
class className {
    T var;
    T function (T arg) {
        // code
    }
};

Creating objects
================

datatype needs to be specified in <>

className<datatype> objectName;
eg: vetor<int> a;


EXAMPLE
=======

template <class T>
class Calculator {
    private:
        T num1, num2;
    public:
        Calculator (T n1, T n2)
        {
            num1 = n1;
            num2 = n2;
        }
    T add()
    {
        return num1+num2;
    }
    T multiply()
    {
        return num1*num2;
    }
    T subtract()
    {
        return num1-num2;
    }
};


*/