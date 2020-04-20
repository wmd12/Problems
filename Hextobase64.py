import math
HexInput = input("Enter Hex string:")
binaryconverted = str(bin(int(HexInput, 16)).split('0b')[1])
lengthbinaryconverted = len(binaryconverted)
count = 0
block = ""
blocks =[]
blockcount =0
#0b[strats from here]101010 010100 1001
numblock =  math.ceil(len(binaryconverted)/6)
print(numblock)
for i in range(0,len(binaryconverted)):
    if(count < 6):
        #creates each block
        block = block + binaryconverted[i]
        count =count + 1
    if(count == 6):
        #adds block to blocks
        blocks.append(block)
        count = 0
    elif(count<6 and i == lengthbinaryconverted-1  ):
        #append zeroes at the end (6 - lengthof block)
        block = block + '0'*(6 - len(block))
        blocks.append(block)
        count = 0
        
total =0
final = []
for eachblock in blocks:
        #rotates each block
        rotated_block =  str(eachblock[-6:] + eachblock[:-6])
        for bit in range(0, len(rotated_block)):
           if(rotated_block[bit] == '1'):
               total = total + 2 ^ bit
        final.append(total)
        total =0

print(final)

