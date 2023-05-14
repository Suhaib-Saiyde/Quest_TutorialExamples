n=int(input("enter the lines\n"))
c=65
for i in range(1,n+1):
	for j in range(1,(n+1)+(i-1)):
		if((j==(n-(i-1)))or(j==(n+(i-1)))):
			print("%c"%(c+(i-1)),end='')
		else:
			print(" ",end='')
	print("\n",end='')

