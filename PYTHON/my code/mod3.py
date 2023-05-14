d={}
a=input("Enter a string\n")
n=len(a)

for i in range(0,n):
	d.update({str[i]:ord(str[i])})	
print(d)
