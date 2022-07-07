# ft_ls
ft_ls is the first project from the Unix branch in Hive Helsinki. The objective is to recode the extremely handy `ls` program which lists files and directories.

## Objectives:

- The objective is to recode the `ls` program and implement the following flags `-l, -a, -R, -t, -r`.
- No memory leaks.
- Program cannot segfault or crash in anyway.

## Initial steps:

I started the project by learning about directory streams and reading the manual for system calls such as `opendir`, `readdir`, `closedir`. I had a vague idea on how I would start coding the project:

1.  Parsing the arguments for flags.
2.  Opening and reading a directory stream, and storing the data from `stat()` and `lstat()`.
3.  Long and short output.
4.  Sorting flags `-r` and `-t` and ascending sort for all cases. 
5.  Recursion flag `-R`.
6.  Handle filenames/directories from arguments
7.  Fix minor things related to pathnames and 

### Challenges:

- **Data structure**:
  - how to store data? Linked lists or array of structs (ended up using the latter).
- **Recursion `-R`-flag**:
  - how to implement the recursion maintain the correct path.
- **System calls**:
  - reading the *man* pages and actually understanding what all the allowed system calls and functions do, return, and handle errors.

## Learnings:

### Failures:
- **Planning**
  - plan ahead before coding.
  - sketch more on paper.
  - show your ideas to your peers more often.
  
>My planning failed until the project was halfway done. I Should have started with the `-R`-flag before everything else (as suggested in the instructions). At this point I had to restructure the whole program and I planned on paper on how to do it.
  
- **When you get stuck**
  - ask help more often.
  - use peers as rubber ducks more often.
  
>Occasionally you end up stuck with your thinking and can't get the problem solved. This happened quite often and in the beginning I was quite stubborn and did want to solve the issues by myself which was a mistake. Only when I started bouncing ideas to my peers and talking about problems in my program I was able to understand how to solve them. It is quite remarkable how we realise we already know the answer to the problem by talking it out loud to someone.

### Successess:
- **Functions**
  - kept my code clean and documented since the beginning of the project.
  - kept functions as simple as possible (doing one thing only).
  - write code according to the school's norme.
  - valuable lessons about malloc() protection.
