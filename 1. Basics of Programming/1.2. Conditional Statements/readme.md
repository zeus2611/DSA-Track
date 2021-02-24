# Conditional Statements:

</br>
<img align="right" width='200px' height="300px" alt="GIF" src="https://media.geeksforgeeks.org/wp-content/uploads/decision-making-c-1.png" />

**if Statement:**

if statement is the most simple decision making statement. It is used to decide whether a certain statement or block of statements will be executed or not i.e if a certain condition is true then a block of statement is executed otherwise not.

Syntax:

    if(condition) {
        // Statements to execute if
        // condition is true
    }

</br>
<img align="left" width='230px' height="350px" alt="GIF" src="https://media.geeksforgeeks.org/wp-content/uploads/decision-making-c-2.png" />

**if-else Statement:**

The if statement alone tells us that if a condition is true it will execute a block of statements and if the condition is false it won’t. But if we want to do something if the condition is false, then we use else statement wich execute a block of code when the condition is false.

Syntax:

    if(condition) {
        // Statements to execute if
        // condition is true
    }
    else {
        // Statements to execute if
        // condition is false
    }

</br>
<img align="right" width='305px' height="300px" alt="GIF" src="https://media.geeksforgeeks.org/wp-content/uploads/decision-making-c-3.png" />

**nested-if Statement:**

Nested if statements means an if statement inside another if statement.

Syntax:

    if(condition) 
    {
        // Statements to execute if
        // condition is true
    }

</br>
</br>
<img align="left" width='305px' height="450px" alt="GIF" src="https://media.geeksforgeeks.org/wp-content/uploads/decision-making-c-4.png" />

**if-else-if Statement:**

Here, a user can decide among multiple options. if statements are executed from the top down. As soon as one of the conditions controlling the if is true, the statement associated with that if is executed, and the rest else-if ladder is bypassed. If none of the conditions are true, then the final else statement will be executed.

Syntax:

    if (condition)
        statement;
    else if (condition)
        statement;
    .
    .
    else
      statement;

</br>
</br>

# **Jump Statements:**

<img align="left" height="200" alt="GIF" src="https://media.geeksforgeeks.org/wp-content/uploads/break.png" />

- <b>break</b> - It is used to terminate the loop. As soon as the break statement is encountered from within a loop, the loop iterations stops there and control returns from the loop immediately to the first statement after the loop.