#!/bin/bash

function pause(){
    read -p "$*"
}

gcc -c -Wall main.c funcoes.c
gcc -o main main.o funcoes.o

pause "Aperte [Enter] para continuar..."

./main