ph_num={}
c='y'
while(c=='y'):
	a=int(input("press 1.check    2.add   3.delete"))
	if a==1:
		search=input("enter name\n")

		if search in ph_num:
			print(ph_num.get(search))
		else:	
			print("DATA NOT FOUND")
			n=input("do you want to add this person? y/n")
			if n=='y':
				ph_num.update({search:int(input("number:"))})
	if a==2:
		ph_num.update({input("enter name"):int(input("number:"))})
	c=input("press y to coninue")
	if a==3:
		b=input("enter name to br delete")
		del ph_num[b]

