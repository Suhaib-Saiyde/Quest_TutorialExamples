L=[]
L1=[]
r=3
c=3
L2=[]
L=[[int(input("enter the element\n"))for i in range(c)]for j in range(r)]
print("L",L)
L1=[[int(input("enter the element\n"))for i in range(c)]for j in range(r)]
print("L1",L1)
L2=[[(L[i][j]+L1[i][j])for j in range(c)]for i in range(r)]
print("L2",L2)
