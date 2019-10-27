#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

//gcc -o prog funcoes.o prog.o
typedef struct cliente Cliente;
struct cliente{
    char nome[150];
    char cpf[12];
    int dataNasc[3];
    float renda;
    char status;
};

typedef struct servico Servico;
struct servico{
    char codigo[10];
    char nomeServico[60];
    float preco;
    char statuServ;
};

typedef struct registro  Registro;
struct registro{
    char nomeReg[60];
    char nomeCli[150];
    char cpfCli[12];
    float precoServ;
    char statusReg;
    char statusAtiv;
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

void menuServicos();
void cadastrarServico(void);
void exibirServico(void);
void buscarServico(void);
void excluirServico(void);
void atualizarServico(void); 

void exibeServico(Servico* servico);
void gravaServico(Servico* servico);

void menuBarbearia();

void selecionaCorte(void);
void atualizarCorte(void);
void listarRegistro(void);
void buscarRegistro(void);
void excluiRegistro(void);

void exibeRegistro(Registro* registro);
void gravaRegistro(Registro* registro);

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
                menuServicos();
                printf("\n\nEscolha uma das opções: ");
                scanf("%d", &resp);
                switch (resp){
                case 1:
                    printf("\nOp 1");
                    cadastrarServico();
                    break;
                case 2:
                    printf("\nOp 2");
                    atualizarServico(); 
                    break;
                case 3:
                    printf("\nOp 3");
                    excluirServico();
                    break;
                case 4:
                    printf("\nOp 4");
                    buscarServico();
                    break;        
                case 5:
                    printf("\nOp 5");
                    exibirServico();
                    break;
                }
            } while (resp != 0);
            break;
        case 4:
            do{
                system("clear");
                sobre();
                printf("\n0 - para Sair: ");
                //printf("Escolha Uma das opções: ");
                scanf("%d", &resp);

            } while (resp != 0);
            break;
        case 3:
            do{
                menuBarbearia();
                printf("\n\nEscolha uma das opções: ");
                scanf("%d", &resp);
                switch (resp){
                case 1:
                    printf("\nOp 1");
                    selecionaCorte();
                    break;
                case 2:
                    printf("\nOp 2");
                    atualizarCorte(); 
                    break;
                case 3:
                    printf("\nOp 3");
                    listarRegistro();
                    break;
                case 4:
                    printf("\nOp 4");
                    buscarRegistro();
                    break;        

                }
            }while (resp != 0);
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
    printf("\n2 - Serviços");
    printf("\n3 - Barbearia");
    printf("\n4 - Sobre");
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


void menuServicos(){
    //system("clear");
    printf("\n######################################");
    printf("\n######################################");
    printf("\n####                              ####");
    printf("\n####           Serviços           ####");
    printf("\n####                              ####");
    printf("\n######################################");
    printf("\n######################################");

    printf("\n\n1 - Cadastrar Serviço");
    printf("\n2 - Atualizar Serviço");
    printf("\n3 - Excluir Serviço");
    printf("\n4 - Buscar Serviço");
    printf("\n5 - Listar Serviços");
    printf("\n0 - Sair\n\n");
}

