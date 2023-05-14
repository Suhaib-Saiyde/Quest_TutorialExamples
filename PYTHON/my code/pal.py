n=int(input("Enter a number\n"))
r=0
c=0
q=n
while(q!=0):
	c=c*10
	r=q%10
	c=c+r
	q=q//10
if(n==c):
	print(n,"is a palindrome")
else:
	print(n,"is not a palindrome")
