my_file = open("input.txt", "r")
file_s = my_file.readlines()
my_file.close()
new_lines = ""
for line in file_s:
    new_l = [item.strip('\t') for item in line.split('|')[0:2]]
    string = " [problem:" + "-".join(new_l) + ']\n'
    new_lines += string

out_file = open("input.out","w")
out_file.write(new_lines)
out_file.close()
