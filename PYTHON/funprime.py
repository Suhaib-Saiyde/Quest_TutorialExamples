def prime(n):
	if(n>=2):
		for i in range(2,n):
			if(n%i==0):
				flag=1
				return flag

n=int(input("enter the number\n"))
a=prime(n)

if(a==1):
	print("not prime")
else:
	print("prime number")
