def see(*b):
	b=list(b)
	n=len(b)
	
	for i in range(0,n):
		print(b[i])
l=[]
a=input("enter the commands\n")
l=a.split(',')
see(l)
