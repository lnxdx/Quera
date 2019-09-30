stk=[]
Q=[]
prec={'-':1, '+':1, '*':2, '/':2}
s=input()
for i in range(len(s)):
  c=s[i]
  if c>='A' and c<='Z': Q=[c]+Q  
  elif c=='(':
    stk+=[c]
  elif c==')':
    while stk[-1]!='(':
      Q=[stk.pop()]+Q
    stk.pop()
  else:
    while len(stk)!=0 and stk[-1] in '+-*/' and (prec[c]<=prec[stk[-1]]):
      Q=[stk.pop()]+Q
    stk+=[c]
while len(stk):
  Q=[stk.pop()]+Q
while len(Q):
  print(Q.pop(),end='')
