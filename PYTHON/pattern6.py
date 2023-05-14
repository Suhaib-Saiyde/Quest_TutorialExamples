n=int(input("enter the lines\n"))
c1=0
c2=0
z=65
for i in range(1,n+1):
	for j in range(1,n+1-i):
		print(" ",end='')
		c1=c1+1
	for k in range(2*i-1):
		if(c1<=n-1):
			print("%c"%(z+k),end='')
			c1=c1+1
		else:
			c2=c2+1
			print("%c"%(z+k-2*c2),end='')
	c1=c2=k=0
	print("\n",end='')

