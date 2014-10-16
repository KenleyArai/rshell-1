#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <wait.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  

  int pid = fork();
  
  if(pid == 0)
  {
     
     char *argv[4];     
     argv[0] = new char[4];
     
     if(argv[0] = "ls")
     {
       strcpy(argv[0],"ls");
       argv[1] = "-a";
       argv[2] = "-l";
       argv[3] = "-d";
       
       execvp("ls",argv);
     }
    
     else if(argv[0] = "mkdir")
     { 
       argv[0] = new char[4];
       strcpy(argv[0],"mkdir");
       argv[1] = "-m";
       argv[2] = "-p";
       argv[3] = "-v";

       execvp("mkdir",argv);  
      }

      else if(arg[0] = "git")
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

   else{
	wait(NULL);
	cout << "I'm a parent." << endl;
	
	}



return(0);
}

