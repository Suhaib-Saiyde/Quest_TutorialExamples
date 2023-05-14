n=int(input("Enter a number\n"))
b=0
for i in range(1,n):
	if(n%i==0):
		b+=1
if(b==1):
	print(n,"is a prime number\n")
else:
	print(n,"is not a prime number\n")
