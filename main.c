#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "funcoes.h"
typedef struct cliente Cliente;
struct cliente{
    char nome[150];
    char cpf[12];
    int dataNasc[3];
    float renda;
    char status;
};

typedef struct comercio Comercio;
struct comercio{
    char codigo[10];
    char nomeAlimento[60];
    float preco;
    char status;
};

void menuPrincipal();
void menuCliente();
void cadastrarCliente();
void atualizarCadastro();
void exibirCadastros();
void excluirCadastro();
void buscarCadastro();
void limpaArq();
void sobre();

void exibeCliente(Cliente *cliente);
void gravaCliente(Cliente *cliente);

void menuComercio();

int verificaNome(char x[]);
int validaLetra(char c);
int validaCpf(char x[]);
int validaRg(char x[]);
int validaNumero(char x);
int bissexto(int);
int dataValida(int, int, int);

int main(void){
    int resp;
    int op;

    do{
        menuPrincipal();
        printf("\n\nEscolha Umas das opções: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            do{
                menuCliente();
                printf("Informe a opção desejada: ");
                scanf("%d", &resp);
                getchar();
                switch (resp){
                case 1:
                    printf("Opção 1\n\n");
                    cadastrarCliente();
                    break;

                case 2:
                    printf("Opção 2\n\n");
                    atualizarCadastro();
                    break;

                case 3:
                    printf("Opção 3\n\n");
                    exibirCadastros();
                    break;

                case 4:
                    printf("Opção 4\n\n");
                    excluirCadastro();
                    break;

                case 5:
                    printf("Opção 5\n\n");
                    buscarCadastro();    
                    break;
                case 999:
                    printf("Surpresa....");
                    limpaArq();
                    break;    
                }

            } while (resp != 0);
            break;
        case 2:
            do{
                menuComercio();
                printf("\n\nEscolha uma das opções: ");
                scanf("%d", &resp);
                switch (resp){
                case 1:
                    printf("\nOp 1");
                    break;
                case 2:
                    printf("\nOp 2");
                    break;
                case 3:
                    printf("\nOp 3");
                    break;
                case 4:
                    printf("\nOp 4");
                    break;        
                case 5:
                    printf("\nOp 5");
                    break;
                case 6:
                    printf("\nOp 6");
                    break;
                case 7:
                    printf("\nOp 7");
                    break;
                }
            } while (resp != 0);
            break;
        case 3:
            do{
                system("clear");
                sobre();
                printf("\n0 - para Sair: ");
                //printf("Escolha Uma das opções: ");
                scanf("%d", &resp);

            } while (resp != 0);
            break;
        }
    } while (op != 0);
    printf("\n\nFIM :)\n\n");
    return 0;
}

void menuPrincipal(){
    system("clear");
    printf("\n######################################");
    printf("\n######################################");
    printf("\n####                              ####");
    printf("\n####        MENU PRINCIPAL        ####");
    printf("\n####                              ####");
    printf("\n######################################");
    printf("\n######################################");

    printf("\n\n1 - Clientes");
    printf("\n2 - Comercio");
    printf("\n3 - Sobre");
    printf("\n0 - Sair");
}
void menuCliente(){
    //system("clear");
    printf("\n######################################");
    printf("\n######################################");
    printf("\n####                              ####");
    printf("\n#### Sistema Controle de Clientes ####");
    printf("\n####                              ####");
    printf("\n######################################");
    printf("\n######################################");

    printf("\n\n1 - Cadastrar cliente");
    printf("\n2 - Atualizar cadastro");
    printf("\n3 - Exibir cadastros");
    printf("\n4 - Excluir cadastros");
    printf("\n5 - Buscar cadastro");
    printf("\n0 - Sair\n\n");
}


void menuComercio(){
    //system("clear");
    printf("\n######################################");
    printf("\n######################################");
    printf("\n####                              ####");
    printf("\n####           Comercio           ####");
    printf("\n####                              ####");
    printf("\n######################################");
    printf("\n######################################");

    printf("\n\n1 - Cadastrar compra");
    printf("\n2 - Atualizar compra");
    printf("\n3 - Excluir compra");
    printf("\n4 - Buscar compraa");
    printf("\n5 - Relatorio geral");
    printf("\n6 - Relatorio semanal");
    printf("\n7 - Relatorio mensal");
    printf("\n0 - Sair\n\n");
}

