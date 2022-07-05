# The content of cpp's files

I decided to repeate OOP principles on cpp, and I found a YouTube channel `#SimpleCode`. I considered themes I'm interested in, wrote and debugged code in these files from this [playlist](https://www.youtube.com/playlist?list=PLQOaTSbfxUtBm7DxblJZShqBQnBAVzlXX) to practice.

## file_1.cpp

**Themes covered in file:**

- *constructors*
- *copy constructors*
- *overloaded operators*

**Description:**

***Constructors:***

*We use constructor to initialize object we create with data.*

1. In `Human` class there is a constructor with 3 parameters:

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

    This constructor  accepts as a parameter an object of `MyClassOther` class.

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

        ```cpp
        bool operator == (const Point &other)
        ```

        It accepts as a parameter an object of `Point` class and return a `bool`.

   - The second overloaded operator is `+` :

        ```cpp
        Point operator + (const Point &other)
        ```

        We create a new object in the method's body and return it as a result of addition.

        ```cpp
        Point temp(this->x_ + other.x_, this->y_ + other.y_);
        return temp;
        ```

   - The final block of overloaded operators are overloaded prefix and postfix increments :

        ```cpp
        Point & operator ++ ()
        ```

        We update some fields here by `this->` pointer and return `return *this`. This is a overloaded prefix increment.

        The overloaded postfix increment should be considered more attentively:

        ```cpp
        // postfix form differs from prefix by unused int parameter
        // we cant return a reference to temp because its lifetime is limited by this block of code 
        Point operator ++ (int value){ // overloaded ++ operator (postfix)
            Point temp(*this);
            this->x_++;
            this->y_++;
            return temp;
        }
        ```

        We create a `temp` copy of `*this`, make some updates with `this->` and return a `temp`, not reference to a `temp`! Because lifetime of this `temp` object is limited by this method. We should do like that because of priority of postfix incrementation. Also we have a one unused parameter `int value` we should do this to differ overloading of prefix incrementation from postfix.

3. In `Human` class there is an overloaded `!=` operator but it realize implemented as overloading `==` described above.

4. In `TestIndexing` class there is overloaded `[]` (indexing) operator:

    ```cpp
    int & operator [] (int index){ // we use reference to be able to change the value by index
            return array_[index];      // without returning reference we can only get a value by index
    }
    ```

    It returns a reference `int &` and accept `index` we are point in square brackets when we use it as a parameter.

___

## file_2.cpp

**Themes covered in file:**

- *friend functions*
- *removing the implementation of methods outside the class body*
- *friend class*

**Description:**

***Friend functions:***

1. In `Point` class 2 functions are `friend` to this class:

    ```cpp
    friend void changeX(Point & pointChange, Test & testChange); // friend function
    friend void changeY(Point & pointChange); // friend function
    ```

    These functions are declared and realiazed outside the class, but they can access private fields of classes in which these functions are `friend`.

2. In `Test` class 1 function is `friend` to this class:

    ```cpp
    void changeX(Point & pointChange, Test & testChange)// this function is friend to two classes
    ```

    Function `changeX` is friend to `Point` and `Test` in it's body we access to private fields of `Point` and `Test` classes.

***Removing the implementation of methods outside the class body:***

In `MyClass` there is a constructor and `print()` method - they are declared in class, but their realizations are out of class body and it work like this:

```cpp
void MyClass::print(){ // method outside the class
    cout << "Data is: " << data_ << "\n";
}
```

As an example here the realiztion of `print()` method outside a class.

***Friend class:***

The `Human` class is designated as `friend` in `Apple` class this leads us to the conclusion that we can access private fields of object of `Apple` class in `Human` method.

```cpp
void Human::takeApple(Apple &apple){
    cout << "Weight: " << apple.weight_ << ", color: " << apple.color_ << "\n"; 
}
```

As an example: `takeApple` method is `Human` class method, but we can access `apple.weight_`
although `weight_` is private in `Apple` class.

___

## file_3.cpp

**Themes covered in file:**

-*static fields & static methods*

**Description:**

***Static fields & static methods:***

In `Apple` class there is a static field `static int appleCount_` this field we need for counting objects of `Apple` class. The initializing of static field must be done outside the class body.

```cpp
int Apple::appleCount_ = 0; // static initializing outside a class
```

Static fields and functions are global for all class and it's objects, we can access it by class namespace like this:

```cpp
Apple::changeColor(apple2, "red");
```

Here it is the example of static method.

Also we cant reach *non-static* field in *static* methods:

```cpp
static int getAppleCount(){
    // weight_ = 0; we cant access to non-static field 
    return appleCount_;
}
```

