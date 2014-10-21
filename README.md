RSHELL
======

Licensing Information: READ LICENSE
---
Project source can be downloaded from https://github.com/SparkTesla/rshell.git

The following project is the creation of a command shell called 'rshell'. This 'rshell' will
execute the same basic bash commands such as 'ls', 'mkdir', and 'git'. The user uses these bash
commands to execute their functions. There is also test edge cases to be considered during the
input from the user.

Author & Contributor List
-----------
Angel Avendano

All other known bugs and fixes can be sent to aaven004@ucr.edu

All reported bugs/fixes will be submitted to correction within my github account SparkTesla.


File List
---------
```
.:

rshell
```
```
rshell:

bin/

LICENSE

README.md

Makefile

src/

tests/

```
```
src:

main.cpp
```

```
tests:

exec.script
```
```
###BUGS

1. Connectors `;` , `&&` and `||` are not implemented in `main.cpp`. It will cause errors.

2. This `rshell` has not made it to the final stages at the point using the `valgrind' debugging tool.

