#include <stdio.h>
#include <windows.h>
#include <ctype.h>
// #include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_CLIENTES 30

//Declara��o structs - Cliente e Conta
typedef struct
{
    char nome[100];
    int RG;
    char endereco[200];
    int telefone;
    float renda;
    int tipo_cliente; //1-private, 2-alta renda, 3-varejo
    union
    {
        int cpf;
        int cnpj;
    } cpf_cnpj;
    int num_cl;
} Cliente;
Cliente cliente[MAX_CLIENTES];
char nome[100];
char endereco[200];

int posicao;

typedef struct
{
    int Numero_Conta; //deve ser unico e gerado pelo programa
    int Agencia;
    float Saldo_Conta;
    int Tipo_Conta;          // 1- Conta corrente 2-Conta poupan�a 3- conta-salario
    struct Cliente *Titular; // titulares (deve estar vinculado aos clientes cadastrados)
    float pix;

} Dados_Contas;
Dados_Contas contas[MAX_CLIENTES];

void pausar()
{
#ifdef WIN32
    system("pause");
#else
    system("read -p \"Pressione enter para sair\"");
#endif
}

void limparTela()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limparEntrada()
{
#ifdef WIN64
    fflush(stdin);
#else
    __fpurge(stdin);
#endif
}

void Add_Cliente(int i)
{
    printf("\n\n     --------------------\n     |   NOVO CLIENTE   | \n     -------------------- \n\n");

    printf("Nome: \n");
    limparEntrada();
    gets(cliente[i].nome);
    //puts(cliente[i].nome);
    fflush(stdin);

    printf("RG: \n");
    scanf("%d", &cliente[i].RG);
    //printf("%d\n", cliente[i].RG);

    printf("Endereco: \n");
    limparEntrada();
    gets(cliente[i].endereco);
    fflush(stdin);
    //puts(cliente[i].endereco);

    printf("Telefone: \n");
    scanf("%d", &cliente[i].telefone);
    //printf("%d\n", cliente[i].telefone);

    printf("Renda: \n");
    scanf("%f", &cliente[i].renda);
    //printf("%.2f\n", cliente[i].renda);

    printf("Tipo de Cliente: \n 1-private, 2-alta renda, 3-varejo \n");
    scanf("%d", &cliente[i].tipo_cliente);
    //printf("%d\n", cliente[i].tipo_cliente);

    printf("CPF ou CNPJ: \n");
    scanf("%d", &cliente[i].cpf_cnpj);
    //printf("%d\n", cliente[i].cpf_cnpj);

    cliente[i].num_cl = i;
    printf("\n O numero do cliente eh: %d - NAO PERCA ESSE NUMERO \n \n \n ", i);
}

void Add_Conta(int j, int num)
{
    int id, menu;
    printf("\n\n     -----------------\n     |   NOVA CONTA   | \n     ----------------- \n\n");
    printf("Qual o numero (identificador) do cliente titular? ");
    scanf("%d", &id);
    if (cliente[id].num_cl == -1)
    { //tratando erro de cliente nao existente
        limparTela();
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n     Esse cliente nao esta cadastrado! \n     Por favor, verifique se o numero do cliente esta correto ou\n     volte ao MENU PRINCIPAL e cadastre um novo cliente\n");
    }
    else
    {
        contas[j].Titular = &cliente[id];
        printf("Nome do Titular: %s ", contas[j].Titular);
        printf("\nAgencia: ");
        scanf("%d%*c", &contas[j].Agencia);
        contas[j].Numero_Conta = num;
        printf("\nO sistema definiu o seguinte numero para a conta: %d - NAO PERCA ESSE NUMERO \n", num);
        printf("\nSaldo da conta:");
        scanf("%f%*c", &contas[j].Saldo_Conta);
        printf("\nTipo da conta: \n 1- CONTA-CORRENTE \n 2- CONTA POUPANCA \n 3- CONTA-SALARIO\n ");
        scanf("%d%*c", &contas[j].Tipo_Conta);

        printf("\nCrie sua chave PIX (CPF ou Telefone): ");
        scanf("%f", &contas[j].pix);
    }
}

