# Sistema Bancário – Registro e Gestão de Contas

Projeto desenvolvido em C++ para a disciplina **INF101 – Programação de Computadores I**, do Centro Universitário de Viçosa (UNIVIÇOSA). O sistema permite cadastrar contas bancárias, consultar informações e realizar movimentações financeiras, conforme os requisitos da Etapa 2 do trabalho.

## Objetivo

O projeto foi desenvolvido para aplicar conceitos de programação em C++, utilizando arrays, funções, estruturas de decisão e repetição para gerenciar várias contas bancárias e registrar suas movimentações em memória.

## Funcionalidades

### 1. Cadastrar contas bancárias

O programa permite cadastrar até 100 contas, armazenando:

- Número da conta, gerado automaticamente a partir de `1001`;
- Nome completo do cliente;
- CPF;
- Tipo de conta: corrente ou poupança;
- Saldo inicial de R$ 0,00;
- Situação da conta (ativa no momento do cadastro).

### 2. Listar e consultar contas

O sistema permite listar todas as contas cadastradas ou consultar uma conta específica pelo número. São exibidos o número, nome do cliente, CPF, tipo de conta, saldo e situação.

### 3. Realizar depósitos

Permite adicionar valores a uma conta ativa. O sistema verifica se a conta existe, se está ativa, se o valor é maior que zero e se há espaço no histórico. O depósito atualiza o saldo e é registrado com o código `D`.

### 4. Realizar saques

Permite retirar valores de uma conta ativa. Antes de concluir a operação, o programa verifica se a conta existe, se está ativa, se o valor é positivo, se há espaço no histórico e se existe saldo suficiente. O saque é registrado com o código `S`.

### 5. Realizar transferências

Permite transferir valores entre duas contas cadastradas e ativas. O sistema verifica se as contas existem, se são diferentes, se o valor é positivo, se há saldo suficiente na conta de origem e se há espaço para os dois registros no histórico.

Cada transferência gera dois registros:

- `S`: saída do valor na conta de origem;
- `D`: entrada do valor na conta de destino.

### 6. Exibir extrato bancário

Apresenta somente as movimentações da conta consultada, mostrando depósitos/entradas, saques/saídas, total de entradas, total de saídas e saldo atual.

### 7. Armazenamento dos dados

As contas e as movimentações são armazenadas em arrays paralelos:

- Limite de 100 contas;
- Limite de 500 movimentações.

Os dados permanecem apenas na memória durante a execução. Ao fechar o programa, as informações são perdidas, conforme solicitado na Etapa 2. A persistência dos dados será desenvolvida na Etapa 3.

## Tecnologias utilizadas

- C++
- Arrays (vetores)
- Funções
- Estruturas de decisão (`if`, `else` e `switch`)
- Estruturas de repetição (`for` e `do while`)
- Entrada e saída de dados pelo terminal

## Instalação

Primeiro, clone este repositório:

```bash
git clone https://github.com/henriquegg10/Sistema-Banc-rios.git
```

Entre na pasta do projeto:

```bash
cd Sistema-Banc-rios
```

## Compilação e execução

É necessário ter um compilador C++ instalado, como o G++.

### Windows

Compile o programa:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic SistemaBancario.cpp -o SistemaBancario.exe
```

Execute:

```bash
SistemaBancario.exe
```

### Linux

Compile o programa:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic SistemaBancario.cpp -o SistemaBancario
```

Execute:

```bash
./SistemaBancario
```

## Estrutura do projeto

- `SistemaBancario.cpp` – código-fonte do sistema bancário;
- `README.md` – documentação do projeto e instruções de compilação e execução.

## Considerações finais

Este projeto corresponde à **Etapa 2** do trabalho de implementação de um Sistema de Registro e Gestão de Contas Bancárias da disciplina INF101 – Programação de Computadores I.
