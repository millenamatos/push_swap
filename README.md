*Este projeto foi criado como parte do currículo da 42 por mmatos-d, pauhenr2*

# Push_swap

## Descrição

O **Push_swap** é um projeto da 42 voltado para algoritmos de ordenação,
complexidade algorítmica e otimização do número de operações.

O objetivo do projeto é ordenar uma lista de números inteiros utilizando duas
pilhas, chamadas **Stack A** e **Stack B**, e um conjunto limitado de
operações.

O programa recebe uma lista de números como argumentos e gera uma sequência
de operações capaz de ordenar os números em ordem crescente, utilizando o
menor número possível de operações dentro da estratégia escolhida.

As operações disponíveis são:

- `sa`, `sb`, `ss` — troca dos elementos no topo das pilhas;
- `pa`, `pb` — transferência de elementos entre as pilhas;
- `ra`, `rb`, `rr` — rotação das pilhas;
- `rra`, `rrb`, `rrr` — rotação reversa das pilhas.

Nesta versão do projeto, foram implementadas três estratégias de ordenação
com diferentes classes de complexidade, além de uma estratégia adaptativa:

- **Simple** — Selection Sort adaptado para duas pilhas (`O(n²)`);
- **Medium** — Chunk Sort utilizando aproximadamente `√n` elementos por chunk
  (`O(n√n)`);
- **Complex** — Radix Sort LSD baseado nos índices dos elementos
  (`O(n log n)`);
- **Adaptive** — seleciona uma das três estratégias anteriores de acordo com
  o nível de desordem inicial da entrada.

O programa também possui um modo de benchmark (`--bench`) que apresenta
informações sobre a desordem inicial, a estratégia utilizada e a quantidade
de operações realizadas.

## Instruções

### Compilação

Para compilar o projeto:

```bash
make
```

Isso gera o executável `push_swap`.

Para remover os arquivos objeto:

```bash
make clean
```

Para remover os arquivos objeto e o executável:

```bash
make fclean
```

Para limpar e recompilar:

```bash
make re
```

### Execução

A forma básica de executar o programa é:

```bash
./push_swap [estratégia] [--bench] <números>
```

Quando nenhuma estratégia é especificada, a estratégia `Adaptive` é utilizada por padrão.

As estratégias podem ser selecionadas explicitamente:

```bash
./push_swap --simple <números>
./push_swap --medium <números>
./push_swap --complex <números>
./push_swap --adaptive <números>
```
### Benchmark

O modo de benchmark pode ser ativado com:

```bash
./push_swap --bench --adaptive <números>
```

Exibe informações sobre a execução do programa, como a desordem inicial, a estratégia utilizada, a complexidade e a quantidade de operações realizadas.

As informações do benchmark são enviadas para `stderr`, enquanto as operações de Push_swap continuam sendo enviadas para `stdout`.

As operações de Push_swap são enviadas para a saída padrão (`stdout`), enquanto as informações do benchmark são enviadas para a saída de erro (`stderr`).

## Calculo de desordem

Antes de executar qualquer operação de Push_swap, o programa calcula a
desordem inicial da Stack A.

A desordem representa o quanto a sequência está distante de estar ordenada.
Para calculá-la, são analisados todos os pares possíveis de elementos da
Stack A.

Sempre que um elemento maior aparece antes de um elemento menor, esse par é
considerado uma inversão.

A fórmula utilizada é:

```text
desordem = número de inversões / número total de pares
```

O resultado é um valor entre `0` e `1`:

- `0.00` — sequência completamente ordenada;
- `1.00` — sequência em ordem completamente inversa;
- valores entre `0` e `1` — diferentes níveis de desordem.

Por exemplo, considerando a sequência:

```text
1 2 3 5 4
```

Existe apenas uma inversão: `5 > 4`.

O número total de pares possíveis é:

```text
5 × 4 / 2 = 10
```

Portanto:

```text
desordem = 1 / 10 = 0.10
```

Essa medida é calculada antes de qualquer operação de Push_swap e é utilizada
pela estratégia Adaptive para escolher o algoritmo de ordenação.

