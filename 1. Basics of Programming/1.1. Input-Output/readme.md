### In this section we dicuss how we take input and output in a C++ Program.
* In C/C++, we have numerous libraries that include predefined functions to make programming easier. These are called header files. And, can be included in our program by inserting the line given below as first in our program.
```
#include<name-of-header-file>
```
* In C++ program we have to include header file which has input and output stream used to take input with the help of “cin” and “cout” respectively. 
    - iostream: iostream stands for standard input-output stream. Includes cin, cout, cerr etc.
    ```
    #include<iostream>
    ```

* The two keywords cout and cin are used very often for printing outputs and taking inputs respectively. These two are the most basic methods of taking input and printing output in C++.
* cout - It is used to produce output on the standard output device which is usually the display screen. The data needed to be displayed on the screen is inserted in the standard output stream (cout) using the insertion operator(<<).
     ```
        #include <iostream>
        using namespace std;

        int main(){
	        char sample[] = "Project Hades";
	        cout << sample << " ";
	        return 0;
        }
    ```
    Output:
    ```
    Project Hades
    ```
* cin - It is used to read input from the standard input device which is usually a keyboard.The extraction operator(>>) is used along with the object cin for reading inputs.
     ```
        #include <iostream>
        using namespace std;
 
        int main(){
            int age;
            cout << "Enter your age:";
            cin >> age;
            cout << "\nYour age is: " << age;
            return 0;
        }
    ```
    Input:
    ```
    18
    ```
    Output:
    ```
    Enter your age:
    Your age is: 18
    ```
* The above program asks the user to input the age. The object cin is connected to the input device. The age entered by the user is extracted from cin using the extraction operator(>>) and the extracted data is then stored in the variable age present on the right side of the extraction operator.