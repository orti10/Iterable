# Iterable

Code by Ortal Hanoch, Tomer Maabari and Nitzan Kravzov	:zap:

# A) class range:
Represent a range of objects, for example:
* range(a,c) is the range from a (include a) to c (not include c) = {a,b}
* range(1,4) is the range from 1 (include 1) to 4 (not include 4) = {1,2,3}

# B) class chain:
Represent a chain of two containers, for example:
* chain(range(1,4),range(5,9)) = {1,2,3,5,6,7,8}
* chain(range('a','d'),string("hello")) = {a,b,c,h,e,l,l,o}

# C) class zip:
Represents a parallel connection of two containers, , for example:
* zip(range(1,6),string("hello")) = {1,h 2,e 3,l 4,l 5,o}
Represents a series of 5 pairs arranged.

# D) class product:
Represents a cartesian product of two containers not necessarily the same length, for example:
* product(range(1,4),string("helo")) = {1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o}
Represents 12 regular pair.

# E) class powerset:
Represents all subgroups of a container, for example:
* powerset(string("abc")) = {{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c}}
Represents 8 sub-groups.
