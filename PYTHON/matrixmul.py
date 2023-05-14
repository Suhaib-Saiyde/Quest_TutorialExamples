
r=int(input("enter the row\n"))
c=int(input("enter the coloumn\n"))
L=[[int(input("enter the element\n"))for i in range(c)]for j in range(r)]
print("L=",L)
p=int(input("enter the row\n"))
q=int(input("enter the coloumn\n"))
L1=[[int(input("enter the element\n"))for i in range(q)]for j in range(p)]
print("L1=",L1)
sum=0
result=[]
for i in range(r):
	a=[]
	for j in range(c):
		a.append(0)
	result.append(a)

for i in range(r):
	for j in range(q):
		for k in range(c):
			result[i][j]+=L[i][k]*L1[k][j]

print("R=",result)


#L2=[[(sum+L[i][k]*L1[k][j]) for k in range(c) for j in range(q)]for i in range(r)]
