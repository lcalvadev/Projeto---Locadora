# Projeto Locadora

Este projeto é uma aplicação simples em linguagem C para controlar uma locadora de veículos. O objetivo é permitir o cadastro de veículos, a listagem dos itens existentes, a marcação de veículos alugados e a devolução desses veículos após o uso.

## Sobre o sistema

O programa funciona em um menu interativo que oferece as seguintes opções:

1. Cadastrar veículo
2. Listar veículos cadastrados
3. Alugar veículo
4. Devolver veículo
5. Sair do sistema

A lógica principal está em um laço `do...while`, que continua executando até que o usuário escolha a opção 5.

## Estrutura do código

O arquivo principal do projeto é o `locadora.c` e contém as seguintes partes:

- Definição do limite máximo de veículos com `MAX_VEICULOS`.
- Declaração de arrays para guardar:
  - `modelo` dos veículos
  - `placa` dos veículos
  - `alugado` para indicar se o veículo está disponível ou alugado
- Variáveis de controle:
  - `opcao` para escolher as ações do menu
  - `quantidade` para contar quantos veículos já foram cadastrados

## Como o programa funciona

### 1. Cadastro de veículos

Quando o usuário escolhe a opção 1, o programa verifica se ainda há espaço para cadastrar novos veículos.

- Se `quantidade >= MAX_VEICULOS`, exibe a mensagem: "Limite maximo de veiculos atingido."
- Caso contrário, solicita:
  - o modelo do veículo
  - a placa do veículo

Depois disso, define o status de aluguel como `0` (disponível) e aumenta a quantidade de veículos cadastrados.

### 2. Listagem dos veículos

A opção 2 percorre todos os veículos cadastrados e imprime:

- modelo
- placa
- status do veículo

O status é exibido da seguinte forma:

- `Disponivel` quando `alugado[i] == 0`
- `Indisponivel / Alugado` quando `alugado[i] != 0`

### 3. Aluguel de veículo

Ao selecionar a opção 3, o programa mostra uma lista numerada com os veículos cadastrados.

O usuário escolhe um número correspondente ao veículo desejado. Em seguida, o programa:

- verifica se o número informado é válido
- checa se o veículo está disponível
- marca `alugado[escolha - 1] = 1` caso o aluguel seja realizado com sucesso

Se o veículo já estiver alugado, o sistema informa que ele não pode ser alugado novamente.

### 4. Devolução de veículo

A opção 4 funciona de maneira semelhante ao aluguel.

- o usuário escolhe um veículo da lista
- o programa valida a escolha
- se o veículo estiver alugado, ele é marcado como disponível novamente com `alugado[escolha - 1] = 0`
- se o veículo não estiver alugado, o programa informa que a devolução não pode ser realizada

### 5. Encerramento

A opção 5 finaliza o programa com uma mensagem de despedida.

## Regras de validação

O programa realiza verificações simples para evitar erros de uso:

- não permite cadastrar mais veículos do que o limite definido
- impede aluguel de veículos inválidos
- impede devolução de veículos fora do intervalo válido
- garante que um veículo só possa ser alugado se estiver disponível

## Como executar

Para compilar o programa, use o compilador GCC:

```bash
gcc locadora.c -o locadora
```

Depois, execute:

```bash
./locadora
```

No Windows, normalmente a execução será feita com o arquivo gerado `.exe`.

## Observações

Este projeto é uma base inicial para estudos de programação em C e pode ser expandido com funcionalidades como:

- busca por veículos
- remoção de veículos
- cadastro de clientes
- controle de valores de aluguel
- persistência em arquivo

## Conclusão

A aplicação demonstra o uso de estruturas básicas em C, como arrays, condicionais, laços e entrada/saída de dados, e serve como uma introdução prática ao desenvolvimento de sistemas de gerenciamento com linguagem C.
