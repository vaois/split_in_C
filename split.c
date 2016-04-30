#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc,char *argv[])
{
   // char block[1024];
    char c; //+
    int in, out,out1; 
    int nread;
    size_t len;
    struct stat statbuf;
    size_t avg;
    if(argc < 3)
    {
    	printf("usage:%s [filein] [fileout1] [fileout2]",argv[0]);
    	exit(1);
    }
    in = open(argv[1], O_RDONLY);
    stat(argv[1],&statbuf);
    len=statbuf.st_size;
    avg=len/2; 
    printf("size %d\n",len);
    out = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    out1 = open(argv[3], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);   
   // printf("01\n");
   // while((nread = read(in,block,sizeof(block))) > 0 && avg>0)
   //    { write(out,block,nread);
             // avg-=1024;
      // }
     while(read(in,&c,1) == 1)
      {    if(avg>0)
          {  write(out,&c,1);
              avg--;
	      }
     else
      {

	write(out1,&c,1);

      }
 // printf("avg %d",avg);
   //  lseek(in,0,SEEK_CUR);
    //out1 = open(argv[3], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
  // printf("02\n");
    //while((nread = read(in,block,sizeof(block))) > 0)
      // write(out,block,nread);
       } 
       close(in);
       close(out);
       close(out1); 
    exit(0);
}

