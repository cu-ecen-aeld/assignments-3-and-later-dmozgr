#include "stdio.h"
#include "syslog.h"
#include "errno.h"
#include "string.h"
#include "stdlib.h"

int main(int argc,char **argv)
{
    int argCount =  argc -1;
    openlog(NULL,0,LOG_USER);
    
    if(argCount != 2)
    {
        printf("Invalid number of arguments, expected 2 insted of %d argument",argCount);
        syslog(LOG_ERR,"Invalid number of arguments, expected 2 insted of %d argument",argCount);
        exit(1);
    }

    char writefile[50]; strcpy(writefile,argv[1]);
    char writestr[50]; strcpy(writestr,argv[2]);
    
    FILE *targetFile;
    targetFile = fopen(writefile,"w+");
    
    if(errno == 0)
    {
        int rc = fprintf(targetFile,"%s",writestr);

        if(rc < 0)
        {
            printf("could not write to file %s\n", writefile);
            syslog(LOG_ERR, "Could not write to file %s", writefile);
            exit(1);
        }
        syslog(LOG_DEBUG,"writing %s to %s",writestr,writefile);
    }
    else
    {
        syslog(LOG_ERR,"An error occured for %s, could not be opened.",writefile);
        exit(1);
    }

    fclose(targetFile);

    return 0;
}
