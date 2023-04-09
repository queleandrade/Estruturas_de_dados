#include <iostream>

using namespace std;

// Função para fazer a fusão de duas sub-arrays ordenadas em um único array
void merge(int v[], int a, int b, int c) {
    int x, y, z;
    int num_1 = b - a + 1;
    int num_2 = c - b;

    // Criação de arrays temporários A e R
    int A[num_1], R[num_2];

    // Copia os elementos das duas sub-arrays para os arrays temporários A e R
    for (x = 0; x < num_1; x++)
        A[x] = v[a + x];
    for (y = 0; y < num_2; y++)
        R[y] = v[b + 1 + y];

    // Inicialização dos índices x, y e z para fazer a fusão
    x = 0; // Índice para a sub-array A
    y = 0; // Índice para a sub-array R
    z = a; // Índice para o array original v

    // Faz a fusão das duas sub-arrays em um único array em ordem decrescente
    while (x < num_1 && y < num_2) {
        if (A[x] >= R[y]) { // Compara o elemento da sub-array A com o elemento da sub-array R
            v[z] = A[x]; // O elemento da sub-array A é maior ou igual ao elemento da sub-array R
            x++; // Incrementa o índice da sub-array A
        }
        else {
            v[z] = R[y]; // O elemento da sub-array R é maior do que o elemento da sub-array A
            y++; // Incrementa o índice da sub-array R
        }
        z++; // Incrementa o índice do array original arr
    }

    // Copia os elementos restantes da sub-array A, se houver
    while (x < num_1) {
        v[z] = A[x];
        x++;
        z++;
    }

    // Copia os elementos restantes da sub-array R, se houver
    while (y < num_2) {
        v[z] = R[y];
        y++;
        z++;
    }
}

// Função para dividir o array em sub-arrays menores e chamar a função merge para fazer a fusão
void merge_sort(int v[], int a, int c, int n) {
    if (a < c) {
        int b = a + (c - a) / 2;

        // Chama a função merge_sort para a sub-array esquerda
        merge_sort(v, a, b, n);

        // Chama a função merge_sort para a sub-array direita
        merge_sort(v, b + 1, c, n);

        // Faz a fusão das sub-arrays esquerda e direita
        merge(v, a, b, c);
    }
}

int main() {
    int indentidicador[] = { 21, 18, 32, 45, 27, 19, 38, 23 }; 
    int n = 8;

    // Chama a função merge_sort para ordenar o array de idades em ordem decrescente
    merge_sort(indentificador, 0, n - 1, n);

    // Imprime o array ordenado em ordem decrescente

    for (int i = 0; i < n; i++) {
        cout << indentidicador[i] << " ";
    }

    return 0;
}
