#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <wait.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

using namespace std;

//char **Tokenizer(string command);

int main()
{
  string EXIT = "exit";		// exit() declaration

  while(true)		       // Does not exit the program until exit() is invoked
 {
   string command;             // create the bash commands as strings
 
   cout << "$ ";	       // The prompt shows $ in the beginning
   getline(cin,command);       // Get the input from user
                     	       // It is set into the variable pid (Processor ID).
   if(command.compare(EXIT) == 0)	 
	exit(0);

  //arg_rep[10000] =  Tokenizer(command);
   char *cmd = new char[command.length() + 1]; 
   strcpy(cmd, command.c_str());
   char **argv = new char*[10000];
   char *token;

   token = strtok(cmd, " ");
    
   int i = 0;
   while( token != NULL)
   {
    // cout << token << endl;

    argv[i] = token;
    token = strtok(NULL, " "); 
    i++;
   }
    	 
   argv[i] = 0;


   int pid = fork();       // The return value when fork() is performed is a 0 or -1.

   if(pid == -1)           // If pid equals to -1 then the fork failed.
   {
     perror("fork() failed completely");   // Prints an error message when fork() failed
    
   }

/* If pid equals to 0 then the fork succeeded. Contents from the parent process 
   is given to the new child process*/

   else if(pid == 0)     
   { 
	
    execvp(argv[0], argv);
   
   }

   else
   {
    wait(0);
    cout << "I'm a parent." << endl; 
   }
 }
   return(0);
}

