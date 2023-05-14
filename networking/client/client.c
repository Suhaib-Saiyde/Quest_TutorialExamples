#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>

void main()
{

char s[20];
int len,ret,q;
struct sockaddr_in v,v1;
int sfd,nsfd;

sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{
	perror("SOCKET");
	return;
}
perror("SOCKET");
printf("SFD=%d\n",sfd);
////////////////////////////////////////////////////////////////////////

v.sin_family=AF_INET;
v.sin_port=htons(4000);
v.sin_addr.s_addr=INET_addr("127.0.0.1");
len=sizeof(v);
ret=connect(sfd,(struct sockaddr*)&v,len);
if(ret<0)
{
	perror("Connect");
	return;
}
perror("Connect");
//////////////////////////////////////////////////////////////////////////

printf("Enter the data\n");
scanf(" %[^\n]s",s);
write(sfd,s,strlen(s)+1);

}
