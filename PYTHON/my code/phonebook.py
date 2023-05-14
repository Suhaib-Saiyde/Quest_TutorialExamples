d={}
c='y'
while c=='y':
	x=int(input("press 1.check 2.add 3.delete 4.print whole list\n"))
	if x==1:
		a=input("Enter the name to be checked:\n")
		if a in d:
			print("The number is",d[a])
		else:
			print("DATA NOT FOUND\n")
			ab=input("Do you want to add this person? y/n\n")
			if ab=='y':
				d.update({a:int(input("Enter the number:\n"))})
	if x==2:
		d.update({input("Enter the name:\n"):int(input("Enter the number:\n"))})
	if x==3:
		a=input("Enter the name to be deleted from the phonebook:\n")
		del d[a]
	if x==4:
		print(d)
	
	c=input("press y to continue\n")
	if c!='y':
		print("Invalid Entry\n")
		break
