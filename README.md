# Nihongo

Programs to help in the learning of the Japanese language.


## Requirements

I personally use Slackware GNU/Linux, which comes with all the compilers and
libraries I need. In case you have a different Linux distro, I think it is
fairly easy to configure.

* Firstly, one needs the consoles to be using UTF-8. Japanese characters are
  not part of ASCII, so we need to use multi-byte characters available from the
  UTF-8 character set.
* Then, the compiler we are using is the GNU C Compiler (gcc).
* Finally, if you are not on Linux, I think you can use the popular compilers C
  for your OS. The dependencies of the programs are pretty standard. I think it
  will work as long as you ensure that the header files are present on your
  OS or in your compiler software bundle.


### random_num_rep.c

Program which generates a random number in a range specified by the user. It
displays the number in western/arabic format and then converts the number to
japanese numerals at the press of the ENTER button. It is a very good way to
exercise with numbers in the japanese language.

To compile:
```
$ gcc -o random_num_rep random_num_rep.c global_charset.c functions.c
```

To run the program:
```
$ ./random_num_rep LOWERLIM UPPERLIM
The program generates random numbers in a range delimitered by 
LOWERLIM and UPPERLIM.
LOWERLIM: lower limit of the range, cannot be smaller than 0;
UPPERLIM: upper limit, cannot be greater than MAXNUM, where MAXNUM is defined
in the header file nihongo.h as the number 1,000,000,000,000,000,000 (1e+18).
```