# Algoritmos

## Simple — Selection Sort

A estratégia Simple é uma adaptação do **Selection Sort** para o modelo de
duas pilhas do Push_swap.

Em um Selection Sort tradicional, o algoritmo procura o menor elemento da
sequência e o coloca em sua posição correta. Esse processo é repetido até que
todos os elementos estejam ordenados.

No nosso caso, como só podemos manipular os elementos através das operações
permitidas pelo Push_swap, o processo é adaptado para trabalhar com as duas
pilhas.

O algoritmo funciona da seguinte maneira:

1. Procura o menor elemento existente na Stack A.
2. Utiliza rotações (`ra`) para colocar esse elemento no topo da Stack A.
3. Utiliza `pb` para transferir o menor elemento para a Stack B.
4. Repete o processo até que todos os elementos tenham sido transferidos para
   B.
5. Utiliza `pa` para devolver os elementos para a Stack A.

A função `find_min` percorre a Stack A para encontrar o menor valor existente.
Depois, o elemento é levado ao topo através de rotações antes de ser enviado
para B.

Quando todos os elementos estão em B, eles são devolvidos para A através de
`pa`. Como os menores elementos foram retirados de A em ordem crescente, eles
ficam organizados corretamente ao retornar para A.

### Complexidade

A procura pelo menor elemento percorre a pilha e esse processo é repetido para
cada elemento. Por isso, a estratégia Simple pertence à classe `O(n²)` no
modelo de complexidade adotado pelo projeto.

Essa estratégia é utilizada pelo modo Adaptive quando a desordem inicial é
menor que `0.2`.

## Medium — Chunk Sort

A estratégia Medium utiliza uma abordagem baseada em **chunks** (blocos).

Antes de iniciar a ordenação, cada elemento da Stack A recebe um índice de
acordo com sua posição na ordem crescente. O menor elemento recebe o índice
`0`, o segundo menor recebe `1`, e assim por diante.

Por exemplo:

```text
Valores:  50  10  30  20
Índices:   3   0   2   1
```

Depois que os elementos recebem seus índices, a sequência é dividida em
chunks. O tamanho de cada chunk é calculado aproximadamente como `√n`.

Para cada chunk, o algoritmo:

1. Procura um elemento cujo índice pertença ao intervalo do chunk atual.
2. Encontra a posição desse elemento na Stack A.
3. Decide se deve utilizar `ra` ou `rra` para levar o elemento até o topo,
   escolhendo o sentido de rotação de acordo com sua posição.
4. Utiliza `pb` para transferir o elemento para a Stack B.
5. Continua até que todos os elementos pertencentes ao chunk tenham sido
   transferidos.

Depois que todos os chunks foram processados, os elementos estão na Stack B.
O algoritmo então reconstrói a Stack A em ordem.

Para isso, procura os maiores índices restantes em B, leva cada elemento ao
topo utilizando `rb` ou `rrb` e depois utiliza `pa` para transferi-lo para A.

### Tamanho dos chunks

O tamanho dos chunks é calculado de forma que seja aproximadamente `√n`.

A função utilizada começa com um tamanho de `1` e o incrementa até que:

```text
chunk_size² >= n
```

Assim, para uma entrada de aproximadamente 100 elementos, por exemplo, o
tamanho do chunk será aproximadamente 10.

### Complexidade

A estratégia foi projetada para pertencer à classe `O(n√n)` no modelo de
complexidade baseado nas operações de Push_swap exigido pelo projeto.

Essa estratégia é utilizada pelo modo Adaptive quando a desordem inicial
está entre `0.2` e `0.5`.

## Complex — Radix Sort LSD

A estratégia Complex utiliza o **Radix Sort LSD (Least Significant Digit)**,
adaptado para funcionar com as duas pilhas do Push_swap.

Antes de iniciar o Radix Sort, cada elemento recebe um índice de acordo com
sua posição na ordem crescente. Dessa forma, os elementos passam a ser
representados por valores entre `0` e `n - 1`, independentemente dos valores
inteiros originais.

Por exemplo:

```text
Valores:  50  10  30  20
Índices:   3   0   2   1
```

