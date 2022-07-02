# The content of cpp's files

I decided to repeate OOP principles on cpp, and I found a YouTube channel `#SimpleCode`. I considered themes I'm interested in, wrote and debugged code in these files from this [playlist](https://www.youtube.com/playlist?list=PLQOaTSbfxUtBm7DxblJZShqBQnBAVzlXX) to practice.

## file_1.cpp

**Themes covered in file:**

- *constructors*
- *copy constructors*
- *overloading operators*

**Description:**

***Constructors:***

*We use constructor to initialize object we create with data.*

1. In `Human` class there is a constructor with 3 parametrs:

    ```cpp
    Human(int age, int height, string name)
    ```

    This constructors sets 3 private fields.

2. In `MyClass` class there are 2 parameterized constructors:

    ```cpp
    MyClass(int size)
    ```

    This constructor sets a size of dynamic
    array, also the memory for dynamic array allocates here and the array fills by default values.

    ```cpp
    MyClass(MyClassOther &object)
    ```

    This constructor  accepts as a parametr an object of `MyClassOther` class.

3. In `Point` class there are 3 constructors:

    ```cpp
    Point()
    ```

    Default constructor sets `x_` and `y_` to zeros.

    ```cpp
    Point(int x, int y)
    ```

    Parameterized constructor sets `x_` and `y_` to accepted `x` and `y`.

    ```cpp
    Point(const Point & other)
    ```

    This constructor accepts other `Point` object and sets values of accepted object.

4. In `MyClassOther` there is default constructor:

    ```cpp
    MyClassOther()
    ```

    This constructor sets a value of `10` to it's private field `privateInfo_` and displays an information about does the code running this constructor.

***Copy constructors:***

*We use copy constructors to initialize object we are creating with data of another object of the same class. The copy constructor might be called by 2 ways:*

```cpp
    int dataToEnter = 5;    
    MyClass firstObject(dataToEnter);
    MyClass secondObject(firstObject); // Copy constructor is used here
    MyClass thirdObject = firstObject; // And here copy constructor too, not assignment
```

***Overloading operators:***

*Primitive data types like `int` "knows" how to interact with different operators like `>`, `+`, `*` and so on. But when we create a class with fields of different types compiler don't know what does it mean to add one object of some class to another.*

*In this file some operators like `=`, `==`, `+`, `!=`, `[]` are overloaded, also operators of postfix and prefix increments are overloaded too:*

1. In `MyClass` class the assignment operator is overloaded and it declared like this:

    ```cpp
    // overload assignment operator
    MyClass & operator = (const MyClass &other)
    ```

    This method returns `MyClass &` - a reference to an object of `MyClass` class. Then we have a `operator` keyword and operator we want to overload: `=` in this case.

    We prescribe some logic in the body of this method and in the end it returns:

    ```cpp
    return *this;
    ```

    We should return a reference to an object because the program won't work if we didnt do this in following case:

    ```cpp
    sixthObject = fifthObject = firstObject;
    //overloaded operator returns reference to object so we able to do this
    ```

2. In `Point` class there are 4 overloaded operators: `==`, `+`, postfix and prefix increment:

   - The first overloaded operator is `==` :

        ``` cpp
        bool operator == (const Point &other)
        ```

___

## file_2.cpp

**Themes covered in file:**
___

## file_3.cpp

**Themes covered in file:**
___

## file_4.cpp

**Themes covered in file:**
___

## file_5.cpp

**Themes covered in file:**
___

## file_6.cpp

**Themes covered in file:**
___

## file_7.cpp

**Themes covered in file:**
___

## file_8.cpp

**Themes covered in file:**
___

## file_9.cpp

**Themes covered in file:**
___

## file_10.cpp

**Themes covered in file:**
___

## file_11.cpp

**Themes covered in file:**
___

## file_12.cpp

**Themes covered in file:**
___

## file_13.cpp

**Themes covered in file:**
___

## file_14.cpp

**Themes covered in file:**
___

## file_15.cpp

**Themes covered in file:**
___