void Imprimir_Conta()
{
    int ct, ag, count = 0;
    printf("\n\n     -----------------\n       BUSCAR CONTA    \n     ----------------- \n\n");
    printf("     Digite o numero da conta que voce deseja buscar: \n ");
    scanf("%d", &ct);
    printf("\n     Digite a agencia que essa conta pertence: \n ");
    scanf("%d", &ag);
    limparTela();
    for (int var = 0; var < 30; var++)
    {
        if (ct == contas[var].Numero_Conta && ag == contas[var].Agencia)
        {
            printf("\n\n     -----------------------\n        DADOS DA CONTA    \n     ----------------------- \n\n");
            printf("\n Numero da conta: %d", contas[var].Numero_Conta);
            printf("\n Agencia: %d", contas[var].Agencia);
            printf("\n Saldo: %.2f", contas[var].Saldo_Conta);
            printf("\n Tipo de conta: %d", contas[var].Tipo_Conta);
            printf("\n Nome do Titular: %s \n", contas[var].Titular);
            printf("\n Sua chave PIX eh: %.2f", contas[var].pix);
            printf("\n ---------------------------------------------------------------- \n");

            count = count + 1;
        }
    }
    if (count == 0)
    {
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n");
        printf("\n\n     Nao foi encontrada nenhuma conta com esses dados :( \n     Verifique se o numero da conta e a agencia estao corretos!\n\n");
    }
}

void Imprimir_Cliente()
{
    int n, count = 0;
    printf("\n\n     --------------------\n        BUSCAR CLIENTE    \n     -------------------- \n\n");
    printf("\n\n     Digite o numero do cliente que voce deseja buscar: \n ");
    scanf("%d", &n);
    limparTela();
    for (int var = 0; var < 30; var++)
    {
        if (n == cliente[var].num_cl)
        {
            printf("\n\n     -------------------\n       DADOS DO CLIENTE    \n     ------------------- \n\n");
            printf("\n Nome: %s", cliente[var].nome);
            printf("\n RG: %d", cliente[var].RG);
            printf("\n Endereco: %s", cliente[var].endereco);
            printf("\n Telefone: %d", cliente[var].telefone);
            printf("\n Renda: %.2f", cliente[var].renda);
            printf("\n Tipo de Cliente: %d", cliente[var].tipo_cliente);
            printf("\n CPF ou CNPJ: %d", cliente[var].cpf_cnpj);
            printf("\n Numero do Cliente: %d", cliente[var].num_cl);
            printf("\n ---------------------------------------------------------------- \n");
            count = count + 1;
        }
    }
    if (count == 0)
    {
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n");
        printf("\n Nao foi encontrada nenhuma cadastro com esses dados :( \n Verifique se o numero do cliente esta correto! \n ");
    }
}

