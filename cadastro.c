#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca de strings
#include <errno.h>
#include <ctype.h>

#define max_lenght 255

char* input_respons() {

    char* response = (char*)malloc(sizeof(char) * max_lenght + 1); 
    /*Nesse comando acima eu estou, declarando um variavel char com um nome response, o (char*) indique que eu preciso que o malloc retorne um ponteiro char*, poís o padrão e que
    retorne um void, eu abro uma função chamado malloc e dou um limite usado sizeof(), uso o char como primeiro valor, o valor de um char e 1byte, coloco que o limite de tamanho é
    char * 256, que seria o mesmo de 1 * 256, lembrando que o maximo de bytes é 256 bytes.)*/

    if(response == NULL) {
        printf("Erro na alocacao de memoria!!");
        exit(1); // o exit(1) faz com que o programa feche na mesma hora.
    };

     fgets(response,max_lenght + 1, stdin); 
    /*fgets é um comando que pega dados, como o scanf, mais a diferença do fgets é que ele lê os dados colocados nele, no comando acima coloco que o valor digitado deve ser armazenado
    no ponteiro char chamando response, no segundo parametro coloco o máximo de caracteres que devem ser lido, o max_lenght e uma constante com o valor de 255, a conta será 255 + 1
    lembrando que o máximo de caracter de um char e´256 bytes, o stdin é colocado para falar que a entrada é uma entrada padrao de teclado ou arquivo*/

    size_t length = strlen(response);
    if (length > 0 && response[length - 1] == '\n') {
        response[length - 1] = '\0';
    }
    /*size_t - verifica o valor em bytes, strlen() server para ver o comprimento em bytes*/

    return response;
};

int validacao_nome(const char* val) {
    
    for(int i = 0; val[i] != '\0'; i++) {

        if(isdigit(val[i])) {
            printf("Nome Invalido!, numero %c foi digitado.\nTente novamente! ",val[i]);
            exit(1);     
        }
    }
    return 0;
};

int year_validator(int year) {

    if(year < 1000 || year > 9999) {
        printf("Data Invalida, tentar novamente!");
        exit(1);
    };
};

char* pergunta_name() {
   
    printf("Digite o seu nome: ");
    char* input_name = input_respons();
    validacao_nome(input_name);
    return input_name;
};

struct list {
        char nome[100], bairro[20], endereco[70], tel[13];
        int ano_nascimento, status, dependente,sex,num_casa;      
        float altura;  
    };

int main() {

    struct list cadastro;
    char* nome_save = pergunta_name();
  
    strncpy(cadastro.nome, nome_save ,sizeof(cadastro.nome));
    printf("Nome Cadastrado: %s\n", nome_save);

    free(nome_save); // Esse comando libera a mémoria alocada.

    printf("\nDigite o ano do seu nascimento: ");
      
    int dig_year;

    scanf("%d",&dig_year);

    year_validator(dig_year);

    return 0;
}