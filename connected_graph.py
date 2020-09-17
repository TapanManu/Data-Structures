# isomorphism

G1={'e1':('v1','v2'),'e2':('v2','v3'),'e3':('v1','v3')}
V1=['v1','v2','v3']
#G2={'ea':('a','b'),'eb':('b','c'),'ec':('c','a')}

def all_Travelled(flag):
	for f in flag:
		if f == False:
			return f
	return True

def degree(G,vertex):
	count=0
	for g in G.values():
		if vertex in g:
			count+=1
			if(g[0]==g[1]):
				count+=1
	return count

def adjacent_vertex(v,G):
	if flag[V1.index(v)]==True:
		return
	adj=[]
	for g in G.values():
		if v in g:
			flag[V1.index(v)]=True
			if g[0]==v:
				adjacent_vertex(g[1],G1)
			if g[1]==v:
				adjacent_vertex(g[0],G1)
	

def unique_vertex(G,V):
	l=[]
	
	for g in G.values():
		l.append(g[0])
		l.append(g[1])
	s = set(l)
	
	return [False for i in V],list(s)

flag,vertices=unique_vertex(G1,V1)
#traverse(G1,V1)

adjacent_vertex('v2',G1)
if all_Travelled(flag):
	print("graph is connected")
else:
	print("not connected")


