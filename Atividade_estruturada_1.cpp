#include <iostream> //biblioteca padr�o de entrada e sa�da

using namespace std;

#define TAM 10

//Prot�tipos
void inserirSemRepetir(int, int, int &, int)



int main (void){
    int valor, 
    v[TAM], //primeira lista
    y[TAM], //segunda lista
    qtd_v, //quantidade de valores existentes na lista v
    qtd_y; //quantidade de valores existentes na lista y
    
    
    //inicializando a quantidade de valores existentes na lista
    qtd_v = 0;
    qtd_y = 0;
    
    cout << "\n***** Criando a primeira lista *****\n";
    
    
    while(true){
        
        cout << "Digite um valor que n�o seja nulo: ";
        cin >> valor;

        if ( valor > 0 ){
            inserirSemRepetir(v [], valor, qtd_v, TAM); //insere os elementos na lista
            //verificando se a lista est� cheia
            if( qtd_v == TAM ){
                cout << "N�o pode inserir mais elementos na lista, cheia!!";
                break;
            }
        }
        else{
            break;
        }
    }
    
    cout << "\n***** Criando a segunda lista *****\n";
    
    
    while(true){
        
        cout << "Digite um valor que n�o seja nulo: ";
        cin >> valor;

        if ( valor > 0 ){
            inserirSemRepetir(y[], valor, qtd_y, TAM); //insere os elementos na lista
            //verificando se a lista est� cheia
            if( qtd_y == tam ){
                cout << "N�o pode inserir mais elementos na lista, cheia!!";
                break;
            }
        }
        else{
            break;
        }
    }
}

//fun��o inserirSemRepetir -> passagem por refer�ncia de n, pois os valores, 
//adi��o e exclus�o do vetor pode ser mudado com base exceute as fun��es
void inserirSemRepetir(int v[], int valor, int &n, int TAM){
    for (int i = 0; i < n; i++){ 
        if (v[i] == valor){ //busca o valor inserido dentro do vetor
            return i;       //retorna se achar
        }
    }
    return -1; //quando n�o achar o valor retornar� -1
    
    if (return < 0){ //menor que zero n�o tem o valor na lista
        v[n] = valor; //inserindo o valor
        i++;
    }
    else{
        cout << "N�mero j� existente na lista, n�o poder� inserir";
    }
}


