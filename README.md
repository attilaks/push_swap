# push_swap, School 21/42 project.

The goal of this project is to write a sorting algorithm "push_swap" which uses 11 types of operations:

***

**sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

**sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

**ss** : sa and sb at the same time.

**pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

**pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

**ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

**rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

**rr** : ra and rb at the same time.

**rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

**rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

**rrr** : rra and rrb at the same time.

***

The result of the program is several lines of this commands

Another goal is to write program "checker" which will check if 
"push_swap" prodused the correct lines of commands to sort the incoming integers.
If the commands sort the integers, checker will write "OK". If not, it'll write "KO".

As a bonus I made a graphical visualization of the sorting process. If you want to see it, you should type:

ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG

If no visualization needed, just don't use the "-v" flag.
