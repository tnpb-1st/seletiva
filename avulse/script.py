import random

arq = open("mod.txt", "w")
opts = ["X", "#"]
outs = {}
for n in range (2):
    string = ""
    aux = []
    for w in opts:
        for k in opts:
            string = w + k
            aux.append(string)
    opts = aux[:]

outs = opts[:]
for s in outs:
    arq.write(s + "\n")
arq.close()