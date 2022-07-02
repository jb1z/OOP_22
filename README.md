# The content of cpp's files

## file_1.cpp

**Themes in file:**

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

2. In `MyClass` class there is a parameterized constructor:

    ```cpp
    MyClass(int size)
    ```

    This constructor sets a size of dynamic
array, also the memory for dynamic array allocates here and the array fills by default values.

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

*Copy constructors:*

```cpp
MyClass(MyClassOther &object)
```

```cpp
MyClass(const MyClass &other)
```

*Overloading operators:*

___

## file_2.cpp

**Themes in file:**
___

## file_3.cpp

**Themes in file:**
___

## file_4.cpp

**Themes in file:**
___

## file_5.cpp

**Themes in file:**
___

## file_6.cpp

**Themes in file:**
___

## file_7.cpp

**Themes in file:**
___

## file_8.cpp

**Themes in file:**
___

## file_9.cpp

**Themes in file:**
___

## file_10.cpp

**Themes in file:**
___

## file_11.cpp

**Themes in file:**
___

## file_12.cpp

**Themes in file:**
___

## file_13.cpp

**Themes in file:**
___

## file_14.cpp

**Themes in file:**
___

## file_15.cpp

**Themes in file:**
___
