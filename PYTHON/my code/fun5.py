def fact(n):
	if n==1:
		return(n)
	else:
		f=n*fact(n-1)
		return(f)
a=int(input("Enter a number\n"))
n=fact(a)
print("The factorial is",n)
