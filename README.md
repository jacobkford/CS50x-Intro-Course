<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/jacobkford/CS50x-Intro-Course">
    <img src="https://prod-discovery.edx-cdn.org/media/course/image/da1b2400-322b-459b-97b0-0c557f05d017-3b9fb73b5d5d.small.jpg" alt="Logo" width="370" height="210">
  </a>

  <h3 align="center">CS50x - Introduction to Computer Science</h3>

  <p align="center">
    This is my repository for the solutions I submitted for Harvard University's Computer Science course CS50.
    <br />
    <br />
    <a href="https://www.edx.org/course/cs50s-introduction-to-computer-science">edX</a>
    ·
    <a href="https://cs50.harvard.edu/x/2020/">Course Materials</a>
    ·
    <a href="https://ide.cs50.io/">IDE</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [Week 0: Scratch](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset0%20-%20Scratch%20%F0%9F%98%BA)
  * [VSP - Virtual Studio Piano](https://scratch.mit.edu/projects/441235319)
* [Week 1: C](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset1%20-%20C)
  * [hello](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset1%20-%20C/hello.c)
  * [mario](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset1%20-%20C/mario.c)
  * [cash](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset1%20-%20C/cash.c)
  * [credit](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset1%20-%20C/credit.c)
* [Week 2: Crypto](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset2%20-%20Arrays)
  * [readability](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset2%20-%20Arrays/readability.c)
  * [caesar](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset2%20-%20Arrays/caesar.c)
  * [substitution](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset2%20-%20Arrays/substitution.c)
* [Week 3: Elections](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset3%20-%20Algorithms)
  * [plurality](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset3%20-%20Algorithms/plurality.c)
  * [runoff](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset3%20-%20Algorithms/runoff.c)
  * [tideman](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset3%20-%20Algorithms/tideman.c)
* [Week 4: Forensics](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset4%20-%20Memory)
  * filter
    * [less](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset4%20-%20Memory/filter%20-%20less)
    * [more](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset4%20-%20Memory/filter%20-%20more)
  * [recover](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset4%20-%20Memory/recover/recover.c)
* [Week 5: Speller](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset5%20-%20Data%20Structures)
  * [speller](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset5%20-%20Data%20Structures/speller)
* [Week 6: Python](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset6%20-%20Python%20%F0%9F%90%8D)
  * [hello](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset6%20-%20Python%20%F0%9F%90%8D/hello.py)
  * [mario](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset6%20-%20Python%20%F0%9F%90%8D/mario.py)
  * [cash](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset6%20-%20Python%20%F0%9F%90%8D/cash.py)
  * [credit](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset6%20-%20Python%20%F0%9F%90%8D/credit.py)
  * [readability](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset6%20-%20Python%20%F0%9F%90%8D/readability.py)
  * [DNA](https://github.com/jacobkford/CS50x-Intro-Course/blob/main/pset6%20-%20Python%20%F0%9F%90%8D/dna/dna.py)
* [Week 7: SQL](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset7%20-%20SQL)
  * [movies](https://github.com/jacobkford/CS50x-Intro-Course/tree/main/pset7%20-%20SQL/movies)



## Week 0: Scratch

Link to the virtual piano I created : 
```javascript
https://scratch.mit.edu/projects/441235319/#fullscreen
```



## Week 1: C
**hello.c** : requests for the users name, then responds with a greeting
```
$ ./hello
What is your name?
Jacob
hello, Jacob
```

**mario.c** : recreates a pyramid using hashes (#) for blocks.
```
$ ./mario
Height: 6
     #  #
    ##  ##
   ###  ###
  ####  ####
 #####  #####
######  ######
```

**cash.c** : counts minimum number of coins needed for a change using Greedy Algorithm
```
$ ./cash
Change owed: 0.72
6
```

**credit.c** : checks if a credit card number is valid, using the Luhn's Algorithm
```
$ ./credit
Number: 4003600000000014
VISA
```



## Week 2: Crypto
**readability.c** : computes the approximate grade level needed to comprehend some text
```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

**caesar.c** : caesar cipher some text, which supports case-sensitivity 
```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```

**substitution.c** : substitution cipher some text, which supports case-sensitivity 
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```



## Week 3: Elections
**plurality.c** : runs a Plurality election
  * *The only contribution to this project was creating the functions 'vote' & 'print_winner'*
```
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice
```

**runoff.c** : runs a Runoff election
  * *The only contribution to this project was creating the functions 'vote', 'tabulate', 'print_winner', 'find_min', 'is_tie' & 'eliminate'*
```
$ ./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
```

**tideman.c** : runs a Tideman election
  * *The only contribution to this project was creating the functions 'vote', 'record_preferences', 'add_pairs', 'sort_pairs', 'lock_pairs', 'lock_check' & 'print_winner'*
```
$ ./tideman Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
```



## Week 4: Forensics
**filter.c (less)** : applies filters to BMPs
  * *The only contribution to this project was creating the functions in helpers.c*
```
$ ./filter -r image.bmp reflected.bmp
```

**filter.c (more)** : applies filters to BMPs
  * *The only contribution to this project was creating the functions in helpers.c*
```
$ ./filter -r image.bmp reflected.bmp
```

**recover.c** : recovers JPEGs from a forensic image
```
$ ./recover card.raw
```



## Week 5: Speller
**speller.c** : spell-checks a file using a hash table
  * *The only contribution to this project was creating the functions in dictionary.c*
```
$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```



## Week 6: Python
**hello.py** : requests for the users name, then responds with a greeting
```
$ python hello.py
What is your name?
Jacob
hello, Jacob
```

**mario.py** : recreates a pyramid using hashes (#) for blocks.
```
$ python mario.py
Height: 6
     #  #
    ##  ##
   ###  ###
  ####  ####
 #####  #####
######  ######
```

**cash.py** : counts minimum number of coins needed for a change using Greedy Algorithm
```
$ python cash.py
Change owed: 0.72
6
```

**credit.py** : checks if a credit card number is valid, using the Luhn's Algorithm
```
$ python credit.py
Number: 4003600000000014
VISA
```

**readability.py** : computes the approximate grade level needed to comprehend some text
```
$ python readability.py
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

**DNA.py** : identifies a person based on their DNA
```
$ python dna.py databases/large.csv sequences/5.txt
Lavender
```



## Week 7: SQL
**movies** : SQL queries to answer questions about a database of movies
```
$ cat filename.sql | sqlite3 movies.db
```




<!-- LICENSE -->
## License

This course is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0) license. 



<!-- DISCLAIMER -->
## Disclaimer

Please do not copy & paste code from this repo if you are doing the course and haven't yet solved the problem sets, it is a violation of the [**Academic Honesty**](https://docs.cs50.net/2016/fall/syllabus/cs50.html#academic-honesty) policy of the course.
