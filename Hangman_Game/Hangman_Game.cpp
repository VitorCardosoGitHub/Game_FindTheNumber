#include <iostream>
#include <string>
#include <map>
using namespace std;

//Use "mingw32-make forca" to compile the file on Windows.

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;

bool letra_existe(char chute){
    // for (int i = 0; i < PALAVRA_SECRETA.size(); i++){
    //     if (chute == PALAVRA_SECRETA[i]){
    //         return true;
    //     }
    // }

    for (char letra : PALAVRA_SECRETA){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

int main () {

    cout << "\nDecifre a palavra:\n";

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while (nao_acertou && nao_enforcou){   
        for (char letra : PALAVRA_SECRETA){
            if (chutou[letra]){
                cout << letra << " ";
            }else{
                cout << "_ ";
            }
        }
        
        cout << endl;
        
        char chute;
        cin >> chute;

        chutou [chute] = true;

        if (letra_existe(chute))
        {
            cout << "\nVoce acertou! Seu chute esta na palavra.\n" << endl;
        }
        else{
            cout << "\nVoce errou! Seu chute nao esta na palavra.\n" << endl;
        }
        
    }
    
}