void ListaCliente_Agencia()
{
    int ag = 0;
    int x = 0, count = 0;
    printf("\n\n     --------------------------------------\n        LISTA DE CLIENTES DE UMA AGENCIA    \n     -------------------------------------- \n\n ");
    printf("Numero da agencia: \n");
    scanf("%d", &ag);
    limparTela();
    printf("\n\n     --------------------------------------\n        NOME DOS CLIENTES DA AGENCIA    \n     -------------------------------------- \n\n ");
    for (x = 0; x <= MAX_CLIENTES; x++)
    {
        if (contas[x].Agencia == ag)
        {
            printf("     %s \n", contas[x].Titular);
            count = count + 1;
        }
    }
    if (count == 0)
    {
        limparTela();
        printf("\n\n     Essa busca nao encontrou nenhum resultado! \n------------------------------------------------- \n\n ");
    }
}
void ListaContas_tipo_agencia()
{
    int ag = 0, tp = 0, count = 0;
    printf("\n\n     ---------------------------------------------\n        LISTA DE CONTAS POR TIPO DE UMA AGENCIA    \n     --------------------------------------------- \n\n ");
    printf(" Numero da agencia: \n");
    scanf("%d", &ag);
    printf("\n 1- CONTA-CORRENTE  2- CONTA POUPANCA  3- CONTA-SALARIO \n Tipo de conta: \n");
    scanf("%d", &tp);
    limparTela();
    printf("\n\n     ----------------------\n      DADOS DAS CONTAS \n     ----------------------\n");
    for (int x = 0; x <= MAX_CLIENTES; x++)
    {
        if (contas[x].Agencia == ag && contas[x].Tipo_Conta == tp)
        {
            printf("\n Numero da conta: %d", contas[x].Numero_Conta);
            printf("\n Agencia: %d", contas[x].Agencia);
            printf("\n Saldo: %.2f", contas[x].Saldo_Conta);
            printf("\n Tipo de conta: %d", contas[x].Tipo_Conta);
            printf("\n Nome do Titular: %s", contas[x].Titular);
            printf("\n Sua chave PIX eh: %f", contas[x].pix);
            printf("\n ---------------------------------------------------------------- \n");
            count = count + 1;
        }
    }
    if (count == 0)
    {
        limparTela();
        printf("\n\n     Essa busca nao encontrou nenhum resultado! \n------------------------------------------------- \n\n ");
    }
}
void Atualizar_Cliente()
{
    int n = 0, x = 8;
    printf("\n\n     ----------------------\n      ATUALIZAR CLIENTE \n     ----------------------\n");
    printf("\n Qual o numero do cliente: \n ");
    scanf("%d", &n);
    limparTela();

    if (cliente[n].num_cl != -1)
    { //verifica se o cliente existe
        do
        {
            printf("\n Selecione uma opcao de atualizacao para o cliente %d \n", n);
            printf("\n 1- Nome \n 2- RG \n 3- Endereco \n 4- Renda \n 5- Tipo de Cliente \n 6- Telefone \n 7- TODAS AS INFORMACOES \n 0- Retornar ao Menu Principal \n\n Nao eh permitida a alteracao de CPF e do numero do cliente! \n");
            scanf("%d", &x);
            limparTela();
            switch (x)
            {
            case 1: //nome
                printf("\n Novo nome: ");
                limparEntrada();
                gets(cliente[n].nome);
                fflush(stdin);
                limparTela();
                //puts(cliente[n].nome);
                printf("\n \n Nome atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            case 2: //RG
                printf("\n Novo RG: ");
                scanf("%d", &cliente[n].RG);
                limparTela();
                printf("\n \n RG atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            case 3: //endereco
                printf("\n Novo Endereco: ");
                limparEntrada();
                gets(cliente[n].endereco);
                fflush(stdin);
                limparTela();
                printf("\n \n Endereco atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            case 4: //Renda
                printf("\n Nova Renda: ");
                scanf("%.2f", &cliente[n].renda);
                limparTela();
                printf("\n \n Renda atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            case 5: //Tipo cliente
                printf("\n Novo Tipo de Cliente: \n 1-private, 2-alta renda, 3-varejo \n");
                scanf("%d", &cliente[n].tipo_cliente);
                limparTela();
                printf("\n \n Tipo de cliente atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            case 6: //telefone
                printf("\n Novo Telefone: ");
                scanf("%d", &cliente[n].telefone);
                limparTela();
                printf("\n \n Telefone atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            case 7: //Todas
                printf("Nome: \n");
                limparEntrada();
                gets(cliente[n].nome);
                fflush(stdin);

                printf("RG: \n");
                scanf("%d", &cliente[n].RG);

                printf("Endereco: \n ");
                limparEntrada();
                gets(cliente[n].endereco);
                fflush(stdin);

                printf("Telefone: \n");
                scanf("%d", &cliente[n].telefone);

                printf("Renda: \n");
                scanf("%f", &cliente[n].renda);

                printf("Tipo de Cliente: \n 1-private, 2-alta renda, 3-varejo \n");
                scanf("%d", &cliente[n].tipo_cliente);

                limparTela();
                printf("\n \n Cadastro de Cliente atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            }

        } while (x != 0);

        // se o cliente nao existir
    }
    else
    {
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n");
        printf("\n Nao foi encontrada nenhuma cadastro com esses dados :( \n Verifique se o numero do cliente esta correto! \n ");
    }
}

void Atualizar_Conta()
{
    int n = 0, x = 4, id = -1;
    printf("\n\n     ----------------------\n         ATUALIZAR CONTA \n     ----------------------\n");
    printf("\n Qual o numero da conta que deseja atualizar? \n ");
    scanf("%d", &n);
    n = n - 1000;

    limparTela();
    if (contas[n].Numero_Conta < 0)
    { //verifica se a conta existe
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n");
        printf("\n Nao foi encontrada nenhuma cadastro com esses dados :( \n Verifique se o numero do cliente esta correto! \n ");
    }
    else
    {
        do
        {
            printf("\n Selecione uma opcao de atualizacao para a conta %d \n", n);
            printf("\n 1- Saldo \n 2- Titular \n 3 - Chave PIX \n 4 - Todas as informacoes \n 0- Retornar ao Menu Principal \n\n Nao eh permitida a alteracao de Agencia, Tipo de conta e do numero da conta! \n");
            scanf("%d", &x);
            limparTela();

            switch (x)
            {
            case 1: //saldo
                printf("Novo saldo da conta: \n");
                scanf("%f%*c", &contas[n].Saldo_Conta);
                limparTela();
                printf("\n \n Novo saldo da Conta atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            case 2: //titular
                printf("Qual o numero (identificador) do novo titular? ");
                scanf("%d", &id);
                contas[n].Titular = &cliente[id];

                limparTela();
                printf("\n \n Novo titular atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;

            case 3: //chave pix
                printf("Qual a nova chave PIX? ");
                scanf("%f", &contas[n].pix);

                limparTela();
                printf("\n \n Nova chave PIX atualizada com sucesso!\n");
                pausar();
                limparTela();
                break;

            case 4: //todos
                printf("Novo saldo da conta: \n");
                scanf("%f%*c", &contas[n].Saldo_Conta);
                printf("Qual o numero (identificador) do novo titular? ");
                scanf("%d", &id);
                contas[n].Titular = &cliente[id];

                limparTela();
                printf("\n \n Novo titular atualizado com sucesso!\n");
                pausar();
                limparTela();
                break;
            }
        } while (x != 0);
    }
}

void deposito()
{
    int n = 0, x = 1;
    float novoDeposito;
    printf("\n\n     ----------------------\n         FAZER DEPOSITO \n     ----------------------\n");
    printf("\n Qual o numero da conta que deseja efetuar o deposito? \n ");
    scanf("%d", &n);
    n = n - 1000;

    limparTela();
    if (contas[n].Numero_Conta < 0)
    { //verifica se a conta existe
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n");
        printf("\n Nao foi encontrada nenhuma cadastro com esses dados :( \n Verifique se o numero da conta esta correto! \n ");
    }
    else
    {
            printf("\nDigite o valor que deseja depositar: ");
            scanf("%f", &novoDeposito);
            contas[n].Saldo_Conta += novoDeposito;

            printf("\nSeu novo saldo eh de: %.2f \n", contas[n].Saldo_Conta);

pausar();
    }
}

void saque()
{
    int n = 0, x = 1;
    float novoSaque;
    printf("\n\n     ----------------------\n         FAZER SAQUE \n     ----------------------\n");
    printf("\n Qual o numero da conta que deseja efetuar o saque? ");
    scanf("%d", &n);
    n = n - 1000;

    limparTela();
    if (contas[n].Numero_Conta < 0)
    { //verifica se a conta existe
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n");
        printf("\n Nao foi encontrada nenhuma cadastro com esses dados :( \n Verifique se o numero da conta esta correto! \n ");
    }
    else
    {

            printf("\nDigite o valor que deseja sacar: ");
            scanf("%f", &novoSaque);

            if (novoSaque < contas[n].Saldo_Conta)
            {
                contas[n].Saldo_Conta -= novoSaque;

                printf("\nSeu novo saldo eh de: %.2f", contas[n].Saldo_Conta);
            }
            else
            {
                printf("Voce nao tem saldo suficiente!");
                printf("\nSeu saldo eh de: %.2f \n", contas[n].Saldo_Conta);
            }


    }
}

void pix()
{
    int n, x = 1;
    float valorPIX;
    printf("\n\n     ----------------------\n         FAZER PIX \n     ----------------------\n");
    printf("\nDigite o numero da sua conta: ");
    scanf("%d", &n);
    n = n - 1000;

    limparTela();
    if (contas[n].Numero_Conta < 0)
    { //verifica se a conta existe
        printf("\n\n     -----------------\n           ERRO    \n     ----------------- \n\n");
        printf("\n Nao foi encontrada nenhuma cadastro com esses dados :( \n Verifique se o numero da conta esta correto! \n ");
    }
    else
    {

            printf("\nQual o PIX da conta que deseja fazer a transferencia: ");
            scanf("%f", &contas[n].pix);
            printf("\nDigite o valor que deseja transferir atraves do PIX: ");
            scanf("%f", &valorPIX);

            for (int cliente = 0; cliente <= MAX_CLIENTES; cliente++)
            {
                if (contas[cliente].pix == contas[n].pix)
                {
                    contas[n].Saldo_Conta -= valorPIX;
                    contas[cliente].Saldo_Conta += valorPIX;
                    printf("Valor Transferido \n\n");
                }
            }
            pausar();


    }
}

int i = 0, j = 0;
int num = 1000;
int main()
{
    //variaveis
    int Menu0, Menu1 = 0, Menu2 = 0, Menu3 = 0;

    //inicializa o vetor com todos elementos nulo
    for (i = 0; i < 30; i++)
    {
        strcpy(cliente[i].nome, "NULL");
        cliente[i].RG = 0;
        strcpy(cliente[i].endereco, "NULL");
        cliente[i].telefone = 0;
        cliente[i].renda = 0.0;
        cliente[i].tipo_cliente = 0;
        cliente[i].cpf_cnpj.cpf = 0;
        cliente[i].num_cl = -1;
    }
    for (i = 0; i < 30; i++)
    {
        contas[i].Numero_Conta = -1;
        contas[i].Agencia = 0;
        contas[i].Saldo_Conta = 0.0;
        contas[i].Tipo_Conta = 0;
    }

    i = 0; //indice dos clientes
    j = 0; //indice das contas

    //MENU
    do
    {
        printf("\n\n     ------------\n     |   MENU   | \n     ------------ \n\n      1- Cadastrar Dados\n      2- Imprimir Dados \n      3- Atualizar Cadastro \n      4- Deposito \n      5- Saque \n      6- Pix \n      0- Sair \n");
        scanf("%d", &Menu0);
        limparTela();

        switch (Menu0)
        {
        // 1- inserir
        case 1:
            printf("\n\n     -----------------\n     |   CADASTRAR   | \n     ----------------- \n\n      1- Nova Conta \n      2- Novo Cliente \n");
            scanf("%d", &Menu1);
            limparTela();
            // chamada para nova conta
            if (Menu1 == 1)
            {
                Add_Conta(j, num);
                num = num + 1;

                // chamada para novo cliente
            }
            else if (Menu1 == 2)
            {
                Add_Cliente(i);
            }
            else
                printf("\n\n      ERRO!!!!!!!!!!!!!!!! \n Digite um numero valido - 1 ou 2 \n \n ");
            pausar();

            //MENSAGENS de confirmacao para o usuario

            if (Menu1 == 2)
            {
                i = i + 1;
                limparTela();
                printf("\n\n     Cadastro de Cliente realizado com sucesso! \n\n ");
                pausar();
                limparTela();
            }
            else if (Menu1 == 1)
            {
                limparTela();
                printf("\n\n     Cadastro da conta realizado com sucesso! \n\n ");
                j = j + 1;
                pausar();
                limparTela();
            }

            break;

        //2- imprimir
        case 2:
            printf("\n\n     -----------------\n     |   IMPRIMIR   | \n     ----------------- \n\n     1- Dados de uma conta \n     2- Dados de um cliente \n     3- Lista de clientes de uma agencia \n     4- Lista de Contas por tipo de uma agencia \n");
            scanf("%d", &Menu2);
            limparTela();

            if (Menu2 == 1)
            { // chamada imprimir dados de uma conta
                Imprimir_Conta();
            }
            else if (Menu2 == 2)
            { // chamada para Imprimir dados de um cliente
                Imprimir_Cliente();
            }
            else if (Menu2 == 3)
            { // chamada para Lista de clientes de uma agencia
                ListaCliente_Agencia();
            }
            else if (Menu2 == 4)
            { // chamada para Lista de Contas por tipo de uma agencia
                ListaContas_tipo_agencia();
            }
            else
                printf("\n ERRO!!!!!!!!!!!!!!!! \n Digite um numero valido - de 1 a 4 \n \n ");
            pausar();
            limparTela();
            break;

        //3- Atualizar
        case 3:
            printf("Voce deseja: \n 1- Atualizar dados de um cliente \n 2- Atualizar dados de uma conta \n");
            scanf("%d", &Menu3);
            if (Menu3 == 1)
            { // chamada para atualizar dados de um cliente
                Atualizar_Cliente();
            }
            else if (Menu3 == 2)
            { // chamada para atualizar dados de uma conta
                Atualizar_Conta();
            }
            else
                printf("\n ERRO!!!!!!!!!!!!!!!! \n Digite um numero valido - 1 ou 2 \n \n ");
            pausar();
            limparTela();
            break;

        // 4- Deposito
        case 4:
            deposito();
            limparTela();
            break;

        //5- Saque
        case 5:
            saque();
            limparTela();
            break;

        //6- PIX
        case 6:
            pix();
            limparTela();
            break;
        }

    } while (Menu0 != 0);
}
