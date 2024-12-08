#include <iostream>
#include <string>
using namespace std;

// Function to process the key: Converts it to uppercase and removes non-alphabetic characters
string processKey(const string& key)
{
    string processedKey;
    for (char c : key)
    {
        if (c >= 'A' && c <= 'Z')
            processedKey += c;
        else if (c >= 'a' && c <= 'z')
            processedKey += c + 'A' - 'a';
    }
    return processedKey;
}

// Function to encrypt the text
string encrypt(const string& text, const string& key)
{
    string out;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < text.length(); ++i)
    {
        char c = text[i];

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
            continue;

        out += (c + key[j] - 2 * 'A') % 26 + 'A';
        j = (j + 1) % keyLength;
    }

    return out;
}

// Function to decrypt the text
string decrypt(const string& text, const string& key)
{
    string out;
    int keyLength = key.length();

    for (int i = 0, j = 0; i < text.length(); ++i)
    {
        char c = text[i];

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
            continue;

        out += (c - key[j] + 26) % 26 + 'A';
        j = (j + 1) % keyLength;
    }

    return out;
}

int main()
{
    string key, input, choice;

    // Get the encryption key
    cout << "Enter the encryption key: ";
    cin >> key;
    cin.ignore(); // Clear the newline character from the buffer

    // Process the key
    key = processKey(key);

    // Get the user's choice
    cout << "Do you want to (E)ncrypt or (D)ecrypt? ";
    getline(cin, choice);

    if (choice == "E" || choice == "e")
    {
        cout << "Enter the text to encrypt: ";
        getline(cin, input);

        string encrypted = encrypt(input, key);
        cout << "Encrypted text: " << encrypted << endl;
    }
    else if (choice == "D" || choice == "d")
    {
        cout << "Enter the text to decrypt: ";
        getline(cin, input);

        string decrypted = decrypt(input, key);
        cout << "Decrypted text: " << decrypted << endl;
    }
    else
    {
        cout << "Invalid choice. Please run the program again." << endl;
    }

    return 0;
}
