

This directory contains exercises and solutions for a hands-on
OpenMP course.  Information about these programs can be found
in the comments and in the slides from the course.

To use these programs, compile with an OpenMP enabled compiler.  
For example:

   gcc -fopenmp pi.c

Alternatively, you can edit the makefile so it points to the appropriate compiler 
on your system and then use the following command to build and test all the programs.

   make test

The solutions directory follows the same conventions so you can build and test
everything by just typing "make test". 

The directory also contains a collection of ChallengeProblems
for more advanced students.  These programs
have not been carefully tested and may have problems building
and running on some systems.


