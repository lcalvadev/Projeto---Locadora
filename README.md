# Projeto Locadora

Este projeto é um sistema simples em C para gerenciar uma locadora de veículos. Ele permite cadastrar clientes e veículos, listar registros, alugar veículos por um número de dias e registrar devoluções.

## Funcionalidades

O programa oferece as seguintes opções no menu principal:

1. Cadastrar cliente
2. Cadastrar veículo
3. Listar clientes
4. Listar veículos
5. Alugar veículo
6. Devolver veículo
7. Sair

Além disso, o sistema realiza um cadastro inicial de cliente antes do menu principal e informa o valor total do aluguel calculado com base na diária do veículo.

## Estrutura do programa

O arquivo principal é [locadora.c](locadora.c), que contém:

- constantes para limites máximos:
  - `MAX_VEICULOS`
  - `MAX_CLIENTES`
- estruturas:
  - `Cliente` com nome e CPF
  - `Veiculo` com modelo, placa, status de aluguel e valor da diária
- variáveis para controlar quantidade de clientes e veículos
- menu interativo em loop com `do...while`

## Como funciona

### Cadastro inicial de cliente

Ao iniciar o programa, o sistema já solicita automaticamente os dados do cliente inicial:

- nome
- CPF

Depois disso, o cliente é incluído no array de clientes e a aplicação entra no menu principal.

### 1. Cadastrar cliente

A opção 1 permite incluir novos clientes no sistema, desde que ainda haja espaço.

Validações:

- impede cadastro quando `quantidadeClientes >= MAX_CLIENTES`
- exige nome e CPF

### 2. Cadastrar veículo

A opção 2 permite incluir novos veículos com:

- modelo
- placa
- valor da diária

O status de aluguel é inicializado como disponível (`alugado = 0`).

Validações:

- impede cadastro quando `quantidadeVeiculos >= MAX_VEICULOS`

### 3. Listar clientes

A opção 3 exibe todos os clientes cadastrados com:

- nome
- CPF

### 4. Listar veículos

A opção 4 exibe todos os veículos cadastrados com:

- modelo
- placa
- valor da diária
- status (`Disponivel` ou `Indisponivel / Alugado`)

### 5. Alugar veículo

A opção 5 permite alugar um veículo para um cliente.

Fluxo:

- verifica se existem clientes cadastrados
- verifica se existem veículos cadastrados
- mostra lista de clientes e veículos
- solicita escolha do cliente e do veículo
- valida as entradas
- verifica se o veículo já está alugado
- solicita a quantidade de dias de aluguel
- calcula o valor total com:
  - `diaria * dias`
- marca o veículo como alugado

### 6. Devolver veículo

A opção 6 permite devolver um veículo que está alugado.

Fluxo:

- lista os veículos cadastrados
- valida a escolha
- verifica se o veículo está realmente alugado
- marca como disponível novamente

### 7. Sair

A opção 7 encerra o programa com mensagem de despedida.

## Validações do sistema

O programa inclui verificações para evitar operações inválidas, como:

- limite máximo de clientes alcançado
- limite máximo de veículos alcançado
- cliente inexistente
- veículo inexistente
- veículo já alugado
- veículo não alugado para devolução
- quantidade de dias inválida

## Observações

Este projeto é uma aplicação de estudo para praticar:

- estruturas em C
- arrays
- laços de repetição
- condicionais
- entrada e saída de dados
- lógica de controle de aluguel

Ele também pode ser expandido futuramente com funcionalidades como persistência em arquivo, remoção de registros e controle mais detalhado de aluguel.
