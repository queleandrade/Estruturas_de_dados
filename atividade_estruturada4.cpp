#include <iostream>
using namespace std;

#define MAX 10

int enfileirar(int v[], int &fim, int &num, int valor);
int desenfileirar(int v[], int &ini, int fim, int &num, int &valor);
int inverte(int v[], int ini, int fim);
void imprimir(int v[], int tam);
int impar(int v[], int tam);
int par(int v[], int tam);

int main(void) {
    // Declara a fila
    int fila[MAX];
    int ini = 0;
    int fim = -1;
    int nfila = 0;

    // Variável para armazenar dado digitado
    int dado, dado2;
    // Variável que indica se acabaram valores da fila
    int vazia;

    // Lê valores e os enfileira, se forem >= 0
    do {
        cout << "Digite um numero inteiro a enfileirar (0 desenfileira um número, -1 termina): ";
        cin >> dado;
        if (dado >0) enfileirar(fila, fim, nfila, dado);
        else if(dado==0) desenfileirar(fila, ini, fim, nfila, dado2);
        } while(dado >= 0);

    // Agora mostra valores da pilha até que eles acabem...
    do {
        vazia = desenfileirar(fila, ini, fim, nfila, dado);
        if (vazia == 0) cout << dado << endl;
    } while (vazia == 0);
    
    cout << "*************invertendo**************";
    inverte(fila, 0, 9);
    imprimir(fila, 10);
    
    impar(fila, 10);
    par(fila, 10);
    
}

// Enfileira um valor
// Entrada:
//  v: vetor com elementos da fila
//  fim: fim da fila
//  num: número de elementos atuais
//  valor: valor a ser enfileirado
// Retorna:
//  1- Se fila cheia
//  0- Caso contrário
int enfileirar(int v[], int &fim, int &num, int valor) {
    // Se a fila está cheia... retorna 1
    if (num==MAX) {
        cout << "ERRO: Fila cheia!" << endl;
        return 1;
    }
    // Se fila não está cheia, vamos enfileirar
    fim = fim + 1;
    if (fim>=MAX) fim = fim - MAX;
    v[fim] = valor;
    num = num + 1;
    // Indica que valor foi enfileirado
    return 0;
}


// Desenfileira um valor
// Entrada:
//  v: vetor com elementos da fila
//  ini: inicio da fila
//  fim: final da fila
//  num: número de elementos atuais
//  valor: Local a colocar valor desenfileirado
// Retorna:
//  valor: valor desenfileirado
//  1- Se fila vazia
//  0- Caso contrário
int desenfileirar(int v[], int &ini, int fim, int &num, int &valor) {
    // Se a fila está vazia... retorna 1
    if (num == 0) {
        cout << "ERRO: Fila vazia!" << endl;
        return 1;
    }
    // Se fila não está vazia, vamos desenfileirar
    valor = v[ini];
    ini = ini + 1;
    if (ini >= MAX) ini = ini - MAX;
    num = num - 1;
    // Indica que valor foi desenfileirado
    return 0;
}


int inverte(int v[], int ini, int fim){
    int aux;
    if(ini < fim){
        aux = v[ini];
        v[ini] = v[fim];
        v[fim] = aux;
        inverte(v, ini + 1, fim - 1);
    }
}

void imprimir(int v[], int tam){
    if(tam == 1)
    	cout << v[tam - 1] << endl;
    else{
        imprimir(v, tam - 1);
        cout << v[tam - 1] << endl;
    }
}

int impar(int v[], int tam) {
    int inicio = 0;  //indice do primeiro elemento da fila
    int ultimo = tam - 1; //indice do ultimo elemento da fila
    int imparcont = 0; //inicializada como zero e é incrementada toda vez que um elemento ímpar é encontrado.
    while (inicio <= ultimo) {
        if (v[inicio] % 2 == 1) { //verificando se o primeiro elemento da fila é ímpar
            imparcont++;        //incrementa
        }
        inicio++;
        if (inicio > ultimo) { //se o laço anterior não for interrompido, o próximo elemento da fila é removido do início da fila e armazenado na variável
            break;
        }
        int fila = v[inicio];
	    //as variaveis inicio e ultimo vão ser sempre atualizadas para indicar uma nova posição
        for (int i = inicio; i > 0; i--) {  
            v[i] = v[i - 1];
        }
        v[0] = fila;
        inicio++;
        ultimo++;
    }
    return imparcont;
}


int par(int v[], int tam) {
    int inicio = 0;  //indice do primeiro elemento da fila
    int ultimo = tam - 1; //indice do ultimo elemento da fila
    int parcont = 0; //inicializada como zero e é incrementada toda vez que um elemento ímpar é encontrado.
    while (inicio <= ultimo) {
        if (v[inicio] % 2 == 0) { //verificando se o primeiro elemento da fila é ímpar
            parcont++;        //incrementa
        }
        inicio++;
        if (inicio > ultimo) { //se o laço anterior não for interrompido, o próximo elemento da fila é removido do início da fila e armazenado na variável
            break;
        }
        int fila = v[inicio];
	    //as variaveis inicio e ultimo vão ser sempre atualizadas para indicar uma nova posição
        for (int i = inicio; i > 0; i--) {  
            v[i] = v[i - 1];
        }
        v[0] = fila;
        inicio++;
        ultimo++;
    }
    return parcont;
}



// int par(int pares[], int TAM, int &num){
// 	int par = 0;
// 	for ( int i=0; i < TAM; i++){
//         if (num % 2 == 0){
//             pares[i] = num;
//             par++;
//         }
//     }
// 	return par;
// }

// int impar(int impares[], int TAM, int &num){
// 	int impar = 0;
// 	for ( int i=0; i < TAM; i++){
//         if (num % 2 != 0){
//             impares[i] = num;
//         	impar++;
//         }
// 	}
// 	return impar;
// }
