

import hashlib
import base64
import binascii
import hmac
def byte_xor(ba1, ba2):
    return bytes([_a ^ _b for _a, _b in zip(ba1, ba2)])

def HMAC_SHA1(key,message,blockSize=64,outputSize =20):

        trans_5C = bytes((x ^ 0x5C) for x in range(256))
        trans_36 = bytes((x ^ 0x36) for x in range(256))
        key = bytes(key, "utf-8")
        message =  bytes(message, "utf-8")

        AlgoSHA1 = hashlib.sha1() 
        AlgoSHA2 = hashlib.sha1() 
        algoSHA3 = hashlib.sha1() 
        if(len(key) > blockSize):
            key = AlgoSHA1.update(key)
        if(len(key) < blockSize ):
            key = key + b'\x00' * (blockSize - len(key))

        o_key_pad= key.translate(trans_5C)
        i_key_pad=key.translate(trans_36)
        
        AlgoSHA2.update(o_key_pad + AlgoSHA1.digest())
        AlgoSHA1.update(i_key_pad + message)
        AlgoSHA3.update( AlgoSHA1.digest() + AlgoSHA2.digest())
      
        return AlgoSHA3.hexdigest()

x = HMAC_SHA1("key", "The quick brown fox jumps over the lazy dog")
print(x)

