n=int(input("enter the lines\n"))
for i in range(1,n+1):
	for j in range(1,n+1):
		if(i==1 or j==1 or j==n-i+1 or i==j or j==n):
			print("*",end='')
		else:
			print(" ",end='')
	print(" ")
