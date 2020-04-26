import math
#globals
lengthbinaryconverted = 0
strlength = 0
binaryconverted = ''
baseset='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/='
Hex = input("Enter Hex string:")
output =''
strlength = len(Hex)
if( Hex != 0 and  strlength > 1 ):
    #0b[strats from here]101010 010100 1001
    binaryconverted = str(bin(int(Hex, 16)).split('0b')[1])
    print(binaryconverted)
    lengthbinaryconverted = len(binaryconverted)

    for i in range(0,strlength,5):
        if(i == 0):
            block =  Hex[i:i+6]
        else:
            block =  Hex[i+1:i+1+6]

        if(block !=''):
            l=str(bin(int(block[0:2], 16)).split('0b')[1])
            if(block[2:4] != ""):
                j=str(bin(int(block[2:4], 16)).split('0b')[1])
            else:
                j=""

            if(block[4:6] != ""):
                k=str(bin(int(block[4:6], 16)).split('0b')[1])
            else:
                k=""
            
            if(len(l)<8 or len(l) ==0 ):
                l =  (8-len(l))*'0'+l
            if(len(j)<8):
                j =  (8-len(j))*'0'+j
            if(len(j)<8 ):
                k =  (8-len(k))*'0'+k
            b1 = l+j+k

        else:
            break
        if(len(b1) == 8):
            b1=b1+'0000'
            s1=b1[0:6]
            s2=b1[6:12]
            s3 = '1000000'
            s4 =s3 
        if(len(b1) == 16):
            b1=b1+'0000'
            s1=b1[0:6]
            s2=b1[6:12]
            s3 =b1[12:18]
            s4 ='1000000'
        if(len(b1) == 24):
            s1=b1[0:6]
            s2=b1[6:12]
            s3 =b1[12:18]
            s4 =b1[18:24]
        output= output+(baseset[int(s1,2)])
        output= output+(baseset[int(s2,2)])
        output= output+(baseset[int(s3,2)])
        output= output+(baseset[int(s4,2)])
    print(output)  

else:
    print("error input data")






        
        
#output








