#include <iostream> //biblioteca padrão de entrada e saída

using namespace std;

#define TAM 10

//Protótipos
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
        
        cout << "Digite um valor que não seja nulo: ";
        cin >> valor;

        if ( valor > 0 ){
            inserirSemRepetir(v [], valor, qtd_v, TAM); //insere os elementos na lista
            //verificando se a lista está cheia
            if( qtd_v == TAM ){
                cout << "Não pode inserir mais elementos na lista, cheia!!";
                break;
            }
        }
        else{
            break;
        }
    }
    
    cout << "\n***** Criando a segunda lista *****\n";
    
    
    while(true){
        
        cout << "Digite um valor que não seja nulo: ";
        cin >> valor;

        if ( valor > 0 ){
            inserirSemRepetir(y[], valor, qtd_y, TAM); //insere os elementos na lista
            //verificando se a lista está cheia
            if( qtd_y == tam ){
                cout << "Não pode inserir mais elementos na lista, cheia!!";
                break;
            }
        }
        else{
            break;
        }
    }
}

//função inserirSemRepetir -> passagem por referência de n, pois os valores, 
//adição e exclusão do vetor pode ser mudado com base exceute as funções
void inserirSemRepetir(int v[], int valor, int &n, int TAM){
    for (int i = 0; i < n; i++){ 
        if (v[i] == valor){ //busca o valor inserido dentro do vetor
            return i;       //retorna se achar
        }
    }
    return -1; //quando não achar o valor retornará -1
    
    if (return < 0){ //menor que zero não tem o valor na lista
        v[n] = valor; //inserindo o valor
        i++;
    }
    else{
        cout << "Número já existente na lista, não poderá inserir";
    }
}


