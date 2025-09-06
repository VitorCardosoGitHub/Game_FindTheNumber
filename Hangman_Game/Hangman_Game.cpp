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

bool nao_acertou (){
    for (char letra : PALAVRA_SECRETA)
    {
        if (!chutou[letra]){
            return true;
        }
    }
    
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void cabecalho(){
    cout << "\n|*****************************************|" << endl;
    cout << "|     Seja bem-vindo ao Hangman Game!     |" << endl;
    cout << "|*****************************************|" << endl;
}

void imprime_erros(){
    cout << "\n\nChutes errados: ";
    for (char letra : chutes_errados){
        cout << letra << ", ";
    }   
}

void imprime_palavra(){
    for (char letra : PALAVRA_SECRETA){
        if (chutou[letra]){
            cout << letra << " ";
        }else{
             cout << "_ ";
        }
    }
}

void chute(){
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
}

int main () {

    system("cls");

    cabecalho();

    cout << "\nDecifre a palavra:\n";

    while (nao_acertou() && nao_enforcou()){
        
        imprime_palavra();

        imprime_erros();
        
        chute();

        system("cls");
        
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;

    if (nao_acertou()){
        cout << "Voce perdeu! Tente novamente.\n" << endl;
    }else{
        cout << "Parabens, voce descobriu a palavra!\n" << endl;
    }
}