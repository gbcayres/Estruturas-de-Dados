# Árvores
Uma árvore é uma estrutura de dados hierárquica que consiste em nós conectados por arestas. É um modelo abstrato que imita a estrutura hierárquica de árvores naturais. Uma árvore tem um nó raiz, e cada nó tem zero ou mais nós filhos, formando uma estrutura que lembra uma árvore invertida.

---

## Importância das Árvores em Estruturas de Dados

Árvores desempenham um papel fundamental em estruturas de dados devido à sua versatilidade e eficiência. Razões críticas para sua importância incluem:

- **Pesquisa e recuperação eficientes**: As árvores fornecem algoritmos de pesquisa eficientes, tornando-as adequadas para aplicações como bancos de dados e mecanismos de busca.
- **Organização hierárquica**: A natureza hierárquica das árvores permite a representação de relacionamentos de maneira estruturada, facilitando a organização e o gerenciamento de dados.
- **Classificação e ordenação**: Certos tipos de árvores, como árvores de busca binária, permitem classificação e ordenação rápidas de dados, tornando-as essenciais em vários algoritmos.
- **Armazenamento e recuperação otimizados**: Árvores são usadas em sistemas de arquivos para organizar e armazenar dados de uma forma que permita recuperação e atualizações rápidas.

---

## Terminologia Geral

- Raiz: O nó mais alto de uma árvore, a partir do qual todas as outras conexões se ramificam.
- **Nó:** Cada elemento individual da árvore, que contém dados e referências aos seus nós filhos.
- **Pai:** Um nó de árvore com um ou mais nós filhos.
- **Filho**: Nós conectados diretamente a outro nó quando se afastam da raiz.
- **Nó interno**: Nó que possui ao menos 1 filho.
- **Folha / Nó externo:** Um nó que não possui filhos.
- **Subárvore**: Uma árvore formada por um nó e seus descendentes.
- **Aresta:** A conexão entre dois nós.
- **Altura:** O comprimento do caminho mais longo de um nó até uma folha.
- **Grau de um nó:** O número de filhos de um nó.
- **Nível de um nó:** A distância do nó até a raiz. A raiz tem nível 0.
- **Profundidade de uma árvore:** A altura da raiz, ou seja, o comprimento do caminho mais longo da raiz até uma folha.

Entender esses termos estabelece a base para explorar os diversos tipos de árvores e suas aplicações em diversas tarefas computacionais.

---

## Tipos de Árvore:

Existem muitos tipos de árvores em estruturas de dados, cada uma projetada para atender a diferentes requisitos de desempenho e organização de dados. Algumas são otimizadas para busca, outras para balanceamento ou operações rápidas de inserção e remoção. Abaixo, estão alguns dos tipos mais comuns e amplamente utilizados:

- **Árvore Binária:**

- **Árvore Binaria de Busca:**

- **Árvore AVL**

- **Heap**

---

## Travessias / Transversais

Travessia ou transversal é o processo de visitar sistematicamente todos os nós em uma árvore. Existem diferentes técnicas de travessia que oferecem formas distintas de acessar e processar os nós. As duas principais estratégias são a Busca em Largura (Breadth-First Search - BFS) e a Busca em Profundidade (Depth-First Search - DFS).

- **Busca em Largura (BFS):** Explora todos os nós vizinhos de um vértice antes de passar para os vértices do próximo nível. Normalmente implementados usando recursão.
- **Busca em Profundidade (DFS):** Explora o mais profundo possível em uma ramificação antes de retroceder. Normalmente implementados usando filas.

---

## Algumas aplicações de árvores são:

- **Árvores de Busca Binária (BST)**: Utilizadas para verificar rapidamente se um elemento está presente em um conjunto. Devido à sua estrutura hierárquica, operações como busca, inserção e remoção podem ser realizadas de forma eficiente, especialmente quando a árvore está balanceada.
- **Heap**: Uma estrutura de árvore binária usada no algoritmo de ordenação Heap Sort e em filas de prioridade. Seu uso é eficiente para encontrar o maior ou menor elemento rapidamente.
- **Trie**: Uma variação de árvore usada em roteadores modernos para armazenar informações de roteamento. Também é aplicada em sistemas de busca, como mecanismos de autocompletar, por armazenar strings de forma eficiente.
- **B-Trees e T-Trees**: Estruturas balanceadas amplamente utilizadas em sistemas de gerenciamento de banco de dados para armazenar grandes quantidades de dados. Elas otimizam operações de leitura e escrita, sendo especialmente eficazes para dados armazenados em disco.
- **Árvores Sintáticas**: Usadas em compiladores para representar e validar a sintaxe de programas, facilitando a análise semântica e a geração de código durante a compilação.