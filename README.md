<img src="https://raw.githubusercontent.com/MicaelliMedeiros/micaellimedeiros/master/image/computer-illustration.png" min-width="400px" max-width="400px" width="400px" align="right" alt="Computador iuriCode">

<h1 align="left">
 ESTRUTURAS DE DADOS - Lista de Exercícios - Funções e Operações com listas
lineares sequenciais
</h1>
<p align="left"> 
  Nome: Quele da Silva Andrade <strong>BCET -> Eng. da Computação</strong>.<br>
</p>

<p align="left">
  🦄 Linguagem: <strong>C++</strong>
</p>

<p align="left">
  💼 Ferramentas: 
   <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>  <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/>
</p>

<p align="left">
  COMPETÊNCIAS/HABILIDADES: Conceituar as listas sequenciais e compreender e implementar
operações com o uso de funções em C/C++
</p>


## 🔧 Desenvolvimento do trabalho

### 1) Considerando o programa questao_1.ccp aqui no repositório e respodendo as perguntas abaixo:

<p>
a) Identifique as variáveis globais e locais. Quando identificar uma variável local, especifique o
escopo da mesma.
</p>
<p>
b) Identifique, em cada função, o tipo de passagem de parâmetros.
</p>
<p>
c) Mostre, passo a passo, o valor de todas as variáveis, indicando o momento em que as variáveis
não mais ocupam espaço na memória.
</p>
<p>
d) Diga o que é impresso na tela
</p>

### 2)  Considere listas lineares sequenciais não ordenadas de inteiros não nulos. Faça um programa para:

<p>
a) Construir duas listas sem repetição de dados. Para isto, implemente uma função de nome
inserirSemRepetir que receba como parâmetros: o vetor de dados, o elemento a ser inserido, a
quantidade de elementos no vetor e o tamanho máximo definido para o vetor.
Note:
• Deverão ser emitidas mensagens de erro adequadamente.
• Será preciso fazer uma busca sequencial para evitar repetição de dados.
• A função deverá ser chamada repetidamente para criar cada uma das listas
</p>
<p>
b) Imprimir as listas criadas no item a, implementando uma função de nome listar (ou percorrer),
conforme estudado em aula.
</p>
<p>
c) Intercalar as listas criadas, gerando uma terceira lista sequencial. Por exemplo, a 1ª. lista possui
os elementos 10, 34 e 5 e a 2ª. lista possui os elementos 4, 7 e 9. A lista resultante será 10, 4,34,7,5
e 9.
</p>
<p>
d) Gerar uma lista que seja a interseção das listas do item a, como em interseção de conjuntos.
</p>
<p>
e) Imprimir as listas geradas nos itens c e d, usando a função listar (ou percorrer).
</p>
<p>
f) Gerar uma lista que seja a união das listas do item a e depois imprimi-la.
</p>
<p>
f) Remover um elemento da lista gerada no item f através do índice passado. Para isto,
implemente uma função com o seguinte protótipo :
void removerPeloIndice(int [], int, int);
Parâmetros :
- vetor de elementos
- quantidade de elementos no vetor
- índice do valor a ser removido
Após a leitura do índice, verifique sua validade. Caso não seja válido, emita mensagem de
erro na main, caso contrário chame a função para realizar a remoção.
</p>

 
<h4 align="left">
<details>
<summary>Respostas...</summary>

## Questão 1:
   #### a)
 Variável global é int x = 20 e variáveis locais são int numero = 10, outroNumero escopo main, int valor = 100 e numero escopo teste2, int valor = 200 e n escopo teste3, numero escopo teste1. A forma de identificar é que variáveis locais são declaradas fora da função, usada por todo programa e ocupa memória até que o programa finalize. Já as locais, são declaradas dentro da função, podendo ser usada somente dentro da mesma e a memória só é ocupada quando a função estiver sendo executada. 
 
  #### b)
 Função Teste1 e Teste3 o tipo de passagem é por valor e Teste2 por referência.
 
  #### c)
 Na função TESTE 1 -> A variável local numero no escopo: Teste1 tem seu valor zero inicial e a variável global x tem seu valor 20, quando faz o incremento o valor é somado com +1, assim sendo 21. Mas, o “Valor de número (após Teste1)” será 10, pois ler a variável local declarada no main. Após, executar não ocupa mais espaço na memória.
 
Na função TESTE 2 -> A variável local valor e a variável global numero no escopo: Teste 2. A variável valor tem valor de 100 já definido, e a variável numero recebe o valor do endereço de memória e o valor foi definido na função main de 10. Após, executar não ocupa mais espaço na memória. E ocorre mais uma incrementação, logo x++ vai ser igual a 22. 
 
Na função TESTE 3 -> Todas as variáveis do escopo da função Teste3 são locais. A variável número como na função Teste2 foi mudada o seu valor através do endereço de memória, numero passa a ser 110, que é justamente o valor que a variável n carrega, assim, o return n irá nos retornar 310. Já o x -- está decrementando, como antes o valor era x++ igual a 22, agora será 21.

 #### d)
 
Valor de número (após Teste1) = 10
 
X = 21
 
Valor de número (após Teste2) = 110
 
X = 22
 
Valor de outro número (após Teste3) = 310
 
X = 21

 
 ## Questão 2:
 
 A resposta está no códido Estrutura_de_dados1.ccp
 
