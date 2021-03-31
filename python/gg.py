import sys
inputfile = sys.argv[1]
xepower = sys.argv[2]
newfile = open(inputfile)
fileID = 0
i = 0
myfile = open(inputfile, mode='r', encoding='utf-8')
for line in myfile:
    if i % int(xepower) == 0:
        newfile.close()
        fileID += 1
        newfile = open('output' + str(fileID), mode='w', encoding='utf-8')
    newfile.write(line)
    i += 1
myfile.close()