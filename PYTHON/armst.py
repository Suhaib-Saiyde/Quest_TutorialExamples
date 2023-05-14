a=input("enter 3 digit number\n")
b=a/100
c=(a%100)/10
d=(a%100)%10
e=((b*b*b)+(c*c*c)+(d*d*d))
if(a==e):
	print "armstrom number"
else:
	print "not armstrom number"
