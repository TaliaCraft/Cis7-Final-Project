/*
Talia Craft
CIS 7
Final Project Case 3: Vigenere Cipher Decryption
8 Dec, 2024
*/


#include <iostream>
#include <string>
using namespace std;

//Encrypt Function
string encrypt(string plain, string key) {
    string cipher = "";

    for (int i = 0; i < plain.length(); i++) {
        char ch = plain[i];
        char keyCh = key[i % key.length()]; //Keeps key repeating if plaintext is larger than key

        //alphabetic characters only
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char base = (ch >= 'A' && ch <= 'Z') ? 'A' : 'a'; //Determining if character is upper or lower
            char keyBase = (keyCh >= 'A' && keyCh <= 'Z') ? 'A' : 'a';
            cipher += (ch - base + (keyCh - keyBase)) % 26 + base; //E=((p-base)+k)mod26 + base
        } else {
            cipher += ch; //non-alphabetic characters(symbols and spaces) are kept unchanged
        }
    }

    return cipher;
}

//Decrypt Function
string decrypt(string cipher, string key) {
    string plain = "";

    for (int i = 0; i < cipher.length(); i++) {
        char ch = cipher[i];
        char keyCh = key[i % key.length()];

        //alphabetic characters only
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char base = (ch >= 'A' && ch <= 'Z') ? 'A' : 'a';
            char keyBase = (keyCh >= 'A' && keyCh <= 'Z') ? 'A' : 'a';
            plain += (ch - base - (keyCh - keyBase) + 26) % 26 + base; //Add 26 to avoid negatives
        } else {
            plain += ch; //Keep non-alphabetic characters unchanged
        }
    }

    return plain;
}


int main() {
    string message, key, mode;
    char again;
    do{
    //Get user input for mode (encrypt/decrypt), message, and key
    cout << "Enter mode (encrypt or decrypt): ";
    cin >> mode;
    cin.ignore();
    cout << "Enter the message: ";
    getline(cin, message);
    cout << "Enter the key: ";
    cin >> key;

    //Check the mode and call appropriate function
    if (mode == "encrypt"){
        cout << "cipher: " << encrypt(message, key) << endl;
    } 
        else if (mode == "decrypt"){
        cout << "plain: " << decrypt(message, key) << endl;
    } 
        else {
        cout << "Invalid mode. Please enter 'encrypt' or 'decrypt'." << endl;
    }
    
    cout<<"Would you like to use the program again?(y/n): ";
    cin>>again;
    }while (again=='y');

    return 0;
}
