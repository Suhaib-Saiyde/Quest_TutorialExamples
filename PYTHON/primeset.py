n=int(input("enter the range\n")
c=0
for i in range(2,n+1):
	for a in range(2,i/2):
		if((i%a)==0):
			c=1
			break
	if(flag==0):
		print("%d"%i,end='')
