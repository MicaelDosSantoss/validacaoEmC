#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca de strings
#include <errno.h>


struct list {
        char nome[100], bairro[20], endereco[70], tel[13];
        int ano_nascimento, status, dependente,sex,num_casa;      
        float altura;  
    };

int main() {

    struct list cadastro;
    char n[100];
    printf("Digite o seu nome:");
    scanf("%s", n);

    strncpy(cadastro.nome, n ,sizeof(cadastro.nome));
    printf("\nNome: %s \n",cadastro.nome);


    return 0;
}