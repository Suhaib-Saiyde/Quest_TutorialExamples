a=int(input("enter num1\n"))
b=int(input("enter num2\n"))
def arith(a,b):
	c=int(input("press 1.sum 2.sub 3.mul 4.div\n"))
	if c is 1:
		print("sum =",a+b)
	elif c is 2:
        	print("sub =",a-b)
	elif c is 3:
        	print("mul =",a*b)
	elif c is 4:
        	print("div =",a/b)
	else:
		print("invalid operation")
print(arith(a,b))
