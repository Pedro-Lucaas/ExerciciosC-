# ExerciciosC++

> Estas foram resoluções minhas para duas questõs da Olimpíada brasileira de programação, cujos enuciados se encontram abaixo. Resoluções estas feitas para a disciplina de Estrutura de Dados 2.
> Para as duas havia limite de memória:

> 1Gb para as 2.

> e limite de tempo de execução :

> Mandraque -> 2 segundos.
Hyperman -> 0.1 segundos.


  
  
  ## Dr Mandraque
  > Dr Mandraque gosta de juntar código genético de duas espécies e formar novos seres.
    Considerando a Classe A e Classe B ele sempre escolhe um código de A e junta com B. EX: Classe A
    contém bhyj e jjus. Classe B contém ajsn e ika . Os espécimes possíveis de serem criados são
    bhyjajsn, bhyjika, jjusajsn, jjusika
    Uma espécie é considerada “prime”, se caso seu código for removido, todas as junções
    genéticas se perdem. Como é o caso do exemplo acima. Todas as quatro sequências são “prime”.
    Mas considere então xx , xxy da Classe A, e z,yz, xx da classe B. Apenas o xx da classe B é
    prime pois sem ele é impossível criar xxxx e xxyxx. O xx da classe A não é prime pois o espécime
    xxyz (xx+yz) pode ser também construído com xxy + z. Pelo mesmo motivo, xxy, yz e z não são prime.
    Fornecido os códigos genéticos das espécies das duas classes, seu objetivo é dizer quantos
    espécimes primes existem em cada classe.
    
#### Entrada
    
    Dois inteiros, A e B. simbolizando a quantidade de espécimes em cada classe (1 ≤ A ≤ (10^5)) , (1 ≤ B ≤
    105)
    
    A segunda linha possui o código das espécies de A e a terceira de B, formados por letras minúsculas.
     Não existe repetição em nomes de uma mesma classe.
    O tamanho máximo de caracteres da entrada é 106 (somando-se todas as espécimes).
#### Saída
    A saída contém a quantidade de primes de A e B
Exemplo de entrada 1 :
~~~
 2 2 | 2 2
 Bhyj jjus
 ajsn ika
~~~

Exemplo saída 1:
~~~
2 2
~~~
Exemplo de entrada 2:
~~~
2 3
xx xxy
z yz xx
~~~
Exemplo de saída 2 
~~~
0 
~~~
## HYPERMAN
>Hyperman é um jogo no qual você derrota chefes, absorve seus poderes, permitindo que você
derrote outro chefe facilmente, pois um ponto fraco de um chefe é um poder de outro. Para
derrotar chefes sem o uso de poderes você precisa de um golpe especial (S), limitado durante o jogo.
O último chefe, não lhe fornece nenhum poder pois ele é o último da cadeia, o número dele é 1. O
objetivo do jogo é derrotar a maior quantidade de chefes possíveis usando seus golpes especiais e
poderes adquiridos.

#### Entrada:
A primeira linha possui N e S, onde N é o número de chefes e S é a quantidade de golpes. (3 ≤ N ≤
105
), (1 ≤ S < N).
A próxima linha contém N-1 inteiros, onde cada posição simboliza um chefe de número (posição +1)
e seu valor é o chefe no qual seu poder é o ponto fraco. É garantido que a partir de um determinado
chefe é possível chegar no último.
#### Saída:
Um único valor contendo a quantidade máxima de chefes possíveis de serem derrotados.

##### Exemplos
Entrada 1
~~~
8 2
1 1 2 3 4 4 6 
~~~
Saída 1
~~~
7
~~~
Entrada 2
~~~
10 3
1 1 2 2 3 3 4 4 5
~~~
Saída 2
~~~
8
~~~


    
    