O algoritmo então trabalha com a representação binária desses índices,
começando pelo bit menos significativo.

Para cada bit:

1. Os elementos da Stack A são analisados um por um.
2. Se o bit analisado for `0`, o elemento é enviado para a Stack B usando
   `pb`.
3. Se o bit analisado for `1`, o elemento permanece na Stack A e a pilha é
   rotacionada usando `ra`.
4. Depois que todos os elementos de A forem analisados, todos os elementos
   presentes em B são devolvidos para A utilizando `pa`.
5. O processo é repetido para o próximo bit.

O algoritmo continua até que todos os bits necessários para representar o
maior índice tenham sido processados.

### Exemplo simplificado

Considere os índices:

```text
0 = 000
1 = 001
2 = 010
3 = 011
```

Na primeira rodada, o algoritmo analisa o bit menos significativo. Depois,
passa para o próximo bit e assim por diante.

Esse processo permite ordenar os índices sem precisar comparar diretamente os
valores dos elementos.

### Complexidade

O maior índice possível é `n - 1`. Portanto, o número de bits necessários para
representar os índices é proporcional a `log(n)`.

Cada rodada processa todos os `n` elementos da Stack A e, ao final, devolve os
elementos da Stack B para A.

Assim, a estratégia possui complexidade `O(n log n)` no modelo de operações
de Push_swap utilizado pelo projeto.

Essa estratégia é utilizada pelo modo Adaptive quando a desordem inicial é
maior ou igual a `0.5`.

## Adaptive

A estratégia Adaptive utiliza a medida de desordem calculada antes da
ordenação para escolher automaticamente entre as três estratégias
implementadas: Simple, Medium e Complex.

A escolha é feita de acordo com os seguintes limites:

| Desordem | Estratégia | Complexidade |
|---|---|---|
| `< 0.2` | Simple | `O(n²)` |
| `0.2 ≤ desordem < 0.5` | Medium | `O(n√n)` |
| `≥ 0.5` | Complex | `O(n log n)` |

Por exemplo:

```text
Desordem = 0.10
→ Simple

Desordem = 0.35
→ Medium

Desordem = 0.80
→ Complex
```

A decisão é tomada antes de qualquer operação de Push_swap. Depois que a
estratégia é escolhida, o algoritmo correspondente é executado normalmente.

A estratégia Adaptive funciona, portanto, como uma camada de decisão sobre os
três algoritmos de ordenação, escolhendo aquele que corresponde ao nível de
desordem da entrada.

Os limites utilizados foram definidos de acordo com os regimes de
complexidade exigidos pelo subject:

- baixa desordem: `O(n²)`;
- média desordem: `O(n√n)`;
- alta desordem: `O(n log n)`.

Essa abordagem permite que o programa utilize estratégias diferentes de
acordo com a configuração inicial da Stack A, em vez de utilizar sempre o
mesmo algoritmo para qualquer entrada.

## Recursos

- **Push_swap Subject — 42**  
  Principal referência utilizada durante o desenvolvimento. O subject define
  as regras do projeto, as operações disponíveis, os requisitos dos
  algoritmos, a métrica de desordem e os objetivos de desempenho.

- **Grokking Algorithms — Aditya Bhargava**  - Livro utilizado como apoio para estudar algoritmos de ordenação e conceitos de complexidade algorítmica.

- **Big O Notation**  - [Big O Notation](https://medium.com/linkapi-solutions/o-que-%C3%A9-big-o-notation-32f171e4a045) - Material utilizado para revisar os conceitos de complexidade de tempo e espaço e compreender melhor as classes `O(n²)`, `O(n√n)` e `O(n log n)`.

### Uso de Inteligência Artificial

A inteligência artificial foi utilizada como ferramenta de apoio durante o
desenvolvimento do projeto.

Ela foi utilizada principalmente para:

- esclarecer partes do subject;
- estudar conceitos de algoritmos e complexidade;
- discutir a organização do programa;
- revisar a implementação da métrica de desordem;
- revisar e entender o funcionamento do benchmark;
- sugerir formas de testar e verificar o programa.
