from sys import argv
import json

script , flag = argv[0], argv[1]

array = []
i = 2


while i < len(argv):
    if (i+3 > len(argv)):
        break
    name , count ,unit , suplier = argv[i+0] , argv[i+1] , argv[i+2] , argv[i+3]        
    array.append((name,count,unit,suplier))
    i+=5
with open("save.json" , "w") as file :
    json.dump(array , file)

print(array)
