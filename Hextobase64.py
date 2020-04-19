import math
HexInput = input("Enter Hex string:")
binaryconverted = str(bin(int(HexInput, 16)))
count = 0
block = ""
blocks =[]
#0b[strats from here]1010100101001001
for i in range(2,len(binaryconverted)):
    if(count < 6):
        block = block + binaryconverted[i]
        count =count + 1
        
    if(count == 6):
        blocks.append(block)
        count = 0
        block = ""


print(blocks)
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



