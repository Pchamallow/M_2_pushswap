*This project has been created as part of the 42 curriculum by pswirgie.*


# Description
With given numbers, the programm must display a sorted stack with the lowest number of operations.  


# Instructions
In order to run the program, follow this instructions : 
1. make re
2. ./push_swap [given numbers]  


# Resources
I have read many articles about algorithms in order to choose the one I would use.
I used many git for understand how to manipulate stacks.
I turned to AI for some minors issues and more understand severly part of algorithm.
From the begin to the end of the project, I collaborated with my peers.  


# Parsing
The parsing step ensures that the following cases are not present :
- an argument is null (Error);
- an alphabet (Error);
- is superior at int max or int min (Error);
- only one argument (already sorted = nothing);
- if sign is not followed by a number and if it is after a number (Error);
- two followed signs (Error);
- two duplicated numbers;  


# Technical choices
I first chose the Turkish algorithm but I couldn't get it to run over the number 455.
On peers recommandations, I used the butterfly algorithm, as it was more efficient one for sorting stacks.  