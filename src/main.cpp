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

//bool Connector(char * tok);
void Exec_VP(int char_limit, char**argv);

int main()
{
  string EXIT = "exit";		// exit() declaration
  string command;                 // set bash commands as strings

  while(true)		           // Does not exit the program until exit() is invoked
 {
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

   cout << " $ ";	       // The prompt shows $ in the beginning
   getline(cin,command);       // Get the input from user
                     	       // It is set into the variable pid (Processor ID).
   if(command.compare(EXIT) == 0)	 
	exit(0);

   int cmd_limit = command.length() + 1;
   char *cmd = new char[cmd_limit]; 

   strcpy(cmd, command.c_str());
   char **argv = new char*[cmd_limit];
   char * token;
   //char *token2, *token3, *token4;

   token = strtok(cmd, " ");
   //token2 = strtok(cmd, ";");
   //token3 = strtok(cmd, "&");
   //token4 = strtok(cmd, "|");
   
    
   int i = 0;

   while(token != NULL)
   {
    argv[i] = token;
    token = strtok(NULL, " ");

   /* if(Connector(token2) == true)
    {  
     Exec_VP(i, argv);
    }*/
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
     execvp(argv[0], argv); 
   }

   else
   {
    wait(0);
    //cout << "I'm a parent." << endl; 
   }
 }
   return(0);
}


/*bool Connector(char * tok)
{
  if(tok == ";")
  {
    return(true);
  }
  else if(tok == "&&")
  {
    return true;
  }
  else if(tok == "||")
  {
    return true;
  }
 return false;
}

void Exec_VP(int char_limit, char**argv)
{
  execvp(argv[char_limit], argv);
  return;
}
*/
