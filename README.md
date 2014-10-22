RSHELL
======

Licensing Information: READ LICENSE
---
Project source can be downloaded from https://github.com/SparkTesla/rshell.git

The following project is the creation of a command shell called 'rshell'. This 'rshell' will
execute the same basic bash commands such as 'ls', 'mkdir', and 'git'. This project will work on forks between the parent and child processes. You can connect bash commands with connectors `;`, `&&`, and `||`. This allows multiple bash comments on one line.

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

BUGS
----

In main.cpp
-------
1. Connectors `;` , `&&` and `||` are not implemented in `main.cpp`. It will cause errors with any bash command using these connectors.

2. There will be an runtime error where if user messes up on the bash command then the amount of times user errors appear will be the number of times the `exit` command has to be inputted.

3. If the user prompts two bash with connectors, one bash command with a connector ONLY, or having theTesting the case for `cat main.cpp` will lose the prompt and will be stuck in a infinite loop.

4. Did not parse the string to get characters within the input of the bash command.

5. The connector `;` in main.cpp will run but can only run the first segment of the bash command then ignores anything after the connector `:`.

6. Typing `ls -l; pwd` or any bash command after the connector `;` will execute ls but ignores the rest of the string including the flag `-l`.
