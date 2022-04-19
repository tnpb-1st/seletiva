def addnumbers(outputs):
    aux = []
    if(len(outputs) == 0):
        for n in range(10):
            outputs.append(str(n))
    else:
        for prev in outputs:
            for n in range(10):
                aux.append(prev + str(n))
        outputs = aux[:]
    return outputs

def addwords(words, outputs):
    aux = []
    if(len(outputs) == 0):
        for w in words:
            outputs.append(w)
    else:
        for prev in outputs:
            for w in words:
                aux.append(prev + w)
        outputs = aux[:]
    return outputs

N = int(input())
words = []
for n in range(N):
    string = input()
    words.append(string)

while True:
    try:
        outputs = []
        string = input()
        if(string == ""):break
        for char in string:
            if(char == "#"):
                outputs = addnumbers(outputs)
            else:
                outputs = addwords(words, outputs)
        for w in outputs:
            print(w)
    except EOFError:
        break