# 42_CPP_Modules

## CPP_Module_00

### ex01

#### Test cases
- Input:
    - Enter
    - Ctrl + C and Ctrl + D
- ADD:
    - adding contacts when the phonebook is full
        - how easily can be a contact overwritten
        - does the history (oldest saved) shifts?
- SEARCH:
    - obviously invalid index such as 'a', 'hello'
    - entry > 8 vs entry <= 8 when there are not yet 8 contacts saved
    - valid index when there are no contacts saved yet
    - printing of empty rows
	
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

### ex02

#### Theory

##### Static member functions
```static``` in a member function declaration means that the function is associated with the class, not any particular instance of the class. This means that the function can be called without creating an instance of the class.

##### Returning reference vs const reference
The choice of returning a reference versus a const reference from a function depends on should be then possible to do with the retured object:
- Returning a reference (Fixed &): The caller can modify such a returned object. It is useful when we want the function to provide direct access to an object that it manages.

- Returning a const reference (const Fixed &): This prevents the caller from modifying the returned object. The caller can use the object and call const methods on it, but cannot change it. This is useful when we want the function to provide read-only access to an object.

#### Operator precedence
- The ```<<``` operator (stream insertion operator) has higher precedence than comparison operators like ```>, <, >=, <=,``` and ```!=```. This mean that went chaining the printing of an output, without the brackets, the << operator would be evaluated first, leading to incorrect results or compilation errors.
- On the other hand, arithmetic operators like ```+``` have higher precedence than the ```<<``` operator, so they are evaluated first even without brackets.