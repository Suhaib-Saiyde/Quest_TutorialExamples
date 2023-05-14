def first(a,b):
	def second(c):
		return(a+b+c)
	return(second)
add=first(2,3)
x=add(5)
print("The total sum is",x)
