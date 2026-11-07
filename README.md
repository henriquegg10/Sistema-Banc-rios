# Sistema Bancário – Registro e Gestão de Contas

Projeto desenvolvido em C++ para implementar um sistema de registro e gestão de contas bancárias, permitindo cadastrar clientes, consultar contas e realizar movimentações financeiras.

## Objetivo

O projeto foi desenvolvido para implementar um sistema bancário capaz de:

1. Cadastrar e gerenciar várias contas bancárias.
2. Realizar operações de depósito, saque e transferência.
3. Consultar informações e saldos das contas.
4. Registrar e consultar o histórico de movimentações financeiras.

## Funcionalidades

### 1. Cadastrar contas bancárias

O programa permite cadastrar novas contas, armazenando informações como:

- Número da conta
- Nome completo do cliente
- CPF
- Tipo de conta (Corrente ou Poupança)
- Saldo inicial
- Situação da conta (Ativa ou Inativa)

Os números das contas são gerados automaticamente, começando pelo número `1001`.

### 2. Listar e consultar contas

O sistema permite visualizar todas as contas cadastradas e consultar individualmente uma conta pelo número.

São apresentadas informações como:

- Número da conta
- Nome do cliente
- CPF
- Tipo de conta
- Saldo disponível
- Situação da conta

### 3. Realizar depósitos

O programa permite realizar depósitos em contas cadastradas.

São realizadas as seguintes verificações:

- Existência da conta.
- Situação ativa da conta.
- Valor do depósito maior que zero.
- Disponibilidade de espaço no histórico de movimentações.

Após a operação, o saldo é atualizado e a movimentação é registrada com o código `D`.

### 4. Realizar saques

O sistema permite retirar valores das contas, verificando:

- Existência da conta.
- Situação ativa da conta.
- Valor do saque maior que zero.
- Saldo suficiente para realizar a operação.

Após a confirmação, o saldo é atualizado e a movimentação é registrada com o código `S`.

### 5. Realizar transferências

O programa permite transferir valores entre duas contas cadastradas.

Antes de realizar a operação, são verificadas:

- Existência das duas contas.
- Situação ativa de ambas.
- Diferença entre a conta de origem e a de destino.
- Valor positivo da transferência.
- Saldo suficiente na conta de origem.
- Espaço disponível para registrar as duas movimentações.

Cada transferência gera dois registros no histórico:

- `S` – Saída do valor na conta de origem.
- `D` – Entrada do valor na conta de destino.

### 6. Exibir extrato bancário

O sistema permite consultar o histórico de movimentações de uma conta específica.

São apresentados:

- Depósitos e entradas.
- Saques e saídas.
- Total de entradas.
- Total de saídas.
- Saldo atual da conta.

### 7. Armazenamento dos dados

O projeto utiliza arrays para armazenar as informações em memória.

Foram definidos os seguintes limites:

- Até 100 contas bancárias.
- Até 500 movimentações financeiras.

Os dados permanecem disponíveis enquanto o programa estiver em execução. Ao fechar o sistema, as informações são perdidas, conforme a proposta da Etapa 2.

## Tecnologias utilizadas

- C++
- Arrays (vetores)
- Estruturas de decisão (`if`, `else` e `switch`)
- Estruturas de repetição (`for` e `do while`)
- Funções
- Manipulação de dados em memória

## Instalação

Primeiro, clone o repositório:

```bash
git clone https://github.com/SEU-USUARIO/NOME-DO-REPOSITORIO.git
```

Entre na pasta do projeto:

```bash
cd NOME-DO-REPOSITORIO
```

## Compilação e execução

Para compilar o programa utilizando o compilador G++, execute:

```bash
g++ -std=c++17 SistemaBancario.cpp -o SistemaBancario
```

Para executar no Windows:

```bash
SistemaBancario.exe
```

Para executar no Linux:

```bash
./SistemaBancario
```

## Estrutura do projeto

- `SistemaBancario.cpp` – Código-fonte principal do sistema.
- `README.md` – Documentação e instruções de utilização.

## Considerações finais

O projeto foi desenvolvido como parte da atividade da disciplina INF101 – Programação de Computadores I, referente à Etapa 2 do trabalho de implementação de um Sistema de Registro e Gestão de Contas Bancárias.

O objetivo é aplicar conceitos fundamentais de programação em C++, utilizando arrays, funções, estruturas de decisão e repetição para organizar contas bancárias e registrar movimentações financeiras.