void cadastrarCliente(void){
    Cliente *cliente;
    printf("\n\n");
    printf("= = = SGControl = = = \n");
    printf("= Cadastrar Cliente  = \n");
    printf("= = = = = = = = = = = \n");
    cliente = (Cliente *)malloc(sizeof(Cliente));

    printf("Informe o nome do Cliente: ");
    scanf(" %149[^\n]", cliente->nome);

    while (!verificaNome(cliente->nome)){
        printf("\nInforme um nome valido: ");
        scanf(" %149[^\n]", cliente->nome);
    }

    printf("Informe o CPF do cliente: ");
    scanf(" %11[^\n]", cliente->cpf);

    while (validaCpf(cliente->cpf)){
        printf("Inforem um CPF valido (Apenas Numeros): ");
        scanf(" %11[^\n]", cliente->cpf);
    }

    printf("Informe a data de nascimento do animal (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &cliente->dataNasc[0], &cliente->dataNasc[1], &cliente->dataNasc[2]);
    getchar();

    while (!dataValida(cliente->dataNasc[0], cliente->dataNasc[1], cliente->dataNasc[2])){
        printf("Informe uma Data de Nascimento valida (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &cliente->dataNasc[0], &cliente->dataNasc[1], &cliente->dataNasc[2]);
        getchar();
    }

    printf("Inforem a renda do cliente: R$");
    scanf(" %f", &cliente->renda);
    cliente->status = '1';
    printf("###############################\n");
    exibeCliente(cliente);
    printf("###############################\n");
    gravaCliente(cliente);
}

void atualizarCadastro(void) {
    FILE* fp;
    Cliente* cliente;
    int achou;
    char resp;
    char procurado[12];
    fp = fopen("cliente.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G P e t = = = \n");
    printf("= = Editar Cadastro = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o CPF do cadastro a ser alterado (Apenas Numeros): ");
    scanf(" %11[^\n]", procurado);
    while (validaCpf(procurado)){
        printf("Inforem um CPF valido (Apenas Numeros): ");
        scanf(" %11[^\n]", procurado);
    }
    cliente = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeCliente(cliente);
        printf("Informe o nome do Cliente: ");
        scanf(" %149[^\n]", cliente->nome);

        while (!verificaNome(cliente->nome)){
            printf("\nInforme um nome valido: ");
            scanf(" %149[^\n]", cliente->nome);
        }

        printf("Informe o CPF do cliente: ");
        scanf(" %11[^\n]", cliente->cpf);

        while (validaCpf(cliente->cpf)){
            printf("Inforem um CPF valido (Apenas Numeros): ");
            scanf(" %11[^\n]", cliente->cpf);
        }

        printf("Informe a data de nascimento do animal (dd/mm/aaaa): ");
        scanf(" %d/%d/%d", &cliente->dataNasc[0], &cliente->dataNasc[1], &cliente->dataNasc[2]);
        getchar();

        while (!dataValida(cliente->dataNasc[0], cliente->dataNasc[1], cliente->dataNasc[2])){
            printf("Informe uma Data de Nascimento valida (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &cliente->dataNasc[0], &cliente->dataNasc[1], &cliente->dataNasc[2]);
            getchar();
        }

        printf("Inforem a renda do cliente: R$");
        scanf(" %f", &cliente->renda);
        cliente->status = '1';
        getchar();
        printf("Deseja realmente editar este cadastro (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, fp);
            printf("\nCadastro editado com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O CPF %s não foi encontrado...\n", procurado);
    }
    free(cliente);
    fclose(fp);
}


void exibirCadastros(void){
    FILE *fp;
    Cliente *cliente;
    fp = fopen("cliente.dat", "rb");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G control = = = \n");
    printf("= = Exibe Clientes = = \n");
    printf("= = = = = = = = = = = \n");
    cliente = (Cliente *)malloc(sizeof(Cliente));
    while (fread(cliente, sizeof(Cliente), 1, fp)){
        if (cliente->status == '1'){
            exibeCliente(cliente);
        }
    }
    fclose(fp);
    free(cliente);
}

void excluirCadastro(void){
    FILE *fp;
    Cliente *cliente;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("cliente.dat", "r+b");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G control = = = \n");
    printf("= = Apagar Cadastro = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o CPF do cliente a ser apagado (Apenas Numeros): ");
    scanf(" %11[^\n]", procurado);
    while (validaCpf(procurado)){
        printf("Inforem um CPF valido (Apenas Numeros): ");
        scanf(" %11[^\n]", procurado);
    }
    cliente = (Cliente *)malloc(sizeof(Cliente));
    achou = 0;
    while ((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))){
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }
    // fclose(fp); CORRIGIR ESTE ERRO AQUI
    if (achou){
        exibeCliente(cliente);
        getchar();
        printf("Deseja realmente apagar este cadastro (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            cliente->status = '0';
            fseek(fp, (-1) * sizeof(Cliente), SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, fp);
            printf("\nCadastro excluído com sucesso!!!\n");
        }else{
            printf("\nOk, os dados não foram alterados\n");
        }
    }else{
        printf("O Cpf %s não foi encontrado...\n", procurado);
    }
    free(cliente);
    fclose(fp);
}

void buscarCadastro(void) {
    FILE* fp;
    Cliente* cliente;
    int achou;
    char procurado[12];
    fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G P e t = = = \n");
    printf("= = Buscar Cadastro = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o CPF do cadastro a ser buscado: ");
    scanf(" %11[^\n]", procurado);
    while (validaCpf(procurado)){
        printf("Inforem um CPF valido (Apenas Numeros): ");
        scanf(" %11[^\n]", procurado);
    }
    cliente = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        exibeCliente(cliente);
    } else {
        printf("O animal %s não foi encontrado...\n", procurado);
    }
    free(cliente);
}

void sobre(){
    printf("\nINFORMAÇÕES SOBRE O DESENVOLVEDOR DO SINTEMA");
    printf("\n\n--------------------------------------------------");
    printf("\n\nSistema desenvolvido por Anderson Lucas da Costa Galdino\nEmai-l: andersoncosta.ob@gmail.com\nTelefone: (84) 9 86078267\nConta do Github: https://github.com/Andersonlks\n\n");
}

int verificaNome(char x[]){
    int tam;
    tam = strlen(x) - 1;
    for (int i = 0; i < tam; i++)
    {
        if (!validaLetra(x[i]))
        {
            return 0;
        }
    }
    return 1;
}

int validaLetra(char c){
    if (c >= 'A' && c <= 'Z'){
        return 1;
    }else if (c >= 'a' && c <= 'z'){
        return 1;
    }else if (c == ' '){
        return 1;
    }else{
        return 0;
    }
}

int validaCpf(char x[]){
    int tam;
    int cont = 0;
    tam = strlen(x);
    for (int i = 0; i < tam; i++){
        cont += 1;
        if (!validaNumero(x[i])){
            return 1;
        }
    }
    if (cont != 11){
        return 1;
    }
    return 0;
}

int validaRg(char x[]){
    int tam;
    int cont = 0;
    tam = strlen(x);
    for (int i = 0; i < tam; i++){
        cont += 1;
        if (!validaNumero(x[i]))
        {
            return 1;
        }
    }
    if (cont != 9){
        return 1;
    }
    return 0;
}

int validaNumero(char x){
    if (x >= '0' && x <= '9')
    {
        return 1;
    }
    return 0;
}

int bissexto(int aa){
    if ((aa % 4 == 0) && (aa % 100 != 0))
    {
        return 1;
    }else if (aa % 400 == 0){
        return 1;
    }else{
        return 0;
    }
}

int dataValida(int dd, int mm, int aa){
    int maiorDia;
    if (aa < 0 || mm < 1 || mm > 12)
        return 0;

    if (mm == 2){
        if (bissexto(aa)){
            maiorDia = 29;
        }else{
            maiorDia = 28;
        }
    }else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)  {
        maiorDia = 30;
    }else{
        maiorDia = 31;
    }
    if (dd < 1 || dd > maiorDia){
        return 0;
    }else if (mm < 1 || mm > 12){
        return 0;
    }
    return 1;
}


