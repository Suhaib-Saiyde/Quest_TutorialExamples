#f=open("phonebook.txt","w")
#f.close()
ph_num={}
c='y'
while(c=='y'):
	a=int(input("press 1.check    2.add   3.delete"))
	if a==1:
		search=input("enter name\n")

		if search in ph_num:

			
			print(ph_num.get(search))
			#f=open("phonebook.txt","a")
			#f.write("%s %d"%(search,ph_num.get(search)))
			#f.close()

		else:	
			print("DATA NOT FOUND")
			n=input("do you want to add this person? y/n")
			if n=='y':
				ph_num.update({search:int(input("number:"))})
				f=open("phonebook.txt","a")
				f.write("%s %d"%(search,ph_num.get(search)))
				f.close()

	if a==2:
		
		ph_num.update({input("enter name"):int(input("number:"))})
		f=open("phonebook.txt","a")
		f.write("%s %d"%(search,ph_num.get(search)))
		f.close()

	c=input("press y to coninue")
	if a==3:
		b=input("enter name to be delete")
		del ph_num[b]

