#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
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
////////////////////////////////////////////////////////////////////////////////////////

v.sin_family=AF_INET;
v.sin_port=htons(4000);
v.sin_addr.s_addr=inet_addr("0.0.0.0");
len=sizeof(v);
ret=bind(sfd,(struct sockaddr*)&v,len);
perror("Bind");
/////////////////////////////////////////////////////////////////////////////////////////

listen(sfd,5);
perror("Listen");
printf("Before\n");
nsfd=accept(sfd,(struct sockaddr*)&v1,&len);
printf("After\n");
read(nsfd,s,sizeof(s));
printf("data=%s\n",s);

}
