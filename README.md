# Cis7-Final-Project


## Vigenère Cipher Program
Author: Talia Craft  
Date Published: Dec 7, 2024

## General Description
This program implements the Vigenère cipher. It allows users to encrypt plaintext into ciphertext or decrypt ciphertext back into plaintext using a given key. The program supports both uppercase and lowercase letters while leaving non-alphabetic characters unchanged. The cyclic repetition of the key ensures that texts of varying lengths can be processed efficiently.

## Programming Approaches

The key is repeated using modulo arithmetic to match the length of the message without manual duplication.
Uppercase and lowercase letters are treated separately, using their respective ASCII ranges to maintain accurate alignment within the alphabet. Non-alphabetic characters remain unchanged. Base is determined by whether the character is uppercase or lowercase to convert letters correctly.

## Encryption and Decryption Formulas

Encryption Formula:
E(i)=(P(i)−base+(K(i)−keyBase))mod26+base
Decryption Formula:
D(i)=(C(i)−base−(K(i)−keyBase)+26)mod26+base

## Basic Instructions

The program will by prompting you to enter a mode: encrypt or decrypt.
It will then ask you to input the message you wish to encrypt or decrypt and to provide the encytion/decryption key
The program will display the encrypted ciphertext or decrypted plaintext.
You can choose to use the program again or exit by following the prompts.
