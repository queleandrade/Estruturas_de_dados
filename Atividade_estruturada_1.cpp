#include <iostream> 

#define TAM 3
using namespace std;

//Prototipos
void inserirSemRepetir(int v[], int valor, int &n, int tamanho);
int buscaSequencial (int v[], int valor, int n);
void listar(int v[], int n);
void intercalar(int v[], int qtd_v, int y[], int qtd_y, int z[], int qtd_z);
bool intersecao (int v[], int y[], int qtd_v, int qtd_y, int &n, int inter[]);
void uniao (int v[], int y[], int uni[], int qtd_v, int qtd_y, int &n);
void removerPeloIndice( int uni[], int &qtd_uni, int indice);

int main (void){
    int valor,  v[TAM],  y[TAM], z[TAM*2], inter[TAM], uni[2*TAM], n, qtd_z, qtd_v,  qtd_y, qtd_uni, indice; //quantidade de valores existentes na lista (qtd_v e qtd_y)
    

    //inicializando a quantidade de valores existentes na lista
    qtd_v = qtd_y = qtd_z = qtd_uni = 0;
    
    cout << "\n*** Criando a primeira lista ***\n";
    
    
    while(true){
        
        cout << "Digite um valor que nao seja nulo: ";
        cin >> valor;

        if ( valor > 0 ){
            inserirSemRepetir(v, valor, qtd_v, TAM); //insere os elementos na lista
            //verificando se a lista est? cheia
            if( qtd_v == TAM ){
                cout << "Nao pode inserir mais elementos na lista, cheia!!";
                break;
            }
        }
        else{
            break;
        }
    }
    
    cout << "\n*** Criando a segunda lista ***\n";
    
    
    while(true){
        
        cout << "Digite um valor que não seja nulo: ";
        cin >> valor;

        if ( valor > 0 ){
            inserirSemRepetir(y, valor, qtd_y, TAM); //insere os elementos na lista
            //verificando se a lista est? cheia
            if( qtd_y == TAM ){
                cout << "Nao pode inserir mais elementos na lista, cheia!!";
                break;
            }
        }
        else{
            break;
        }
    }  
            
    cout << "\n*** Imprimindo as listas 1 e 2 criadas ***\n";   
    
    cout << "\nLista 1:";
    listar(v, qtd_v);
    
    cout << "\nLista 2:";
    listar(y, qtd_y);
    
    cout << "\n\n*** Intercalando a lista 1 e 2, em um nova lista 3 ***\n\n"; 
    intercalar(v, qtd_v, y, qtd_y, z, qtd_z);
    cout << "\nLista 3:";
    listar(z, qtd_z);
    
    cout << "\n\n*** Interseção a lista 1 e 2, em um nova lista 4 ***\n\n"; 
    intersecao(v, y, qtd_v, qtd_y, n, inter);
    cout << "\nLista 4:";
    listar(inter, n);
    
    cout << "\n\n*** União a lista 1 e 2, em um nova lista 5 ***\n\n"; 
    uniao(v, y, uni, qtd_v, qtd_y, qtd_uni);
    if(qtd_uni != 0){ //caso exista união, mostra na tela
    	cout << "\nLista 5: ";
    	listar(uni, qtd_uni);
	}
	else{
		cout << "\n União vazia";
	}
	
	cout << "\n\n*** Removendo pelo indice, gerando uma nova lista 6 ***\n\n"; 
	
	if (qtd_uni != 0 ){
		//criando um loop -> enquanto o usuario tiver digitando indice inexistente o sistema
		//vai pedir novo indice a ser removido
		
		do {
			cout << "\n Digite o indice para remover: ";
			cin >> indice;
			
			if (indice < 0 || indice >= qtd_uni){
				cout << "Não existe o indice inserido para remoção";
			}
		} while (indice < 0 || indice >= qtd_uni);
		
		removerPeloIndice(uni, qtd_uni, indice);
		cout << "\nLista 6:";
		listar(uni, qtd_uni);
	}
	else{
		cout << "Não pode remover, lista vazia";
	}
}

