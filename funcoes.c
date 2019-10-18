#include <string.h>
#include <stdlib.h>

int validaNumero(char x){
    if (x>='0' && x<='9'){
        return 1;
    }
    return 0;
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