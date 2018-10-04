def orangecap(dict1):
    dict2 = {}
    for k1 in dict1:
        for k2 in dict1[k1]:
            dict2[k2] = dict2.get(k2, 0) + dict1[k1][k2]
    player = max(dict2, key=dict2.get)
    return player, dict2[player]
def addpoly(p1,p2):
    i=0
    su=0
    j=0
    c=[]
    if len(p1)==0:
        #if p1 empty
        return p2
    if len(p2)==0:
        #if p2 is empty
        return p1
    while i<len(p1) and j<len(p2):
        if int(p1[i][1])==int(p2[j][1]):
            su=p1[i][0]+p2[j][0]
            if su !=0:
                c.append((su,p1[i][1]))
            i=i+1
            j=j+1
        elif p1[i][1]>p2[j][1]:
            c.append((p1[i]))
            i=i+1
        elif p1[i][1]<p2[j][1]:
            c.append((p2[j]))
            j=j+1
    if p1[i:]!=[]:
        for k in p1[i:]:
            c.append(k)
    if p2[j:]!=[]:
        for k in p2[j:]:
            c.append(k)
    return c  
def multpoly(p1,p2):
    p=[]
    s=0
    for i in p1:
        c=[]
        for j in p2:
            s=i[0]*j[0]
            e=i[1]+j[1]
            c.append((s,e))
        p=addpoly(c,p)
    return p 
import ast

def todict(inp):
    inp = ast.literal_eval(inp)
    return (inp)

def topairoflists(inp):
    inp = "["+inp+"]"
    inp = ast.literal_eval(inp)
    return (inp[0],inp[1])

fncall = input()
lparen = fncall.find("(")
rparen = fncall.rfind(")")
fname = fncall[:lparen]
farg = fncall[lparen+1:rparen]

if fname == "orangecap":
   arg = todict(farg)
   print(orangecap(arg))
elif fname == "addpoly":
   (arg1,arg2) = topairoflists(farg)
   print(addpoly(arg1,arg2))
elif fname == "multpoly":
   (arg1,arg2) = topairoflists(farg)
   print(multpoly(arg1,arg2))
else:
   print("Function", fname, "unknown")
  