But we can do it this way (by receiving an object like a method's parameter):

```cpp
static void changeColor(Apple &apple, string color){ // we can do like this
    apple.color_ = color;  
}
```

___

## file_4.cpp

**Themes covered in file:**

- *inner class*
- *agregation & composition*

**Description:**

***Inner class:***

In this file class `Pixel` inside the `Image` class (image consist of lots of pixels - by this logic), class `Pixel` declared in private section of `Image`, these classes can't access each other private data.

Also in `Image` there is *static* field:

```cpp
static const int LENGTH = 5; // must be static
// we can initialize it here because this field is CONSTANT
```

And it initialized here because this field is `const` despite being `static` at the same time.

This field sets the size of `Pixel` array in `Image`.

***Agregation & composition***

The example of *composition* in this file is `Brain` class in `Human` class, we create also a `Brain` object in `Human`. We can use `Brain` only with `Human` class - this is composition. We call `brain.think()` method in `think()` method of `Human` - this is *delegation*.

The example of *aggregation* in this file is an object of `Cap` class, which we both use in `Human` class and `Mannequin` class.

___

## file_5.cpp

**Themes covered in file:**

- *inheritance*
- *access specifiers in inheritance*

**Description:**

***Inheritance:***

In this file `Human` is base class for `Student`, `Professor` and also `Extramural student` inherited from from `Student`. The inheritance denoted like:

```cpp
class Professor: public Human // inherited from Human
```

***Access specifiers in inheritance:***

The `public` keyword before `Human` means the specification modifier of inheritance, it also could be `private` and `protected`. Here is the table of inheritance:

*empty*  | public | protected | private
   :----: | :----: | :----: | :----:
public   | public | protected  | private
protected  | protected  | protected  | private
private  | private  | private  | private

The columns mean inheritance type, the rows mean *access specifiers* and to which type they transform after inheritance.

___

## file_6.cpp

**Themes covered in file:**

- *polymorphism*
- *virtual method*
- *overridden method*

In this file there are 3 classes: `Gun`, `MachineGun` inherited from `Gun` and player, which receive a pointer to `Gun` as a parameter in it's `shoot()` method.

In this block of code two objects creating of `Gun` and `MachineGun` classes, then a `shoot()` method called for for `Gun` object the output is `Bang!` and for `MachineGun` object the output is `Bang! Bang! Bang!`:

```cpp
Gun gun;
    gun.shoot(); // Bang!
    MachineGun machineGun;
    machineGun.shoot(); // Bang! Bang! Bang!
```

But the next block is showing *polymorphism* itself:

```cpp
    // pointer of base class type may point to the object of base class or to the object of inherited class
    Gun gun1;
    Gun *weapon1 = &gun1;
    weapon1->shoot(); // Bang!
    //
    MachineGun gun2;
    Gun *weapon2 = &gun2;
    weapon2->shoot(); // Bang! Bang! Bang!
    // called methods are determined by "object" type!
```

In the `Gun` class the method `shoot()` is virtual and in the `MachineGun` class this method is overridden.

But if the `shoot()` method in `Gun` class wasn't virtual the output would be another:

```cpp
/*weapon1->shoot(); // Bang!
weapon2->shoot(); // Bang!*/
// called methods are determined by "pointer" type!
```

We can send to method objects of both class, because `shoot()` method in `Player` receive a pointer to `Gun` and we will see different realisation depends on **object type**!

___

## file_7.cpp

**Themes covered in file:**

- *pure virtual methods*
- *virtual destructors*
- *pure virtual destructors*
  
***Pure virtual methods:***

We need pure virtual methods to force inheritor-classes to realize this method.

***Virtual destructors:***

These destructors are needed for correct memory release like in this block of code:

```cpp
A *bptr = new B;
delete bptr;
// we only release memory by A destructor, without B destructor
// we should make ~A() - virtual
// we need virtual destructor for a correct memory release
```

***Pure virtual destructors:***

These destructor don't let us create an object of class where such a destructor exists. But we still need them for correct memory release.

___

## file_8.cpp

**Themes covered in file:**

- *delegating constructors*
- *overridden methods*

**Description:**

***Delegating constructors:***

In `Human` class there are 3 contructors: 2 of them call other contructor:

```cpp
Human(string name, int age) : Human(name){ // firstly calling Human(name)
    age_ = age;
}
Human(string name, int age, int weight) : Human(name, age){ // firstly calling Human(name)
    weight_ = weight;
}
```

These are *delegating* constructors.

***Overridden methods:***

In this file there are `Msg` and `Brekets` classes: `BreketMsg` inherited from `Msg` and in `BreketMsg` class the `getMsg()` method is overridden and if we want to call a `getMsg()` from `Msg` class we should use it's by `Msg` namespace:

```cpp
string getMsg() override{
    return "[" + Msg::getMsg() + "]"; // we should directly point to method we want to use
}
```

___

## file_9.cpp

**Themes covered in file:**

- *plural inheritance*

**Description:**

***Plural inheritance:***

The order of constructor order deepends on inheritance order:

```cpp
class FlyingCar : public Car, public Airplane // plural inheritance
```

The `Car` class constructor will be called first.

Also we can use a pointer of both base classes with `FlyingCar` object:

```cpp
Car *ptrC = &fc;
Airplane *ptrA = &fc;
```

And if we have in base classes same method we need to lead object to required type:

```cpp
((Car)fc).use();
((Airplane)fc).use();
```

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
