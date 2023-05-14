n=int(input("enter the number\n"))
a=0
b=1
for i in range(0,n):
	print("%d  "%a,end="")
	f=a+b
	a=b
	b=f
	
