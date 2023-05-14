def fib(n):
	a=0
	b=1
	for i in range(0,n):
		f=a+b
		a=b
		b=f
		print(f,end="")

n=int(input("enter the number\n"))
print('01',end='')
fib(n)


