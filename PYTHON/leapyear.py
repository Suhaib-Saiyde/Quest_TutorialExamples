a=input("enter the year")
if((a%100)==0):
	if((a%400)==0):
		print "leap year"
	else:
		print "non leap year"
elif((a%4)==0):
	print "leap year"
else:
	print "non leap year"
		