//funcaoo inserirSemRepetir -> passagem por referencia de n, pois os valores, 
//adicao e exclusao do vetor pode ser mudado com base exceute as fun??es
void inserirSemRepetir(int v[], int valor, int &n, int tamanho){
    int pos;

	pos = buscaSequencial(v, valor, n);
	if (pos < 0){ // < 0, porque não existe valor o valor no vetor
		v[n] = valor;  //insere na posição livre, que no nosso caso, na 1ª posição livre
		n++;           // incrementa a quantidade de elementos existentes, se antes com 2, agora fica 3
	}
	else{
		cout << "Elemento já existe na lista";
	}
}

//funcao que busca sequencialmente os valores do vetor
int buscaSequencial (int v[], int valor, int n){
	for (int i = 0; i < n; i++){
		if (v[i] == valor){  //se o valor da lista for igual ao da busca
			return i;        // retorna o índice do valor
		}
	}
	return -1; //caso não ache, retorna -1
}

//imprimindo as listas criadas
void listar(int v[], int n){
	for (int i = 0; i < n; i++){
		cout << " " << v[i];
	}
}

//intercalando as listas e gerando uma nova intercalada para qualquer tamanho de lista
void intercalar(int v[], int qtd_v, int y[], int qtd_y, int z[], int qtd_z){
	int i, j;
	for (i = 0; i < qtd_v && i < qtd_y; i++){
		z[i] = v[i]; //1ª posição do vetor vazia, adiciona o primeiro elemento de v
		z[i + 1] = y[i]; //2ª posição do vetor vazia, adiciona o segundo elemento de y
		qtd_z+=2;  //incrementa em 2 em 2, pois adiciona dois valores a cada loop
	}
	
	if (i == qtd_y){
		for (int j = qtd_z; i < qtd_v; j++, i++){
			z[j] = v[i];
			qtd_z++;
		}
	}
	
	if (i == qtd_v){
		for (j = qtd_z; i < qtd_y; i++, j++){
			z[j] = y[i];
			qtd_z++;
		}
	}	
}

//interseção de duas listas significa que precisamos pegar todos os elementos comuns a mesma lista
//e armazenar em outra
bool intersecao (int v[], int y[], int qtd_v, int qtd_y, int &n, int inter[]){
	bool comuns = false;
	for (int i = 0; i < qtd_v; i++){ //percorre os elementos da lista 1 e 2
		for (int j = 0; j < qtd_y; j++){
			if (v[i] == y[j]){  //verifica se tem numeros em comuns
				inter[n] = v[i]; //armazena na variavel as interseções
				comuns = true;
				n++;
			}
		}
	}
	//return comuns;
}

//união das listas geradas e não repete os números existentes em comum nas listas
void uniao (int v[], int y[], int uni[], int qtd_v, int qtd_y, int &n){
	
	bool distintos = false;
	
	//verificando se a 1ª lista está fazia, se sim, o resultado será a 2ª lista
	if (qtd_v == 0){
		for (int i = 0; i < qtd_y; i++){
			uni[i] = y[i];
		n = qtd_y;
		return;
		}
	}
	//caso não esteja vazio, pega os valores da 1ª lista e coloca na lista uni -> uniao
	for (int i = 0; i < qtd_v; i++){
		uni[i] = v[i];
	n = qtd_v;
	}
	//percorre os elementos da lista 1 e 2, verifica se os valores são distintos
	//se sim, adiciona os valores na nova lista
	for (int i = 0; i < qtd_y; i++){
		for (int j = 0; j < qtd_v; j++){
			if (y[i] != v[j]){ //verificandos se os valores são diferentes
				distintos = true;
			}
			else{
				distintos = false;
				break;
			}
		}
		if (distintos){ //caso sim, adicona na nova
			uni[n] = y[i];
			n++;
		}
	}
}

//remover pelo indice o resultado da união das listas 1 e 2
void removerPeloIndice( int uni[], int &qtd_uni, int indice){
	uni[indice] = uni[qtd_uni - 1];
	qtd_uni --;
}