void menuBarbearia(){
    //system("clear");
    printf("\n######################################");
    printf("\n######################################");
    printf("\n####                              ####");
    printf("\n####           Barbearia          ####");
    printf("\n####                              ####");
    printf("\n######################################");
    printf("\n######################################");

    printf("\n\n1 - Selecionar Corte");
    printf("\n2 - Atualizar Corte");
    printf("\n3 - Exibir Registro ");
    printf("\n4 - Buscar Registro");
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
    printf("= = = S G Control = = = \n");
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
    printf("= = = S G Control = = = \n");
    printf("= = Buscar Cadastro = = \n");
    printf("= = = = = = = = = = = = \n");
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

void cadastrarServico(void){
    Servico* servico;
    printf("\n\n");
    printf("= = = SGControl = = = \n");
    printf("= Cadastrar Serviço = \n");
    printf("= = = = = = = = = = = \n");
    servico = (Servico *)malloc(sizeof(Servico));

    printf("\nInforem o codigo do serviço: ");
    scanf(" %9[^\n]", servico->codigo);
    printf("\nInforem o nome do serviço: ");
    scanf(" %59[^\n]", servico->nomeServico);
    printf("\nInforem o preço do serviço: R$");
    scanf(" %f", &servico->preco);
    servico->statuServ = '1';
    printf("###############################\n");
    exibeServico(servico);
    printf("###############################\n");
    gravaServico(servico);
}

void exibeServico(Servico* servico){
    printf("\nCodigo: %s\n", servico->codigo);
    printf("Nome do produto: %s\n", servico->nomeServico);
    printf("Preço: R$%.2f", servico->preco);
    printf("\n");
}

void gravaServico(Servico* servico){
    FILE *fp;
    fp = fopen("servico.dat", "ab");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(servico, sizeof(Servico), 1, fp);
    fclose(fp);
}

void exibirServico(void){
    FILE* fp;
    Servico* servico;
    fp = fopen("servico.dat", "rb");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G control = = = \n");
    printf("= = Listar Serviços = = \n");
    printf("= = = = = = = = = = = \n");
    servico = (Servico *)malloc(sizeof(Servico));
    while (fread(servico, sizeof(Servico), 1, fp)){
        if (servico->statuServ == '1'){
            exibeServico(servico);
        }
    }
    fclose(fp);
    free(servico);
}

void buscarServico(void) {
    FILE* fp;
    Servico* servico;
    int achou;
    char procurado[10];
    fp = fopen("servico.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G Control = = = \n");
    printf("= = Buscar Serviço  = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o codigo do serviço a ser buscado: ");
    scanf(" %9[^\n]", procurado);

    servico = (Servico*) malloc(sizeof(Servico));
    achou = 0;
    while((!achou) && (fread(servico, sizeof(Servico), 1, fp))) {
        if ((strcmp(servico->codigo, procurado) == 0) && (servico->statuServ == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        exibeServico(servico);
    } else {
        printf("O codigo %s não foi encontrado...\n", procurado);
    }
    free(servico);
}

void excluirServico(void){
    FILE* fp;
    Servico* servico;
    int achou;
    char resp;
    char procurado[10];
    fp = fopen("servico.dat", "r+b");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G control = = = \n");
    printf("= = Apagar Serviço  = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o codigo do serviço a ser apagado (Apenas Numeros): ");
    scanf(" %9[^\n]", procurado);
    
    servico = (Servico *)malloc(sizeof(Servico));
    achou = 0;
    while ((!achou) && (fread(servico, sizeof(Servico), 1, fp))){
        if ((strcmp(servico->codigo, procurado) == 0) && (servico->statuServ == '1')){
            achou = 1;
        }
    }
    // fclose(fp); CORRIGIR ESTE ERRO AQUI
    if (achou){
        exibeServico(servico);
        getchar();
        printf("Deseja realmente apagar este serviço (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            servico->statuServ = '0';
            fseek(fp, (-1) * sizeof(Servico), SEEK_CUR);
            fwrite(servico, sizeof(Servico), 1, fp);
            printf("\nServiço excluído com sucesso!!!\n");
        }else{
            printf("\nOk, os dados não foram alterados\n");
        }
    }else{
        printf("O codigo %s não foi encontrado...\n", procurado);
    }
    free(servico);
    fclose(fp);
}

void atualizarServico(void) {
    FILE* fp;
    Servico* servico;
    int achou;
    char resp;
    char procurado[10];
    fp = fopen("servico.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G Control = = = \n");
    printf("= = Editar Serviço  = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o codigo do serviço a ser alterado (Apenas Numeros): ");
    scanf(" %11[^\n]", procurado);
    
    servico = (Servico*) malloc(sizeof(Servico));
    achou = 0;
    while((!achou) && (fread(servico, sizeof(Servico), 1, fp))) {
        if ((strcmp(servico->codigo, procurado) == 0) && (servico->statuServ == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeServico(servico);
        printf("\nInforem o codigo do serviço: ");
        scanf(" %9[^\n]", servico->codigo);
        printf("\nInforem o nome do serviço: ");
        scanf(" %59[^\n]", servico->nomeServico);
        printf("\nInforem o preço do serviço: R$");
        scanf(" %f", &servico->preco);
        servico->statuServ = '1';
        getchar();
        printf("Deseja realmente editar este serviço (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            fseek(fp, (-1)*sizeof(Servico), SEEK_CUR);
            fwrite(servico, sizeof(Servico), 1, fp);
            printf("\nServiço editado com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O codigo %s não foi encontrado...\n", procurado);
    }
    free(servico);
    fclose(fp);
}

void selecionaCorte(void){
    FILE* fp;
    Registro* registro;
    int x;
    fp = fopen("servico.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = =   S G Control   = = = \n");
    printf("= = Selecionar Serviço  = = \n");
    printf("= = = = = = = = = = = = = = \n");
    registro = (Registro*) malloc(sizeof(Registro));   

    exibirServico();

    printf("\nInforme o Nome do serviço: ");
    scanf(" %59[^\n]", registro->nomeReg);

    printf("\nInforme o Preço: R$");
    scanf("%f", &registro->precoServ);

    printf("\nInforme o Nome do cliente: ");
    scanf(" %149[^\n]", registro->nomeCli);

    printf("\nInforme o cpf do cliente: ");
    scanf(" %11[^\n]", registro->cpfCli);

    printf("\n1 - Pagar\n2 - Fiado");
    printf("\nDeseja pagar avista ou deixar fiado? ");
    scanf("%d", &x);

    if (x == 1){
        registro->statusReg = '1';
    } else {
        registro->statusReg = '0';
    }

    registro->statusAtiv = '1';
    printf("###############################\n");
    exibeRegistro(registro);
    printf("###############################\n");
    gravaRegistro(registro);
    fclose(fp);
    free(registro);
}

void atualizarCorte(void){
    FILE* fp;
    Registro* registro;
    int achou, x;
    char resp;
    char procurado[12];
    fp = fopen("registro.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = =  S G Control  = = = \n");
    printf("= = Editar Regisstro  = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o CPF que consta no registro (Apenas Numeros): ");
    scanf(" %11[^\n]", procurado);
    
    registro = (Registro*) malloc(sizeof(Registro));
    achou = 0;
    while((!achou) && (fread(registro, sizeof(Registro), 1, fp))) {
        if ((strcmp(registro->cpfCli, procurado) == 0)) {
            achou = 1;
        }
    }
    if (achou) {
        exibeRegistro(registro);
        
        printf("\nInforme o Nome do serviço: ");
        scanf(" %59[^\n]", registro->nomeReg);

        printf("\nInforme o Preço: R$");
        scanf("%f", &registro->precoServ);

        printf("\nInforme o Nome do cliente: ");
        scanf(" %149[^\n]", registro->nomeCli);

        printf("\nInforme o cpf do cliente: ");
        scanf(" %11[^\n]", registro->cpfCli);

        printf("\n1 - Pagar\n2 - Fiado");
        printf("\nDeseja pagar avista ou deixar fiado? ");
        scanf("%d", &x);

        if (x == 1){
            registro->statusReg = '1';
        } else {
            registro->statusReg = '0';
        }

        registro->statusAtiv = '1';
        getchar();
        printf("Deseja realmente editar este registro (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            fseek(fp, (-1)*sizeof(Registro), SEEK_CUR);
            fwrite(registro, sizeof(Registro), 1, fp);
            printf("\nregistro editado com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O cpf %s não foi encontrado...\n", procurado);
    }
    free(registro);
    fclose(fp);
}


void listarRegistro(void){
    FILE* fp;
    Registro* registro;
    fp = fopen("registro.dat", "rb");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G control = = = \n");
    printf("= = Exibir registros = = \n");
    printf("= = = = = = = = = = = \n");
    registro = (Registro*)malloc(sizeof(Registro));
    while (fread(registro, sizeof(Registro), 1, fp)){
        if (registro->statusAtiv == '1'){
            exibeRegistro(registro);        
        }
    }
    fclose(fp);
    free(registro);
}

void buscarRegistro(void){
    FILE* fp;
    Registro* registro;
    int achou;
    char procurado[12];
    fp = fopen("registro.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = S G Control  = = = \n");
    printf("= = Buscar Registro  = = \n");
    printf("= = = = = = = = = = = \n");
    printf("Informe o CPF do cliente: ");
    scanf(" %11[^\n]", procurado);

    registro = (Registro*) malloc(sizeof(Registro));
    achou = 0;
    while((fread(registro, sizeof(Registro), 1, fp))) {
        if ((strcmp(registro->cpfCli, procurado) == 0)) {
            exibeRegistro(registro);
            achou = 1;
        }
    }
    if (achou == 0){
        printf("O cpf %s não foi encontrado nos registros...", procurado);
    }
    fclose(fp);
    free(registro);
}

void excluiRegistro(void){

}

void exibeRegistro(Registro* registro){
    printf("\nNome do Servico: %s", registro->nomeReg);
    printf("\nNome do Cliente: %s", registro->nomeCli);
    printf("\nCPF: %s", registro->cpfCli);
    printf("\nPreço: R$%.2f", registro->precoServ);
    if (registro->statusReg == '1'){
        printf("\nEstatus do Serviço: Pago");
    } else{
        printf("\nEstatus do Serviço: Fiado");
    }
    printf("\n");
}
void gravaRegistro(Registro* registro){
    FILE *fp;
    fp = fopen("registro.dat", "ab");
    if (fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(registro, sizeof(Registro), 1, fp);
    fclose(fp);
}



