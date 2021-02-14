#This python program generates public and private keys and decrypts text using RSA.
#Author- Kewal Padamwar
#Class- T.Y. B.Tech C.S.E.    Division- B
#Roll No-  PB23

import Cryptodome
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

class rivestShamirAdleman:

	def __init__(self):
		pass

	def generate_keys(self, private_key_path='private.pem', public_key_path='public.pem'):
		self.key = RSA.generate(1024)

		with open(private_key_path, 'wb') as file:
			file.write(self.key.exportKey())
			
		with open(public_key_path, 'wb') as file:
			file.write(self.key.publickey().exportKey())

	def load_private_key(self, private_key_path='private.pem'):

		with open(private_key_path) as file:
			self.private_key = RSA.import_key(file.read())

	def decrypt(self, cipher_text):
		self.cipher_text = cipher_text
		decryptor = PKCS1_OAEP.new(self.private_key)
		self.deciphered_text = decryptor.decrypt(self.cipher_text)

rsa = rivestShamirAdleman()

cont = 'y'
while cont == 'y':
	print('\n\tMenu')
	print('1. Generate Keys')
	print('2. Decryption')
	choice = int(input("Enter the operation you want to perform: "))
	
	if choice == 1:
		#create and store keys in respective files
		print('\nGenerating the Keys')
		private_key_path = input("Enter the path where you'd like to save the private key(optional, default:private.pem): ")
		public_key_path = input("Enter the path where you'd like to save the public key(optional, default:public.pem): ")

		if private_key_path != '':
			if public_key_path != '':
				rsa.generate_keys(private_key_path, public_key_path)
			else:
				rsa.generate_keys(private_key_path)
		else:
			if public_key_path != '':
				rsa.generate_keys(public_key_path=public_key_path)
			else:
				rsa.generate_keys()

	elif choice == 2:
		#load keys and cipher text from respective files
		print('\nWelcome to RSA Decoder!')
		cipher_text_path = input("Enter the path to load the cipher text from(optional, default:cipher_text.txt): ")
		private_key_path = input('Enter the path to load the private key from(optional, default:private.pem): ')

		if cipher_text_path != '':
			with open(cipher_text_path, 'rb') as file:
				cipher_text = file.read()
		else:
			with open('cipher_text.txt', 'rb') as file:
				cipher_text = file.read()

		if private_key_path != '':
			rsa.load_private_key(private_key_path)
		else:
			rsa.load_private_key()
		
		#decryption
		rsa.decrypt(cipher_text)
		print(f'Your decrypted text for {cipher_text}: \n{rsa.deciphered_text}')

		#writing it to a file
		with open('deciphered_text.txt', 'wb') as file:
			file.write(rsa.deciphered_text)

	else:
		print('Invalid option entered! Try again.')

	cont = input('Do you want to continue? (y/n): ')

'''************OUTPUT**************
        Menu
1. Generate Keys
2. Decryption
Enter the operation you want to perform: 1

Generating the Keys
Enter the path where you'd like to save the private key(optional, default:private.pem):
Enter the path where you'd like to save the public key(optional, default:public.pem):
Do you want to continue? (y/n): y

        Menu
1. Generate Keys
2. Decryption
Enter the operation you want to perform: 2

Welcome to RSA Decoder!
Enter the path to load the cipher text from(optional, default:cipher_text.txt):
Enter the path to load the private key from(optional, default:private.pem):
Your decrypted text for b'\x19 AOY\xd5S7?mFb\x1eX\x06\x811\xda\x18\x03\xf2\x1f43\xff\x19|C\xa5\x83a.\xa9\xb4\x97)\xc4.\xbdA\xeb\x00\xe7\xba\xc5\x19\x89z\xeawGN\'5\xfb\xc7\xbd\xb0h"!sd\xce_\xa00S\xd9\x96"\x9f\xf3\xf4\xdf\xfa\x01\xae\xb2\x19.\x9e\xac\x8f\xe1\xaeNy\xa2\xe3\t\xf5a;W\x8e!\x14\xbcgY\xa9\x93vg \x822\\\x9b7\x0c,\xe3\x15Oz\xb0\x84\xa7^T\x8d\x1d\xbcG\x15\x07':
b'Hello World!'
Do you want to continue? (y/n): n
********************************'''