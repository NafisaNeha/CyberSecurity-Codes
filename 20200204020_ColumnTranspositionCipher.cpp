#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm> //These lines are including necessary
//header files for input/output operations

using namespace std;

int main() {
    string msg = "meet me after the party";
    string key = "HACK";
//wo strings msg and key are declared and initialized.
//msg contains the message to be encrypted, and key contains the keyword used for encryption.
    set<pair<char, int>> keySet;

    keySet.insert(make_pair('H', 3)); //ascen
    keySet.insert(make_pair('A', 1));
    keySet.insert(make_pair('C', 2));
    keySet.insert(make_pair('K', 4));
//A set of pairs (keySet) is declared, where each pair consists of a character and an integer.
//These pairs represent the permutation order of characters in the key string.
// The order is determined by the integer value associated with each character.
// For example, 'H' corresponds to 3, 'A' to 1, 'C' to 2, and 'K' to 4.
    int col = key.length(); //number of row
    int row = (msg.length() + col - 1) / col;//This line calculates the number of rows
    vector<vector<char>> matrix(row, vector<char>(col, 'x')); //This line declares a
    //2D vector named matrix with dimensions row × col.
    // Each element of the matrix is initialized to the character 'x'.
    for (int i = 0, index = 0; i < msg.length(); ++i, ++index) {
        matrix[index / col][index % col] = msg[i];
    } //placing each character in the appropriate position in the matrix.

    string cipher = "";//This line declares an empty string named cipher,
    // which will store the encrypted message.

    for (char keyChar : key) {
        int permutationOrder = 0;
        for (const auto& pair : keySet) {
            if (pair.first == keyChar) {
                permutationOrder = pair.second;
                break;
            }
        } //it retrieves the permutation order for the current
        //character in the key from the keySet.

        for (int k = 0; k < row; ++k) {
            char matrixChar = matrix[k][(permutationOrder - 1) % col];
            if ((matrixChar >= 'A' && matrixChar <= 'Z') || (matrixChar >= 'a' && matrixChar <= 'z') || matrixChar == 'x')
                cipher += matrixChar;
        }
    }//For each character in the key string, this loop retrieves the
    //corresponding character from the matrix using the permutation order.
    //If the character is a letter ('A'-'Z' or 'a'-'z')
    //or padding ('x'), it is appended to the cipher string.

    cout << "Cipher text: " << cipher << endl;
//the encrypted message (cipher) is printed to the console.
    return 0;
}

