# Push_Swap

This project is for sorting numbers using two stacks, with a limited number of instructions.

## Concept :

This project aims to sort one stack using another one with some instructions, for example you have two stack (a) and (b).
The stack (a) holds unsorted random numbers, and you have to sort them in an ascending order using this instructions :
(pa - pb - sa - sb - ss - ra - rb - rr - rra - rrb - rrr) .

=> Subject file is in the subject folder.

<img src="https://github.com/nowl01/push_swap/blob/master/subject/1_rXKk8juFHQaLzI-uJyEVog.png">

## The instructions :

### (pa - pb) :
-> Push the first element to the stack . 
(pa) for stack a, (pb) for stack b .

<img src="https://github.com/nowl01/push_swap/blob/master/subject/push.png">

### (sa - sb - ss) :
-> Swap the two first elements in the stack .
(sa) for stack a, (sb) for stack b .
-> (ss) for both instructions (sa - sb) at the same time.

<img src="https://github.com/nowl01/push_swap/blob/master/subject/swap.png">

### (ra - rb - rr) :
-> Rotate one time the elements of stack with the contrary direction of clockwise .
(ra) for stack a, (rb) for stack b .
-> (rr) for both instructions (ra - rb) at the same time.

<img src="https://github.com/nowl01/push_swap/blob/master/subject/rotate.png">

### (rra - rrb - rrr) :
-> Rotate one time the elements of stack with the same direction as clockwise .
(rra) for stack a, (rrb) for stack b .
-> (rrr) for both instructions (rra - rrb) at the same time.

<img src="https://github.com/nowl01/push_swap/blob/master/subject/r_rotate.png">

## The algorithm :

<a href="https://diyanazizo13.medium.com/fastest-push-swap-algorithm-2f510028602b">algorithm 1 </a> by <a href="https://github.com/zainabdnaya">zainabdnaya</a> & <a href="https://github.com/Hamzaelkhatri">Hamzaelkhatri</a>

<a href="https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a"> algorithm 2 </a>

## VISUALIZER :

- If you want to see the visualiation of sorting check this account <a href="https://github.com/o-reo/push_swap_visualizer">visualizer . </a>

<img src="https://github.com/nowl01/push_swap/blob/master/subject/visualizer.png">

### How to run:
- Run ->**make**<- command .
- Then run ->**./push_swap**<- with list of numbers of your choice .
- if you want to generate random numbers run ->**python3 generate_random_nums.py**<- and choose the size you want...

## Checker :

-> Checker is a program that checks if your push_swap did sort the random numbers.

### How to run:
- Run ->**make bonus**<- command .
- Then run ->**$arg="list of numbers of your choice " ; ./push_swap $arg | ./checker $arg**<- with list of numbers of your choice .
