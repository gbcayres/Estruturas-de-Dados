# Tipos Abstratos de Dados (TADs)

Um **Tipo Abstrato de Dado (TAD)** é uma abstração de uma estrutura de dados. Ele especifica quais operações podem ser realizadas sobre os dados e quais valores são permitidos, sem definir como essas operações serão implementadas internamente.

A principal ideia dos TADs é **separar a especificação da implementação**, ou seja, você define quais operações podem ser realizadas (como adicionar, remover ou acessar elementos), mas não se preocupa com a forma como essas operações são feitas em termos de código. Isso permite maior flexibilidade e reutilização do código, pois a implementação pode ser modificada sem impactar o resto do programa.

### **Exemplos de operações em um TAD:**

- Criação da estrutura.
- Inclusão de elementos.
- Remoção de elementos.
- Acesso de elementos.

### Especificação e Implementação

- **Especificação (Arquivo de Cabeçalho `.h`):** Contém as assinaturas das funções, definições de tipos, e possivelmente variáveis globais e documentação.
    - Exemplo: exemplo_tad.h
        - Protótipos das funções (Assinaturas).
        - Definição de tipos, como ponteiros.
        - Documentação ( Comentários explicativos ).
- **Implementação (Arquivo `.c`):** Contém a implementação real das funções descritas no arquivo de cabeçalho.
    - Exemplo: exemplo_tad.c
        - Implementação das funções que operam sobre a estrutura de dados.
        - Definição de tipos de dados (Estruturas, listas, e etc.).

### **Exemplo**: TAD Lista de Inteiros
Implementei um TAD chamado intList, uma lista de inteiros com capacidade estática. A especificação e a implementação estão organizadas nos arquivos intList.h e intList.c, respectivamente.

O TAD intList permite operações como:

- ** Criação de uma lista(`create`): Inicializa uma lista com capacidade definida.
- ** Destruição de uma lista(`destroy`): Libera a memória alocada pela lista.
- ** Obtenção do tamanho e capacidade(`size` e `capacity`): Funções que retornam o tamanho atual e a capacidade da lista.
- ** Manipulação de elementos(`get`, `set` e `append`): Funções para acessar, modificar e adicionar elementos na lista.
- ** Remoção de itens da lista(`removeAt`): Função para remover um item em determinado index.
- ** Impressão da lista(`print`): Exibe os elementos contidos na lista.

### Vantagens dos TADs:

- **Encapsulamento e Segurança:** Os dados são protegidos e acessados apenas por meio de funções específicas. Isso evita acesso indevido ou manipulação direta dos dados.
- **Flexibilidade e Reutilização:** A implementação pode ser alterada sem modificar o código que usa o TAD, facilitando a manutenção e a evolução do software.
