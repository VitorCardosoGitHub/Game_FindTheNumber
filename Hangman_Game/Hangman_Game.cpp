#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime> //random function
#include <cstdlib> //random function
using namespace std;

//Use "mingw32-make forca" to compile the file on Windows.

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute){
    // for (int i = 0; i < palavra_secreta.size(); i++){
    //     if (chute == palavra_secreta[i]){
    //         return true;
    //     }
    // }

    for (char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou (){
    for (char letra : palavra_secreta)
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
    for (char letra : palavra_secreta){
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

vector<string> le_arquivo(){
    
    ifstream arquivo;
    arquivo.open("palavras.txt");
    
    if (arquivo.is_open())
    {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        vector<string> palavras_do_arquivo;

        for(int i=0; i<quantidade_palavras;i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }

        arquivo.close();
        return palavras_do_arquivo;
    }else{
        cout << "Nao foi possivel acessar o banco de palavras" << endl;
        exit(0);
    }
    
    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    vector<string> palavras_do_arquivo;

    for(int i=0; i<quantidade_palavras;i++){
        string palavra_lida;
        arquivo >> palavra_lida;
        palavras_do_arquivo.push_back(palavra_lida);
    }
    arquivo.close();
    return palavras_do_arquivo;
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

int main () {

    system("cls");

    cabecalho();

    le_arquivo();

    sorteia_palavra();

    cout << "\nDecifre a palavra:\n";

    while (nao_acertou() && nao_enforcou()){
        
        imprime_palavra();

        imprime_erros();
        
        chute();

        system("cls");
        
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (nao_acertou()){
        cout << "Voce perdeu! Tente novamente.\n" << endl;
    }else{
        cout << "Parabens, voce descobriu a palavra!\n" << endl;
    }
}