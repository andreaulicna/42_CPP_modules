# 42_CPP_Modules

## CPP_Module_00

### ex01

#### Test cases
- Input:
    - Whitespaces (also followed by something)
    - Ctrl + C and Ctrl + D
- ADD:
    - adding contacts when the phonebook is full
        - how easily can be a contact overwritten
        - does the history (oldest saved) shifts?
	- non-numeric characters for the phone number
    - Ctrl + C and Ctrl + D
- SEARCH:
    - obviously invalid index such as 'a', 'hello'
    - entry > 8 vs entry <= 8 when there are not yet 8 contacts saved
    - valid index when there are no contacts saved yet
    - printing of empty rows
    - Ctrl + C and Ctrl + D
	
### ex02

#### Test cases
There are 2 bash scripts to make the testing (comparison between the original log and the recreated one) easier in VS Code.
- The first one executes the program, redirects the output into recreated.log and
creates comparison files.
- The second one cleans up the recreated.log and comparison files once the comparison is done.
```
cd compare_logs
bash compare_logs.sh
bash compare_logs_cleanup.sh
```

## CPP_Module_01

### ex04

#### Test cases
```
./sed hello ola
./sed hello ""
./sed "" jou
```

## CPP_Module_02

### Theory

#### Fixed-point numbers
Fixed-point numbers are a method of representing fractional numbers in a computer, which is especially useful in systems that lack floating-point hardware. 

In a fixed-point number system, a specific number of digits are reserved for representing the integer part of the number, and a specific number of digits are reserved for representing the fractional part. The position of the "decimal" point is fixed and doesn't move, hence the name "fixed-point".

For example, if we have a 16-bit fixed-point number system where 8 bits are used for the integer part and 8 bits are used for the fractional part, the number 10.6 would be represented like this:
- Integer part: 10 in binary is 00001010
- Fractional part: 0.6 is approximately 98/256 in binary, which is 01100010
- So, 10.6 would be represented as 00001010.01100010

Fixed-point arithmetic is similar to integer arithmetic. For addition and subtraction, you can simply add or subtract the numbers as if they were integers. For multiplication and division, you need to take into account the position of the "decimal" point. For example, when multiplying two fixed-point numbers, the result will have twice as many fractional bits, so you need to shift the result to the right to correct this.
```
10.6 (00001010.01100010) + 3.2 (00000011.00110011) = 13.8 (00001101.11010101)
10.6 (00001010.01100010) * 3.2 (00000011.00110011) = 33.92 (100001.11101100)
```

#### Copy constructor vs copy assignment operator
- Copy constructor: Used for initialization as it creates a new class instance that is a copy of an existing class instance.
- Copy assignment operator: Used for assignment as it assigns the value of one (already existing) class instance to another.
- Regardless of which one is used, obj1 ends up as a copy of obj2, but the difference is in whether obj1 is a new object (copy constructor) or an existing object (copy assignment operator).

#### Static member functions
```static``` in a member function declaration means that the function is associated with the class, not any particular instance of the class. This means that the function can be called without creating an instance of the class.

#### Returning reference vs const reference
The choice of returning a reference versus a const reference from a function depends on should be then possible to do with the retured object:
- Returning a reference (Fixed &): The caller can modify such a returned object. It is useful when we want the function to provide direct access to an object that it manages.

- Returning a const reference (const Fixed &): This prevents the caller from modifying the returned object. The caller can use the object and call const methods on it, but cannot change it. This is useful when we want the function to provide read-only access to an object.

#### Operator precedence
- The ```<<``` operator (stream insertion operator) has higher precedence than comparison operators like ```>, <, >=, <=,``` and ```!=```. This mean that went chaining the printing of an output, without the brackets, the << operator would be evaluated first, leading to incorrect results or compilation errors.
- On the other hand, arithmetic operators like ```+``` have higher precedence than the ```<<``` operator, so they are evaluated first even without brackets.
