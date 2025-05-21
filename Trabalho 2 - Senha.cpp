#include <iostream>
#include <cstdlib>//biblioteca para usar o system
#include <time.h>//bilbioteca para usar o srand e rand
using namespace std;

int main()
{
    int escolha = 0, dificuldade = 2;//variavel para armazenar a escolha do jogador e a dificuldade no médio por padrão
    int qtd_digitos = 0, tentativas = 0;//armazenar a quantidade de digitos e tentativas
    while (escolha != 4) {
        system("cls");

        cout <<"=============================" << endl;
        cout <<"     MENU PRINCIPAL         " << endl;
        cout <<"=============================" << endl;
        cout <<"1. Jogar" << endl;
        cout <<"2. Dificuldade" << endl;
        cout <<"3. Sobre" << endl;
        cout <<"4. Fim" << endl;
        cout <<"=============================" << endl;
        cout <<"Sua escolha: ";
        cin >> escolha;

        cout << endl;

        if (escolha == 1) {

            if (dificuldade == 0) {
                cout << "Selecione a dificuldade antes de jogar." << endl;  
                system("pause");
            } else {
                cout << "Iniciando o jogo..." << endl;
   
                if (dificuldade == 1) {//Define quantidade de dígitos e tentativas conforme a dificuldade
                    qtd_digitos = 3;
                    tentativas = 8;
                }
                else if (dificuldade == 2) {
                    qtd_digitos = 4;
                    tentativas = 10;
                } else if (dificuldade == 3) {
                    qtd_digitos = 5;
                    tentativas = 12;
                }

                // Gera a senha aleatória sem dígitos repetidos
                srand(time(0));
                int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;
                d1 = 1 + rand() % 6;
                do { d2 = 1 + rand() % 6; } while (d2 == d1);
                if (qtd_digitos >= 3) {
                    do { d3 = 1 + rand() % 6; } while (d3 == d1 || d3 == d2);
                }
                if (qtd_digitos >= 4) {
                    do { d4 = 1 + rand() % 6; } while (d4 == d1 || d4 == d2 || d4 == d3);
                }
                if (qtd_digitos == 5) {
                    do { d5 = 1 + rand() % 6; } while (d5 == d1 || d5 == d2 || d5 == d3 || d5 == d4);
                }

                bool venceu = false;
                // Loop principal das tentativas do jogador
                for (int t = 1; t <= tentativas; ) { 
                    int u1 = 0, u2 = 0, u3 = 0, u4 = 0, u5 = 0;
                    bool tentativa_valida = true;

                    cout << "\nTentativa " << t << " de " << tentativas << endl;
                    cout << "Digite " << qtd_digitos << " numeros de 1 a 6 (sem repetir e com espaço entre eles): ";

                    if (qtd_digitos == 3) cin >> u1 >> u2 >> u3;
                    else if (qtd_digitos == 4) cin >> u1 >> u2 >> u3 >> u4;
                    else cin >> u1 >> u2 >> u3 >> u4 >> u5;

                    // Validação dos números e repetições
                    if (qtd_digitos == 3) {
                        if (u1 < 1 || u1 > 6 || u2 < 1 || u2 > 6 || u3 < 1 || u3 > 6 ||
                            u1 == u2 || u1 == u3 || u2 == u3) {
                            tentativa_valida = false;
                        }
                    } else if (qtd_digitos == 4) {
                        if (u1 < 1 || u1 > 6 || u2 < 1 || u2 > 6 || u3 < 1 || u3 > 6 || u4 < 1 || u4 > 6 ||
                            u1 == u2 || u1 == u3 || u1 == u4 ||
                            u2 == u3 || u2 == u4 ||
                            u3 == u4) {
                            tentativa_valida = false;
                        }
                    } else if (qtd_digitos == 5) {
                        if (u1 < 1 || u1 > 6 || u2 < 1 || u2 > 6 || u3 < 1 || u3 > 6 || u4 < 1 || u4 > 6 || u5 < 1 || u5 > 6 ||
                            u1 == u2 || u1 == u3 || u1 == u4 || u1 == u5 ||
                            u2 == u3 || u2 == u4 || u2 == u5 ||
                            u3 == u4 || u3 == u5 ||
                            u4 == u5) {
                            tentativa_valida = false;
                        }
                    }

                    if (!tentativa_valida) {
                        cout << "Palpite invalido! Digite numeros de 1 a 6, sem repetir.\n";
                        continue; // não desconta tentativa, volta para o mesmo t
                    }

                    //adiciona 1 na tentativa
                    t++;

                    //Conta quantos números estão na posição correta
                    int corretos_pos = 0;
                    if (u1 == d1) corretos_pos++;
                    if (u2 == d2) corretos_pos++;
                    if (u3 == d3) corretos_pos++;
                    if (qtd_digitos >= 4 && u4 == d4) corretos_pos++;
                    if (qtd_digitos == 5 && u5 == d5) corretos_pos++;

                    //Conta quantos números estão corretos mas em posição errada
                    int corretos_fora = 0;
                    if (u1 != d1) {
                        if (u1 == d2) corretos_fora++;
                        else if (qtd_digitos >= 3 && u1 == d3) corretos_fora++;
                        else if (qtd_digitos >= 4 && u1 == d4) corretos_fora++;
                        else if (qtd_digitos == 5 && u1 == d5) corretos_fora++;
                    }
                    if (u2 != d2) {
                        if (u2 == d1) corretos_fora++;
                        else if (qtd_digitos >= 3 && u2 == d3) corretos_fora++;
                        else if (qtd_digitos >= 4 && u2 == d4) corretos_fora++;
                        else if (qtd_digitos == 5 && u2 == d5) corretos_fora++;
                    }
                    if (u3 != d3) {
                        if (u3 == d1) corretos_fora++;
                        else if (u3 == d2) corretos_fora++;
                        else if (qtd_digitos >= 4 && u3 == d4) corretos_fora++;
                        else if (qtd_digitos == 5 && u3 == d5) corretos_fora++;
                    }
                    if (qtd_digitos >= 4 && u4 != d4) {
                        if (u4 == d1) corretos_fora++;
                        else if (u4 == d2) corretos_fora++;
                        else if (u4 == d3) corretos_fora++;
                        else if (qtd_digitos == 5 && u4 == d5) corretos_fora++;
                    }
                    if (qtd_digitos == 5 && u5 != d5) {
                        if (u5 == d1) corretos_fora++;
                        else if (u5 == d2) corretos_fora++;
                        else if (u5 == d3) corretos_fora++;
                        else if (u5 == d4) corretos_fora++;
                    }

                    // Mostra ao jogador o resultado da tentativa
                    cout << "Corretos na posição correta: " << corretos_pos << endl;
                    cout << "Corretos em posição errada: " << corretos_fora << endl;
                    cout << "Tentativas restantes: " << (tentativas - t + 1) << endl;

                    // Verifica se o jogador acertou todos os dígitos
                    if (corretos_pos == qtd_digitos) {
                        cout << "\nParabéns! Você venceu!\n";
                        venceu = true;
                        break; // Sai do loop de tentativas
                    }
                }
                // Se não venceu, mostra a senha correta
                if (!venceu) {
                    cout << "\nSuas tentativas acabaram! Você perdeu.\n";
                    cout << "A senha era: " << d1 << " " << d2 << " " << d3;
                    if (qtd_digitos >= 4) cout << " " << d4;
                    if (qtd_digitos == 5) cout << " " << d5;
                    cout << endl;
                }
                system("pause");
            }
        }
        else if (escolha == 2) {
            dificuldade = 0;
            while (dificuldade < 1 || dificuldade > 3) {
                cout <<">> Selecionar dificuldade..."<<endl;
                //explica cada uma das dificuldades
                cout <<"1. Facil: 3 digitos e 8 tentativas"<<endl;
                cout <<"2. Medio: 4 digitos e 10 tentativas"<<endl;
                cout <<"3. Dificil: 5 digitos e 12 tentativas"<<endl;
                cout <<"Escolha: ";
                cin >> dificuldade;
                if (dificuldade < 1 || dificuldade > 3) {//se esolher uma dificuldade invalida
                    cout <<"Dificuldade invalida. Tente novamente."<< endl;
                    dificuldade = 0;
                    system("pause");
                }
            }
            cout <<"dificuldade selecionada: "<< dificuldade<< endl;//mostra a dificuldade selecionada
            system ("pause");
        }
        else if (escolha == 3) {//mostra quem criou o codigo a data e o professor
            cout<<"Criado por: Joao da Rosa Mac-Ginity"<<endl;
            cout<<"13/05/2025"<<endl;
            cout<<"Professor: Thiago Felski Pereira"<<endl;
            cout<<"disciplina: Algoritmos e Programacao"<<endl;
            system("pause");
        }
        else if (escolha == 4) {//sai do programa
            cout<<"Saindo do programa."<<endl;
        }
        else {//se escolher uma opção invalida
            cout<<"Opcao invalida. Tente novamente."<<endl;
        }
    }

    return 0;
}