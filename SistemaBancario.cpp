
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

// Limites definidos no enunciado.
const int MAX_CONTAS = 100;
const int MAX_MOVIMENTACOES = 500;

// Arrays paralelos para armazenar as contas.
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS]; // 1 = Corrente | 2 = Poupanca
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];
int quantidadeContas = 0;

// Arrays paralelos para armazenar o historico de movimentacoes.
int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES]; // D = Deposito | S = Saque
double valorMovimentacao[MAX_MOVIMENTACOES];
int quantidadeMovimentacoes = 0;

// Numero inicial para gerar as contas automaticamente.
int proximoNumeroConta = 1001;

// Funcao para ler numeros inteiros.
int lerInteiro(const string& mensagem) {
    int valor;

    while (true) {
        cout << mensagem;

        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        cout << "Entrada invalida. Digite um numero inteiro.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Funcao para ler valores decimais.
double lerDouble(const string& mensagem) {
    double valor;

    while (true) {
        cout << mensagem;

        if (cin >> valor && isfinite(valor)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        cout << "Entrada invalida. Digite um valor numerico.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Funcao para ler textos.
string lerTexto(const string& mensagem) {
    string texto;

    do {
        cout << mensagem;
        getline(cin, texto);

        if (texto.empty()) {
            cout << "O campo nao pode ficar vazio.\n";
        }

    } while (texto.empty());

    return texto;
}

// Localiza uma conta pelo numero.
int localizarConta(int numero) {
    for (int i = 0; i < quantidadeContas; i++) {

        if (numeroConta[i] == numero) {
            return i;
        }
    }

    return -1;
}

// Mostra os dados de uma conta.
void mostrarConta(int indice) {
    cout << fixed << setprecision(2);

    cout << "\nNumero da conta: " << numeroConta[indice] << '\n';
    cout << "Cliente: " << nomeCliente[indice] << '\n';
    cout << "CPF: " << cpf[indice] << '\n';

    cout << "Tipo: "
         << (tipoConta[indice] == 1 ? "Corrente" : "Poupanca")
         << '\n';

    cout << "Saldo: R$ " << saldo[indice] << '\n';

    cout << "Situacao: "
         << (contaAtiva[indice] ? "Ativa" : "Inativa")
         << "\n";
}

// Verifica se existe espaco no historico.
bool podeRegistrarMovimentacoes(int quantidadeNecessaria) {
    return quantidadeMovimentacoes + quantidadeNecessaria
           <= MAX_MOVIMENTACOES;
}

// Registra uma movimentacao no historico.
void registrarMovimentacao(int numero, char tipo, double valor) {

    contaMovimentacao[quantidadeMovimentacoes] = numero;
    tipoMovimentacao[quantidadeMovimentacoes] = tipo;
    valorMovimentacao[quantidadeMovimentacoes] = valor;

    quantidadeMovimentacoes++;
}

// Cadastra uma nova conta.
void cadastrarConta() {

    if (quantidadeContas >= MAX_CONTAS) {
        cout << "Limite de 100 contas atingido.\n";
        return;
    }

    cout << "\n=== CADASTRO DE CONTA ===\n";

    int indice = quantidadeContas;

    numeroConta[indice] = proximoNumeroConta++;

    nomeCliente[indice] = lerTexto("Nome completo do cliente: ");
    cpf[indice] = lerTexto("CPF: ");

    do {
        tipoConta[indice] = lerInteiro(
            "Tipo de conta (1 - Corrente | 2 - Poupanca): "
        );

        if (tipoConta[indice] != 1 && tipoConta[indice] != 2) {
            cout << "Opcao invalida. Escolha 1 ou 2.\n";
        }

    } while (tipoConta[indice] != 1 && tipoConta[indice] != 2);

    saldo[indice] = 0.0;
    contaAtiva[indice] = true;

    quantidadeContas++;

    cout << "\nConta cadastrada com sucesso!\n";
    cout << "Numero da conta: " << numeroConta[indice] << '\n';
    cout << "Saldo inicial: R$ 0.00\n";
}

// Lista todas as contas cadastradas.
void listarContas() {

    cout << "\n=== CONTAS CADASTRADAS ===\n";

    if (quantidadeContas == 0) {
        cout << "Nenhuma conta cadastrada.\n";
        return;
    }

    for (int i = 0; i < quantidadeContas; i++) {

        cout << "\n------------------------------\n";

        mostrarConta(i);
    }
}

// Consulta uma conta pelo numero.
void consultarConta() {

    cout << "\n=== CONSULTAR CONTA ===\n";

    int numero = lerInteiro("Informe o numero da conta: ");

    int indice = localizarConta(numero);

    if (indice == -1) {
        cout << "Conta nao encontrada.\n";
        return;
    }

    mostrarConta(indice);
}

// Realiza depositos.
void depositar() {

    cout << "\n=== DEPOSITO ===\n";

    int numero = lerInteiro("Informe o numero da conta: ");

    int indice = localizarConta(numero);

    if (indice == -1 || !contaAtiva[indice]) {
        cout << "Conta nao encontrada ou inativa.\n";
        return;
    }

    if (!podeRegistrarMovimentacoes(1)) {
        cout << "Limite de movimentacoes atingido. Deposito nao realizado.\n";
        return;
    }

    double valor = lerDouble("Valor do deposito: R$ ");

    if (valor <= 0) {
        cout << "O valor do deposito deve ser maior que zero.\n";
        return;
    }

    saldo[indice] += valor;

    registrarMovimentacao(numero, 'D', valor);

    cout << "Deposito realizado com sucesso. Novo saldo: R$ "
         << fixed << setprecision(2) << saldo[indice] << '\n';
}

// Realiza saques com verificacao de saldo.
void sacar() {

    cout << "\n=== SAQUE ===\n";

    int numero = lerInteiro("Informe o numero da conta: ");

    int indice = localizarConta(numero);

    if (indice == -1 || !contaAtiva[indice]) {
        cout << "Conta nao encontrada ou inativa.\n";
        return;
    }

    if (!podeRegistrarMovimentacoes(1)) {
        cout << "Limite de movimentacoes atingido. Saque nao realizado.\n";
        return;
    }

    double valor = lerDouble("Valor do saque: R$ ");

    if (valor <= 0) {
        cout << "O valor do saque deve ser maior que zero.\n";
        return;
    }

    if (saldo[indice] < valor) {
        cout << "Saldo insuficiente. Saque nao realizado.\n";
        return;
    }

    saldo[indice] -= valor;

    registrarMovimentacao(numero, 'S', valor);

    cout << "Saque realizado com sucesso. Novo saldo: R$ "
         << fixed << setprecision(2) << saldo[indice] << '\n';
}

// Realiza transferencias entre duas contas.
void transferir() {

    cout << "\n=== TRANSFERENCIA ===\n";

    int numeroOrigem = lerInteiro("Numero da conta de origem: ");

    int numeroDestino = lerInteiro("Numero da conta de destino: ");

    int indiceOrigem = localizarConta(numeroOrigem);

    int indiceDestino = localizarConta(numeroDestino);

    if (indiceOrigem == -1 || indiceDestino == -1) {
        cout << "Uma ou ambas as contas nao foram encontradas.\n";
        return;
    }

    if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
        cout << "As duas contas precisam estar ativas.\n";
        return;
    }

    if (numeroOrigem == numeroDestino) {
        cout << "A conta de origem e a de destino devem ser diferentes.\n";
        return;
    }

    if (!podeRegistrarMovimentacoes(2)) {
        cout << "Nao ha espaco para registrar os dois lancamentos da transferencia.\n";
        return;
    }

    double valor = lerDouble("Valor da transferencia: R$ ");

    if (valor <= 0) {
        cout << "O valor da transferencia deve ser maior que zero.\n";
        return;
    }

    if (saldo[indiceOrigem] < valor) {
        cout << "Saldo insuficiente na conta de origem.\n";
        return;
    }

    // Atualiza os saldos das duas contas.
    saldo[indiceOrigem] -= valor;

    saldo[indiceDestino] += valor;

    // Registra a saida e a entrada no historico.
    registrarMovimentacao(numeroOrigem, 'S', valor);

    registrarMovimentacao(numeroDestino, 'D', valor);

    cout << "Transferencia realizada com sucesso!\n";

    cout << "Novo saldo da conta " << numeroOrigem << ": R$ "
         << fixed << setprecision(2) << saldo[indiceOrigem] << '\n';

    cout << "Novo saldo da conta " << numeroDestino << ": R$ "
         << fixed << setprecision(2) << saldo[indiceDestino] << '\n';
}

// Exibe o extrato de uma conta.
void exibirExtrato() {

    cout << "\n=== EXTRATO ===\n";

    int numero = lerInteiro("Informe o numero da conta: ");

    int indice = localizarConta(numero);

    if (indice == -1) {
        cout << "Conta nao encontrada.\n";
        return;
    }

    cout << "\nExtrato da conta " << numero
         << " - " << nomeCliente[indice] << '\n';

    cout << "----------------------------------------\n";

    cout << fixed << setprecision(2);

    bool encontrou = false;

    double totalEntradas = 0.0;

    double totalSaidas = 0.0;

    for (int i = 0; i < quantidadeMovimentacoes; i++) {

        if (contaMovimentacao[i] == numero) {

            encontrou = true;

            if (tipoMovimentacao[i] == 'D') {

                cout << "Deposito/entrada: + R$ "
                     << valorMovimentacao[i] << '\n';

                totalEntradas += valorMovimentacao[i];

            } else if (tipoMovimentacao[i] == 'S') {

                cout << "Saque/saida:      - R$ "
                     << valorMovimentacao[i] << '\n';

                totalSaidas += valorMovimentacao[i];
            }
        }
    }

    if (!encontrou) {
        cout << "Nenhuma movimentacao registrada para esta conta.\n";
    }

    cout << "----------------------------------------\n";

    cout << "Total de entradas: R$ " << totalEntradas << '\n';

    cout << "Total de saidas:   R$ " << totalSaidas << '\n';

    cout << "Saldo atual:       R$ " << saldo[indice] << '\n';

    cout << "\nObs.: transferencias aparecem como saida na conta de origem e entrada na conta de destino.\n";
}

// Exibe o menu principal.
void exibirMenu() {

    cout << "\n========== SISTEMA BANCARIO ==========\n";

    cout << "1 - Cadastrar conta\n";

    cout << "2 - Listar contas\n";

    cout << "3 - Consultar conta\n";

    cout << "4 - Realizar deposito\n";

    cout << "5 - Realizar saque\n";

    cout << "6 - Realizar transferencia\n";

    cout << "7 - Exibir extrato\n";

    cout << "0 - Sair\n";

    cout << "======================================\n";
}

// Funcao principal do programa.
int main() {

    int opcao;

    do {

        exibirMenu();

        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {

            case 1:
                cadastrarConta();
                break;

            case 2:
                listarContas();
                break;

            case 3:
                consultarConta();
                break;

            case 4:
                depositar();
                break;

            case 5:
                sacar();
                break;

            case 6:
                transferir();
                break;

            case 7:
                exibirExtrato();
                break;

            case 0:
                cout << "\nEncerrando o sistema. Ate mais!\n";
                break;

            default:
                cout << "Opcao invalida. Escolha uma opcao do menu.\n";
        }

    } while (opcao != 0);

    return 0;
}
