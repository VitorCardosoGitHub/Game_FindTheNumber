#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//Use "mingw32-make forca" to compile the file on Windows.

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

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

    system("cls");

    cout << "\n|*****************************************|" << endl;
    cout << "|     Seja bem-vindo ao Hangman Game!     |" << endl;
    cout << "|*****************************************|" << endl;

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

        cout << "\n\nChutes errados: ";
        for (char letra : chutes_errados){
            cout << letra << ", ";
        }
        
        cout << endl;
        
        cout << "\nDigite seu chute: ";

        char chute;
        cin >> chute;

        chutou [chute] = true;

        if (letra_existe(chute))
        {
            cout << "\nVoce acertou! Seu chute esta na palavra.\n" << endl;
        }
        else{
            cout << "\nVoce errou! Seu chute nao esta na palavra.\n" << endl;
            chutes_errados.push_back(chute);
        }

        system("cls");
        
    }
    
}