o=0
while(o==0):
    print("press 1 to encrypt")
    print("press 2 to decrypt")
    print("press 3 to exit")
    choice=int(input("enter the choice"))
    if(choice==1):
        mss=input("enter the message to encrypt.")
        key=int(input("enter the key to encode"))
        lenght=len(mss)
        q=list(mss)
        b=[]
        c=[]
        for i in q:
            b.append(ord(i))
        for i in range (lenght):
            b[i]=b[i]+key
        for i in b:
            c.append(chr(i))
        print(''.join(c))
    
    if(choice==2):
        mss1=input("enter the message to decrypt.")
        key=int(input("enter the key to decode"))
        lenght1=len(mss1)
        q=list(mss1)
        b=[]
        c=[]
        for i in q:
            b.append(ord(i))
        for i in range (lenght1):
            b[i]=b[i]-key
        for i in b:
           c.append(chr(i))
        print(''.join(c))
    if(choice==3):
        o=1
else:
    print("Thank you")
         

