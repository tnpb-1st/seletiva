my_file = open("test.txt", "w")
for i in range(1000):
    my_file.write("1000\n")
    for j in range(1,1000):
        my_file.write(str(j) + " ")
    my_file.write("1000\n")
my_file.write("0")
my_file.close()