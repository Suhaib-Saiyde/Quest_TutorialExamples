e=int(input("Enter a three digit number\n"))
n=e
s=0

r=n%10
c=r**3
n=n//10

p=n%10
k=p**3
n=n//10

u=n%10
v=u**3

s=c+k+v
print(s, c, k, v)
if(e==s):
	print(e,"is an armstrong number\n")
else:
	print(e,"is not an armstrong number\n")
