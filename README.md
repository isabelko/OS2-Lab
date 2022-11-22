# Coding Assignment #2
##### By: Isak Sabelko

## Enviornment my Program Was Written in

I wrote my code in virtual box which was running linux ubuntu 22.04.1 LTS. I wrote my code in VS code in the language C++. 

## How to Run my Program

In the terminal you would type "g++ banker.cpp" to compile the code then write "./a.out" to run the code.

## Data Entered Into Program

![image](https://user-images.githubusercontent.com/116108682/203414167-3c9dca0f-85c9-4ce6-a264-2e6165b60cfb.png)

## Output of Program 
```code 
making sure data entered in correctly from table:
Available column: 3 3 2
Maximum column: 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
Allocation column: 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
The current system is in a safe state! :)
The safe state sequence = 1 3 4 0 2
```

## What Does my Code/Bankers Algorithm do?

My code first takes in data from my data.txt file. It puts the data in its according arrays (availible, allocated, and maximum). It will then find the needed resources for each process by subtracting the allocated from maximum for each process to figure out what resources they now need. If the need is less than what is availible the process will recieve the resource and the arrays will change accordingly. The safe state checking is done by making sure that the need value is less than what is availible. Every time a process runs it will save the process name in order to create the safe state sequence. If the processes all run without deadlock, the safe state sequence is true. The code will then print out that it is safe and the safe sequence
 

## Challenges/lessons

The biggest challenge I faced was making sure the process was in a safe state and finding the safe state sequence. Another issue which is kind of unrelated to the code is my github. Every time I commit I would lose my read me. This is my 3rd read me file ive written. It also would not let me commit unless I had the a.out in the repository so that is why that is there. I learned how to calculate what processes need and it was awesome to see what a potential operating system could implement. I also learned that I could've read my data from the file in in a much more elegant way but I wanted to make sure I got every piece of data in correctly so I did it in a not so elegant way. 


