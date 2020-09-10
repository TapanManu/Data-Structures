G={'e1':('v1','v2'),'e2':('v1','v1'),'e3':('v1','v2')}

# general graph

def degree(G,vertex):
	count=0
	for g in G.values():
		if vertex in g:
			count+=1
			if(g[0]==g[1]):
				count+=1
	return count
def distinct_vertex(G):
	l=[]
	for g in G.values():
		l.append(g[0])
		l.append(g[1])
	s = set(l)
	for i in s:
		print(i,":",degree(G,i))


		
distinct_vertex(G)
