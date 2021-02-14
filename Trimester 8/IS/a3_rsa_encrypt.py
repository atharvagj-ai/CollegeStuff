#This python program encrypts text using RSA.
#Author- Kewal Padamwar
#Class- T.Y. B.Tech C.S.E.    Division- B
#Roll No-  PB23

import Crypto
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

class rivestShamirAdleman:

	def __init__(self):
		pass

	def load_public_key(self, public_key_path='public.pem'):

		with open(public_key_path) as file:
			self.public_key = RSA.import_key(file.read())

	def encrypt(self, plain_text):
		self.plain_text = plain_text
		encryptor = PKCS1_OAEP.new(self.public_key)
		self.ciphered_text = encryptor.encrypt(self.plain_text)

rsa = rivestShamirAdleman()

print('\nWelcome to RSA Encoder!')

#load keys and plain text from respective files
plain_text_path = input("Enter the path to load the plain text from(optional, default:plain_text.txt): ")
public_key_path = input('Enter the path to load the public key from(optional, default:public.pem): ')

if plain_text_path != '':
	with open(plain_text_path, 'rb') as file:
		plain_text = file.read()
else:
	with open('plain_text.txt', 'rb') as file:
		plain_text = file.read()

if public_key_path != '':
	rsa.load_public_key(public_key_path)
else:
	rsa.load_public_key()

#encryption
rsa.encrypt(plain_text)
print(f'Your encrypted text for {plain_text}: \n{rsa.ciphered_text}')

#writing it to a file
with open('cipher_text.txt', 'wb') as file:
	file.write(rsa.ciphered_text)

'''************OUTPUT**************
Welcome to RSA Encoder!
Enter the path to load the plain text from(optional, default:plain_text.txt):
Enter the path to load the public key from(optional, default:public.pem):
Your encrypted text for b'Hello World!':
b'\x19 AOY\xd5S7?mFb\x1eX\x06\x811\xda\x18\x03\xf2\x1f43\xff\x19|C\xa5\x83a.\xa9\xb4\x97)\xc4.\xbdA\xeb\x00\xe7\xba\xc5\x19\x89z\xeawGN\'5\xfb\xc7\xbd\xb0h"!sd\xce_\xa00S\xd9\x96"\x9f\xf3\xf4\xdf\xfa\x01\xae\xb2\x19.\x9e\xac\x8f\xe1\xaeNy\xa2\xe3\t\xf5a;W\x8e!\x14\xbcgY\xa9\x93vg \x822\\\x9b7\x0c,\xe3\x15Oz\xb0\x84\xa7^T\x8d\x1d\xbcG\x15\x07'
********************************'''