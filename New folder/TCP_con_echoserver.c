#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
main(int argc,char* argv[])
{
        int sockid,rval,clen,newsid,itr,i,pid;
        struct sockaddr_in s,c;
        char m1[255];
        system("clear");
        if(argc<3){
                printf("\nUsage %s IP address, PortNo",argv[0]);
                exit(1);
        }
        printf("\nEnter the number of connection request\n");
        scanf("%d",&itr);
        sockid=socket(AF_INET,SOCK_STREAM,0);
        if(sockid==-1){
                perror("SOCK_CRE_ERR");
                exit(1);
        }
        s.sin_family=AF_INET;
        s.sin_addr.s_addr=inet_addr(argv[1]);
        s.sin_port=htons(atoi(argv[2]));
        rval=bind(sockid,(struct sockaddr*) &s,sizeof(s));
        if(rval==-1){
                perror("ERR_IN_BIND");
                exit(1);
}
        printf("Binded successfully");
        rval=listen(sockid,5);
        if(rval==-1){
                perror("ERR_IN_LISTEN");
                exit(1);
        }
        printf("\nlisten successful\n");
        for(i=0;i<itr;i++){
        clen=sizeof(c);
        newsid=accept(sockid,(struct sockaddr *)&c,&clen);
        if(newsid==-1){
                perror("ERR_IN_ACCEPTING");
                exit(1);
        }
        printf("Success in accept\n");
        pid=fork();
        if(pid==-1){
                perror("Error in creating child process");
                exit(1);
        }
        if(pid==0){
        rval=recv(newsid,m1,sizeof(m1),0);
        if(rval==-1){
                perror("ERROR_IN_RECEIVEING");
                exit(1);
        }
        printf("\nMessage Receive by server is %s",m1);
        rval=send(newsid,m1,sizeof(m1),0); if(rval==-1){
                perror("ERR");
                exit(1);
        }
        printf("\nMessage send by server is %s\n",m1);
        close(newsid);
        exit(0);
        }
        else{
        close(newsid);
        }}
        close(sockid);
}
