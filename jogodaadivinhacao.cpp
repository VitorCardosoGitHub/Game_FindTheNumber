#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    cout << "\n|****************************************|" << endl;
    cout << "| Seja bem-vindo ao jogo da adivinhacao! |" << endl;
    cout << "|****************************************|" << endl;

    cout << "\nEscolha seu nivel de dificuldade: " << endl;
    cout << "\nFacil (F)\nMedio (M)\nDificil (D)." << endl;
    cout << "\nEscolha: "<< endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if (dificuldade == 'F')
    {
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M')
    {
        numero_de_tentativas = 10;
    }
    else if (dificuldade == 'D')
    {
        numero_de_tentativas = 5;
    }
    
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas < numero_de_tentativas; tentativas++)
    {
        cout << "\nTentativa: " << tentativas << endl;

        int chute;
        cout << "\nQual o seu chute? ";
        cin >> chute;
        cout << "\nO valor do seu chute e: " << chute << endl;

        double pontos_perdidos = abs(chute-NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "\nParabens, voce acertou!\n";
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "\nVoce errou! O numero secreto e menor.\n";
        }
        else{
            cout << "\nVoce errou! O numero secreto e maior.\n";
        }
    }
    
    cout << "\nFim do jogo!\n";
    if (nao_acertou)
    {
        cout << "\nVoce perdeu! Tente novamente." << endl;
    }
    else{
        cout << "\nVoce ganhou o jogo com " << tentativas << " tentativa(s)." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "\nSua pontuacao final foi de: "<< pontos << " pontos." << endl;
    }

}