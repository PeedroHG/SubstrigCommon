# 🔥 Maior Substring Comum Recursivo 

### 🎯 Objetivo

Este algoritmo recebe duas strings `s1` (principal) e `s2`, e encontra a **maior substring comum** entre elas. Ele retorna a **posição de início e fim da substring comum dentro da string `s1`**.

Exemplo:
```cpp
s1 = "banana";
s2 = "ananas";

result: 1->5: anana
```
### 🧮 Formula de recursão

```math
LCS(i, j) = 
\begin{cases} 
1 + LCS(i+1, j+1), & \text{se } s1[i] = s2[j] \\
0, & \text{caso contrário}
\end{cases}
```

Considerando o pior caso onde o algoritmo vai percorrer todas posições de ```i``` e de ```j``` nosso código tem custo 

```math
O(m.n)
```

### ⚙️ Funcionamento


```
pair<int, int> encontrarMaiorSubstringComumRec();
```
- Faz a chamada de ```int recursiveLCSMemo()``` inicializando os os parametros e retorna apenas o par de int que represeta as posições de inicio e fim da substring.


```
int recursiveLCSMemo();
```
- Para cada par de posições `i` e `j` ele compara se `s1[i] = s2[j]`.
    - Se verdadeiro: ele continua para `i+1` e `j+1` recursivamente representando o acesso a diagonal da tabela.
        - Quando tiver um retorno a variável len é atualizada e depois verifica se ```len > max_len``` afim de sempre manter max_len com o tamanho da maior substring e guardar a posição inicial da mesma.
    - Se falso: são realizadas mais duas chamadas recursivas: uma alterando a posição da `s1` e outra da `s2` até que caiam na condição de igualdade de caractere ou termine uma das duas strings.


### 📚 Referências

- [**Dynamic Programming Problems**](https://github.com/h3dema/DPP/tree/master)
- [**GeeksforGeeks: Longest Common Substring**](https://www.geeksforgeeks.org/longest-common-substring-dp-29/) 
- [**Vídeo Explicativo (YouTube)**](https://www.youtube.com/watch?v=_vRoDvL2SaA) 
