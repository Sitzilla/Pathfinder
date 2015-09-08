# Pathfinder
Homework assignment from Programming Foundations II. Problem on course website:
http://csce.uark.edu/~lbg002/csce2014/homework/homework-2-pathfinding/

# Problem Statement
You are a ninja. The princess has been kidnapped and is being held on the lowest basement floor of the bad guy’s castle. Her room is filling up with poisonous gas, so you only have a limited time to save her. You have a map of the castle showing how many guards are in each room, and since you are a ninja, you know you can beat each guard in one minute (two guards in two minutes, three guards in three minutes, etc). You must find the fastest path through the castle’s rooms in order to save the princess in time!

The goal of this assignment is to practice recursive algorithms by writing a program that takes in a matrix representing the number of guards in each room of the castle and outputs the fastest path to the princess and the number of guards you will have to fight.

Matrix input will look like this:
10 10
5   2   28  49  58  82  10  58  91  75
65  8   8   72  29  22  7   63  12  61
34  1  73  11  1   22  53  34  9   37
26  1  41  76  84  20  84  77  53  94
53  1  2   76  78  35  38  76  25  14
53  73  92  1  15  51  35  40  60  20
20  90  59  1  28  34  17  59  73  43
31  21  31  36  14  93  1  1  12  89
40  81  89  21  97  92  50  1  1   83
79  7   44  51  36  99  15  96  90  74

# Design
You should begin by thinking about how the recursion will work. What is the base case? What should each step of the recursion return? How can it store the current path and the current cost?

Using the provided starting place for programming, fill in the doit method by having it call your recursive function, then print out the fastest path to the princess and how many guards you have to fight.

# Implementation

*Need to create a Matrix.txt filename to pass in as an argument when calling homework2.cpp
