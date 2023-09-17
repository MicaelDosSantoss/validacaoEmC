#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca de strings
#include <errno.h>

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

    int length_res = strlen(response);
    printf("Lenght: %d \n",length_res);

    return response;

};


char* pergunta_name() {
   
    printf("Digite o seu nome: ");
    char* input_name = input_respons();
    return input_name;
};

struct list {
        char nome[100], bairro[20], endereco[70], tel[13];
        int ano_nascimento, status, dependente,sex,num_casa;      
        float altura;  
    };

int main() {

    struct list cadastro;
    char* t = pergunta_name();
  
    
    for(int i = 0; t[i] != '\0'; i++){

        if(t[i] == '0' || t[i] == '1'|| t[i] == '2'|| t[i] == '3' || t[i] == '4'|| t[i] == '5'|| t[i] == '6'|| t[i] == '7'|| t[i] == '8'|| t[i] == '9') {
            printf("Nome Invalido!, numero %c foi digitado.\n",t[i]);
            exit(1);     
        };
        
    };
      strncpy(cadastro.nome, t ,sizeof(cadastro.nome));
      printf("Nome Cadastrado: %s\n", t);
      free(t); // Esse comando libera a mémoria alocada.

    
    // char n[100];
    // printf("Digite o seu nome:");
    // scanf("%s", n);

   
    // printf("\nNome: %s \n",cadastro.nome);


    return 0;
}