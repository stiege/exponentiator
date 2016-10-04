# Exponentiator

This repository is an example of doing some big number arithmetic in c++.

## Setup

`vagrant up` will create an environment, build the executable and run all unit tests. CTest will report that 2 tests have succeeded, these are actually suites. If one does fail you can `vagrant ssh` in and execute the entire suite to get some more information.

## Design
The design is fairly straight forward, the exponentiator is the class that depends on the GNU MP bignum library. It is passed a number and performs an exponentiation on it; in its constructor it's passed in a modifier function that can modify how the exponent is modified from the base.

Aside from the exponentiator the only interesting part is the specific modifier that is used for the project - a reverse function to swap digits.

In `main.c` you can find some checks for user input and then the construction of the exponentiator with the reverse function.

## Further work
Not too many comments are through the code. On one hand a few around the headers would be good, but this readme as the front page can explain the picture and intent likely better than any local comments can. For further clarification on what the reverse of exponentiator does, see the unit tests.

I was going to write some python functional tests also but ran out of time, these would just call the built executable from the command line and ensure the user interface was correct.
