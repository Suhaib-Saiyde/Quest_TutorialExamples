a=input("Enter a string\n")
b=[]
c=[]
d=[]
n=len(a)
for i in range(0,n):
	if a[i]>='A' and a[i]<='Z' or a[i]>='a' and a[i]<='z':
		b.append(a[i])
	elif a[i]>='0' and a[i]<='9':
		c.append(a[i])
	else:
		d.append(a[i])
print(b)
print(c)
print(d)
