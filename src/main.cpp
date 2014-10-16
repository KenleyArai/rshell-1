#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <wait.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <errno.h>

using namespace std;

int main()
{
  int pid = fork();
  
  if(pid == 0)
  {
     char *argv[4];
     argv[0] = new char[4];
    
      strcpy(argv[0],"ls");
     if(argv[0] == "ls")
     {
       argv[1] = "-a";
       strcpy(argv[1],"-a");

       argv[2] = "-l";
       strcpy(argv[2],"-l");

       argv[3] = "-d";
       strcpy(argv[3],"-d");
       
       execvp("ls",argv);
     }

      strcpy(arg[0],"mkdir");    
     else if(argv[0] == "mkdir")
     { 
       argv[1] = "-m";
       strcpy(argv[1],"-m");

       argv[2] = "-p";
       strcpy(argv[2],"-p");

       argv[3] = "-v";
       strcpy(argv[3],"-v");

       execvp("mkdir",argv);  
      }

      else if(argv[0] == "git")
      {
        argv[0] = new char[4];
        strcpy(argv[0],"git");
        argv[1] = "commit";
        argv[2] = "-p";
        argv[3] = "-v";

        execvp("mkdir",argv); 
      }
     
     cout << "i'm a child." << endl; 

   }

   else if(pid == -1)
    {
	perror("There was an error in the fork()");
	wait(NULL);
	cout << "I'm a parent." << endl;
	} 
   else
   { 
   return(0);
    }
}

