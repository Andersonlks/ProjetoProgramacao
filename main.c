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

void menuPrincipal();
void menuCliente();
void cadastrarCliente();
void atualizarCadastro();
void exibirCadastros();
void excluirCadastro();
void sobre();

void exibeCliente(Cliente* cliente);
void gravaCliente(Cliente* cliente);

int verificaNome(char x[]); 
int validaLetra(char c);
int validaCpf(char x[]);
int validaRg(char x[]);
int validaNumero(char x);
int bissexto(int);
int dataValida(int, int , int);

int main(void){
    int resp;
    int op;
    
    do {
        menuPrincipal();
        printf("\n\nEscolha Umas das opções: ");
        scanf("%d", &op);
    
        switch (op){
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
                            
                        break;
                    } 
            
                    menuCliente();
                    printf("\n\nInforme a opção desejada: ");
                    scanf("%d", &resp);
                    getchar();
                }while (resp != 0);
            break;
            case 2:
                do{
                    system("clear");
                    printf("\nCOMERCIO");
                    printf("\n\n---------------");
                    printf("\n\nParte em desenvolvimento...");
                    printf("\n\n0 - sair: ");
                    scanf("%d", &resp);

                }while(resp!=0);
            break;
            case 3:
                do{
                    system("clear");
                    sobre();
                    printf("\n0 - para Sair: ");
                    //printf("Escolha Uma das opções: ");
                    scanf("%d", &resp);

                } while(resp!=0);
            break;
        }
    } while (op!=0);
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
    printf("\n2 - comercio");
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
    printf("\n5 - Sobre?");
    printf("\n0 - Sair\n\n");

}

