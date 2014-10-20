#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <wait.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/*
const int char_limit = 10000;

char *String_Parsing(int argc, char *argv[]);
*/
using namespace std;

int main()
{
  int pid = fork();       // The return value when fork() is performed is a 0 or -1.
                          // It is set into the variable pid (Processor ID).
 
  if(pid == -1)           // If pid equals to -1 then the fork failed.
  {
    perror("fork() failed completely");   // Prints an error message when fork() failed
    
  }

  else if(pid == 0)             /* If pid equals to 0 then the fork succeeded. All contents from the parent process is given to the new child process*/
  {
    string command;
     
    cout << "$ ";
    getline(cin,command);
    char *cmd = new char[command.length() + 1];
    strcpy(cmd, command.c_str());
    char **argv = new char*[100];
    char *token;

    token = strtok(cmd, " ");

    int i = 0;
    while( token != NULL)
    {
      cout << token << endl;

      argv[i] = token;
      token = strtok(NULL, " ");
      i++;
    }

    argv[i] = 0;

    execvp(argv[0], argv);
   
    cout << "Print: " << command << endl;

    
  //  cout << "$ ";

   // cin.getline(cin, name);

   // stcrcpy(name, cmd);

    
    
   // execvp("ls", cmd);
   // execvp("mkdir", argv2);
   // execvp("g++", argv3);

    cout << "i'm a child" << endl;  // prints out if fork succeeded then the child process is created

   }

  else
  {
   wait(0);
   cout << "I'm a parent." << endl;

  }

   return(0);

}


char *String_Parsing(int argc, char *argv[])
{
     

}
