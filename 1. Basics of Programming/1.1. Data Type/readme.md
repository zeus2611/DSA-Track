# Data Tpes:

All variables use data-type during declaration to restrict the type of data to be stored. Whenever a variable is defined in C++, the compiler allocates some memory for that variable based on the data-type with which it is declared. Every data type requires a different amount of memory.

<div style="text-align:center"><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113115600/DatatypesInC.png" /></div>

<b>Note</b>: We Will be maily discussing primary data types in this article.

<b>Primitive Data Types</b>: These data types are built-in or predefined data types and can be used directly by the user to declare variables. example: int, char , float, bool etc.
    
Primitive data types available in C++ are: 
- Integer: Keyword used for integer data types is int. Integers typically requires 4 bytes of memory space and ranges from -2147483648 to 2147483647. 
- Character: Character data type is used for storing characters. Keyword used for character data type is char. Characters typically requires 1 byte of memory space and ranges from -128 to 127 or 0 to 255.
- Boolean: Boolean data type is used for storing boolean or logical values. A boolean variable can store either true or false. Keyword used for boolean data type is bool
- Floating Point: Floating Point data type is used for storing single precision floating point values or decimal values. Keyword used for floating point data type is float. Float variables typically requires 4 byte of memory space.
- Double Floating Point: Double Floating Point data type is used for storing double precision floating point values or decimal values. Keyword used for double floating point data type is double. Double variables typically requires 8 byte of memory space.
- Void: Void means without any value. void datatype represents a valueless entity. Void data type is used for those function which does not returns a value. 


If deafult range of any data type is not enough for us. We can use Datatype Modifiers to extend range of any data type.

Data type modifiers available in C++ are: 
- Signed
- Unsigned
- Short
- Long

| Data Type     | size (in byte) |  Range  |
| ------------- | -------------- | ------- |
| short int |	2	| -32,768 to 32,767 |
|unsigned short int |	2 |	0 to 65,535|
|unsigned int |	4	| 0 to 4,294,967,295 |
|int |	4	| -2,147,483,648 to 2,147,483,647 |
|long int |	8	| -2,147,483,648 to 2,147,483,647|
|unsigned long int |	8	| 0 to 4,294,967,295|
|long long int |	8	| -(2^63) to (2^63)-1|
|unsigned long long int |	8	| 0 to 18,446,744,073,709,551,615|
|signed char |	1	| -128 to 127|
|unsigned char |	1	| 0 to 255|
|float	|4	| | 
|double	| 8	 | |
|long double	| 12| |

<b>Note:</b> Above values may vary from compiler to compiler. In the above example, we have considered GCC 32 bit.