//This C++ program performs encryption and decryption using
//the RSA algorithm.
#include <bits/stdc++.h>
using namespace std;
//This function checks whether a given integer num is a prime number or not.
//It returns true if num is prime, otherwise false.
bool isPrime(int num)
{
    if (num <= 1)//Prime number is a number that is greater than 1
    {
        return false;
    }
//int sqrtNum = static_cast<int>(sqrt(num));
//This function checks whether a given integer is a prime number by iterating from
//2 to the square root of the number and checking for the capacity of being divided
    int sqrtNum=sqrt(num);
    for (int i = 2; i <= sqrtNum; i++)
    {
//num % i: This calculates the remainder when 'num' is divided by 'i'.
//== 0: This checks if the result of the modulo operation is equal to 0.
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
//Euclidean algorithm
 //greatest common divisor (GCD)
//int calculateGCD(int a, int b): This line defines a function named calculateGCD that takes two
//integer parameters a and b and returns an integer value.
//while (b != 0): This line starts a while loop that continues as long as the value of b is not equal to 0.
//int temp = b;: Here, the current value of b is stored in a temporary variable temp.
//b = a % b;: This line calculates the remainder of the division of a by b using
 //the modulo operator and assigns it to b. This step is crucial in the Euclidean algorithm
 //for finding the greatest common divisor (GCD).
//a = temp;: The original value of b (stored in temp) is assigned to a,
//preparing for the next iteration of the loop.
//return a;: Once the value of b becomes 0, the loop exits, and the function returns the final
 //value of a, which represents the GCD of the original input values a and b.

int calculateGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//It calculates the modular multiplicative inverse of a number 'a'
//under modulo 'm' using a brute force approach
//

int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}
//



int modExp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    for (; exp > 0; exp /= 2)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
    }
    return result;
}
int encrypt(int message, int e, int n)
{
    return modExp(message, e, n);
}
int decrypt(int ciphertext, int d, int n)
{
    return modExp(ciphertext, d, n);
}
int main()
{
    int p, q;
// Key Setup
    cout << "Enter the value of p: ";
    cin >> p;
    cout << "Enter the value of q: ";
    cin >> q;
    if ((!isPrime(p)) || (!isPrime(q)))
    {
        cout << "Enter prime numbers!!!"<<endl;
        cout << "Enter the value of p: ";
        cin >> p;

        cout << "Enter the value of q: ";
        cin >> q;

    }

    string msg;
    cout << "Enter the plain text: ";
    fflush(stdin);
    getline(cin, msg);

    vector<int> message;
    for (char ch : msg)
    {
        message.push_back(static_cast<int>(ch));
    }

    int n, phi_n;
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    // calculate e
    int e, d;
    for (e = 2; e < phi_n; e++)
    {
        if (calculateGCD(e, phi_n) == 1)
        {
            break;
        }
    }

    // calculate d
    d = modInverse(e, phi_n);

    cout << "Public Encryption Key {e, n}: " << "{" << e << "," << n << "}" << endl;
    cout << "Public Decryption Key {d, n}: " << "{" << d << "," << n << "}" << endl;

    // Encryption
    vector<int> ciphertext;
    cout << "\nEncrypted message: "<<endl;
    int CipherText=0;
    for (int ch : message)
    {
        ciphertext.push_back(encrypt(ch, e, n));
        cout<<"'"<<static_cast<char>(ch)<<"': "<<encrypt(ch, e, n)<<endl;
    }
    cout<<"Encrypted Text"<<endl;
    for (int ch : message)
    {
        cout<<static_cast<char>(encrypt(ch, e, n));
    }
// Decryption
    vector<int> decryptedMessage;
    cout << "\n\nDecrypted message: ";
    for (int ch : ciphertext)
    {
        decryptedMessage.push_back(decrypt(ch, d, n));
        cout << static_cast<char>(decrypt(ch, d, n));
    }
    cout<<endl;
    return 0;
}