void gravaCliente(Cliente * cliente){
    FILE *fp;
    fp = fopen("cliente.dat", "ab");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
}

void exibeCliente(Cliente * cliente){
    printf("Nome: %s\n", cliente->nome);
    printf("CPF: %s\n", cliente->cpf);
    printf("Nascimento: %02d/%02d/%04d\n", cliente->dataNasc[0], cliente->dataNasc[1], cliente->dataNasc[2]);
    printf("Renda: R$%.2f\n", cliente->renda);
    printf("\n");
}

void limpaArq(){
  FILE* fp1;
  FILE* fp2;
  Cliente* cliente;

  fp1 = fopen("cliente.dat", "rb");
  if (fp1 == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fp2 = fopen("backup.dat", "wb");
  if (fp2 == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  cliente = (Cliente*) malloc(sizeof(Cliente));

  while(fread(cliente, sizeof(Cliente), 1, fp1)) {
    if (cliente->status == '1'){
      fwrite(cliente, sizeof(Cliente), 1, fp2);
    }
  }
  fclose(fp1);
  fclose(fp2);

  fp1 = fopen("cliente.dat", "wb");
  if (fp1 == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fp2 = fopen("backup.dat", "rb");
  if (fp2 == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  while(fread(cliente, sizeof(Cliente), 1, fp2)) {
    fwrite(cliente, sizeof(Cliente), 1, fp1);
  }
  fclose(fp1);
  fclose(fp2);
  free(cliente);  
}
