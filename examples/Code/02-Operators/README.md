# Operators

<img src="images/Thumbnail_Arduino_Maths.png" width="800">

## Contents

- [Introduction](#introduction)
- [Operators](#operators)
    - [Arithmetic Operators](#arithmetic-operators)
    - [Assignment Operators](#assignment-operators)
    - [Relational Operators](#relational-operators)
    - [Logical Operators](#logical-operators)

## Introduction
At its heart, a computer is essentially a very fast calculator, capable of calculating and outputting thousands, millions, and sometimes billions of calculations every second. 

When programming, we need ways of calculating, incrementing and comparing values. In a programming language, an operator is just a character that represents a mathematical or logical action or process.  

You will likely be familiar with some arithmetic operators already: add (+), subtract (-), multiply (*), divide (/), however there are several others that we can use in our code. Let's take a look at some of the more common operators…

## Operators
### Arithmetic Operators

Arithmetic operators, as the name suggests, are used for simple arithmetic. You would use arithmetic operators to perform mathematical calculations such as addition, subtraction, multiplication, and division in programming or mathematics.

| Operation	                        | Symbol	| Example	| Equivalent    |
|-----------                        |-----------|-----------|---------------|
| Add                               | +	        | 2 + 1     | 	3           | 
| Subtract                          | 	-	    | 2 - 1     | 	1           | 
| Multiply                          | 	*	    | 2 * 2     | 	4           | 
| Divide                            | 	/	    | 10 / 2    | 	5           | 
| Modulo (remainder after division) | 	%       | 	3 % 2   | 	1           | 

### Assignment Operators

Assignment operators allow you to assign a value to a variable. The most simple example of this is the equals operator (=) which is used to assign a value to a variable. 

You can also use assignment operators to modify the value being stored in a variable. For example:

``` cpp
int a = 1;
a += 2;
Serial.print(a);
```

This example code would print <code>3</code> to the serial monitor.

- First, a is assigned a value of <code>1</code> using the equals operator.
- Then we use the <code>+=</code> operator to add <code>2</code> to <code>a</code>'s current value.
- One plus two is three, so now <code>a</code> has a value of <code>3</code> and is printed to the serial monitor.
 
Here are some more assignment operators:

| Operation	                    | Symbol | Example	| Equivalent|
|-----------                    |-----------|-----------|---------------|
| Equals	                    | =  |    a = 10  | a = 10    |
| Add	                        | += |	    a += 2	| a = a + 2 |
| Subtract	                    | -= |	    a -= 2	| a = a - 2 |
| Multiply	                    | *= |	    a *= 2	| a = a * 2 |
| Divide	                    | /= |	    a /= 2	| a = a / 2 |
| Modulo (remainder after division) |	%= |	    a %= 2	| a = a % 2 |

### Relational Operators

Relational operators compare two values and return either <code>1</code> (if <code>true</code>) or <code>0</code> (if <code>false</code>). These operators are commonly used with [control flow statements](../4-ControlFlow/README.md) where they are used to decide whether a block of code if executed or ignored.

For example:

``` cpp
int a = 2;
​
if (a > 0) {
  Serial.println("Hello");
}
```

This example uses an <code>if()</code> statement to check if the variable a is greater than <code>0</code>. As a has already been assigned a value of <code>2</code> (line 1), <code>(a > 0)</code> will return <code>true</code> and the block of code with the print statement will be executed.

Here are some more relational operators:

| Operation |	Symbol	| Example	| Equivalent |
|-----------|-----------|-----------|---------------|
| Equal to | 	== |	1 == 2 |	0 (<code>false</code>) |
| Not equal to |	!= |	1 != 2 |	1 (<code>true</code>) |
| Less than |	< |	1 < 2 |	1 (<code>true</code>) |
| Greater than |	> |	1 > 2 |	0 (<code>false</code>) |
| Less than or equal to |	<= |	1 <= 2 |	1 (<code>true</code>) |
| Greater than or equal to |	>= |	1 >= 2 |	0 (<code>false</code>) |

### Logical Operators

Logical operators can be used in conjunction with relational operators to combine more than one condition. For example, if we wanted to check that <code>a</code> was less than <code>1</code>0 and greater than <code>0</code>, we can use the logical AND operator (<code>&&</code>) like so:

``` cpp
int a = 3;
bool b = (a < 10) && (a > 0);
```

In this example, <cod>b</code> would be true as the both conditional statements are <cod>true</code>.

Here are some more logical operators:

| Operation | Symbol |	Example |	Equivalent |
|-----------|-----------|-----------|---------------|
| Logical AND |	&& |	(1 != 2) && (1 > 2) |	0 (<code>false</codex>) |
| Logical OR |	\|\| |	(1 != 2) \|\| (1 > 2) |	1 (<code>true</codex>) |
| Logical NOT |	! |	!(1 > 2) |	1 (<code>true</codex>) |