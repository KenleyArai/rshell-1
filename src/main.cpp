#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <wait.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pwd.h>


using namespace std;


int main()
{
  string EXIT = "exit";		// exit() declaration

  while(true)		           // Does not exit the program until exit() is invoked
 {
   string command;                 // set bash commands as strings
   char * get_login = getlogin();  // set getlogin

   cout << get_login;		   // print login on the prompt

   int g = gethostname(get_login, 30);  // get hostname from login
   
   if(g == 0)                      // if true, then hostname is found
   {
    cout << "@" << get_login;      // print hostname
   }
   else
   {
    perror("No hostname");
   }

   cout << "$ ";	       // The prompt shows $ in the beginning
   getline(cin,command);       // Get the input from user
                     	       // It is set into the variable pid (Processor ID).
   if(command.compare(EXIT) == 0)	 
	exit(0);

   
   char *cmd = new char[command.length() + 1]; 
   strcpy(cmd, command.c_str());
   char **argv = new char*[command.length() + 1];
   char *token;

   token = strtok(cmd, " ");
    
   int i = 0;
   
   while( token != NULL )
   {
    argv[i] = token;
    token = strtok(NULL, " "); 
    i++;
   }
   
   argv[i] = 0;	           //Sets the null pointer
  
   int pid = fork();       // The return value when fork() is performed is a 0 or -1.

   if(pid == -1)           // If pid equals to -1 then the fork failed.
   {
     perror("fork() failed completely");   // Prints an error message when fork() failed
    
   }

/* If pid equals to 0 then the fork succeeded. Contents from the parent process 
   is given to the new child process*/

   else if(pid == 0)     
   {
    //perror(";"); 
    cout << "i'm a child" << endl;	
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



