# ft_ls
ft_ls is the first project from the Unix branch in Hive Helsinki. The objective is to recode the extremely handy `ls` function.

## Objectives:

- The objective is to recode the `ls` function and implement the following flags `-l, -a, -R, -t, -r`.
- No memory leaks allowed.
- Program cannot segfault.

## Initial steps:

I started the project by learning about directory streams and reading the manual for system calls such as `opendir`, `readdir`, `closedir`. I had a vague idea on how I would start coding the project:

1.  Parsing the arguments for flags.
2.  Opening and reading a directory stream.
3.  Long and short output.
4.  Sorting flags `-r` and `-t` and ascending sort for all cases. 
5.  Recursion flag `-R`.
6.  Handle filenames/directories from arguments

### Challenges:

- I didn't do the **ft_printf** project as I wanted to prove the project instructions wrong (which state that doing this without ft_printf is like eating soup with a fork.) Now I can say that **ft_printf** is not needed for this project.
- Using linked list or array of structs (ended up using the latter).
- Recursion and maintaining the correct path to files was challenging at first.
- How to solve device special and block special files in long format.