void cadastrarCliente(void) {
    Cliente* cliente;
    printf("\n\n");
    printf("= = = SGControl = = = \n");
    printf("= Cadastrar Cliente  = \n");
    printf("= = = = = = = = = = = \n");
    cliente = (Cliente*) malloc(sizeof(Cliente));

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

void atualizarCadastro(){
    Cliente cl;
    int resp, op, confirma;
    char cpf[11];
    
    do{
        system("clear");
        printf("ATUALIZAR CADASTRO DE CLIENTES");
        printf("\n\n----------------------------------");
        printf("\n\nInforem o CPF do cliente (Apenas Numeros): ");
        scanf("%s", cpf);

        while (validaCpf(cpf)){
            printf("Inforem um CPF valido (Apenas Numeros): ");
            scanf("%s", cpf);
        }    
        printf("\n\n1 - Nome\n2 - CPF\n3 - RG\n4 - Data de Nascimento\n5 - Renda");
        printf("\n\nEscolha uma das opções de atualização: ");
        scanf("%d", &op);
        getchar();
        switch (op){
            case 1:
                printf("\nNome: ");
                fgets(cl.nome, sizeof(cl.nome), stdin);
                while (!verificaNome(cl.nome)){
                    printf("\nInforme um nome valido: ");
                    fgets(cl.nome, sizeof(cl.nome), stdin);
                    
                }
            break;
            case 2:   
                printf("CPF (Apenas Numeros): ");
                scanf("%s", cl.cpf);
                while (validaCpf(cl.cpf)){
                    printf("Inforem um CPF valido (Apenas Numeros): ");
                    scanf("%s", cl.cpf);
                }
            break;
            case 3: 
                printf("Bull");
            break;
            case 4:
                printf("Data de Nascimento (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &cl.dataNasc[0], &cl.dataNasc[1], &cl.dataNasc[2]);
                
                while (!dataValida(cl.dataNasc[0], cl.dataNasc[1], cl.dataNasc[2])){
                    printf("Informe uma Data de Nascimento valida (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &cl.dataNasc[0], &cl.dataNasc[1], &cl.dataNasc[2]);
                }
            break;
            case 5: 
                //printf("Emai-l: ");
                //fgets(email, sizeof(email), stdin);
                printf("Renda: R$");
                scanf("%f", &cl.renda);
            break;
        }
        printf("\n\nConfirmação...\n\n1 - confirmar\n0 - Cancelar");
        printf("\nEscolha uma das opções: ");
        scanf("%d", &confirma);

        if (confirma == 1){
            printf("\n\nAlteração efetuada com sucesso!");
        } else{
            printf("\n\nOperação cancelada!");
        }    
        printf("\n\n1 - Atualizar um novo campo\n0 - Sair");
        printf("\nEscolha uma das opções: ");
        scanf("%d", &resp); 

    } while(resp!=0);
    
}

void excluirCadastro(){
    int confirma, resp;
    char cpf[11];   
    do{
         system("clear");
        printf("EXCLUIR CADASTROS");
        printf("\n\n-----------------------");
        
        printf("\n\nInforem o CPF do cliente a ser excluido: ");
        scanf("%s", cpf);
        while (validaCpf(cpf)){
            printf("Inforem um CPF valido (Apenas Numeros): ");
            scanf("%s", cpf);
        }

        printf("\n\nConfirmação...\n\n1 - confirmar\n0 - Cancelar");
        printf("\nEscolha uma das opções: ");
        scanf("%d", &confirma);

        if (confirma == 1){
            printf("\n\ncliente excluido com sucesso!");
        } else{
            printf("\n\nOperação cancelada!");
        }
        printf("\n\n1 - Excluir outro cadastro\n0 - Sair");
        printf("\nEscolha uma das opções: ");
        scanf("%d", &resp);
    } while(resp!=0);    
    
}
void sobre(){
    printf("\nINFORMAÇÕES SOBRE O DESENVOLVEDOR DO SINTEMA");
    printf("\n\n--------------------------------------------------");
    printf("\n\nSistema desenvolvido por Anderson Lucas da Costa Galdino\nEmai-l: andersoncosta.ob@gmail.com\nTelefone: (84) 9 86078267\nConta do Github: https://github.com/Andersonlks\n\n");
}

int verificaNome(char x[]) { 
  int tam;
  tam = strlen(x)-1;
  for (int i = 0; i < tam; i++) {
    if (!validaLetra(x[i])) {
      return 0;
    }
  }
  return 1;
}

int validaLetra(char c) {
  if (c>='A' && c<='Z') {
    return 1;
  }
  else if (c>='a' && c<='z') { 
    return 1;
  }
  else if (c == ' ') {
    return 1;
  }
  else {
    return 0;
  }
}

int validaCpf(char x[]){
    int tam;
    int cont = 0;
    tam = strlen(x);
    for (int i = 0; i < tam; i++){
        cont +=1;
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
        cont +=1;
        if (!validaNumero(x[i])){
            return 1;
        }
    }
    if (cont != 9){
        return 1;
  
    } 
    return 0;
}

int validaNumero(char x){
    if (x>='0' && x<='9'){
        return 1;
    }
    return 0;
}

int bissexto(int aa) {
    if ((aa % 4 == 0) && (aa % 100 != 0)) {
        return 1;
    } else if (aa % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}    

int dataValida(int dd, int mm, int aa) {
    int maiorDia;
    if (aa < 0 || mm < 1 || mm > 12)
        return 0;

    if (mm == 2) {
        if (bissexto(aa)){
            maiorDia = 29;
        } else {
            maiorDia = 28;
        }    
    } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        maiorDia = 30;    
    } else {
        maiorDia = 31;
    }                
    if (dd < 1 || dd > maiorDia){
        return 0;
    } else if (mm < 1 || mm > 12){
        return 0;
    }
    return 1;
}


void exibirCadastros(void) {
  FILE* fp;
  Cliente* cliente;
  fp = fopen("cliente.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = S G control = = = \n");
  printf("= = Exibe Clientes = = \n");
  printf("= = = = = = = = = = = \n");
  cliente = (Cliente*) malloc(sizeof(Cliente));
  while(fread(cliente, sizeof(Cliente), 1, fp)) {
    if (cliente->status == '1') {
      exibeCliente(cliente);
    }
  }
  fclose(fp);
  free(cliente);
}

void gravaCliente(Cliente* cliente) {
  FILE* fp;
  fp = fopen("cliente.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(cliente, sizeof(Cliente), 1, fp);
  fclose(fp);
}


void exibeCliente(Cliente* cliente) {
  printf("Nome: %s\n", cliente->nome);
  printf("CPF: %s\n", cliente->cpf);
  printf("Nascimento: %02d/%02d/%04d\n", cliente->dataNasc[0], cliente->dataNasc[1], cliente->dataNasc[2]);
  printf("Renda: R$%.2f\n", cliente->renda);
  printf("\n");


}

