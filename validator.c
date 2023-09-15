#include <stdio.h>
#include <string.h> 
#include <stdlib.h> // Uso desse blibioteca para alocação
#define max_lenght 255


char* pergunta_name() {
    char* response = (char*)malloc(sizeof(char) * max_lenght + 1); 
    /*Nesse comando acima eu estou, declarando um variavel char com um nome response, o (char*) indique que eu preciso que o malloc retorne um ponteiro char*, poís o padrão e que
    retorne um void, eu abro uma função chamado malloc e dou um limite usado sizeof(), uso o char como primeiro valor, o valor de um char e 1byte, coloco que o limite de tamanho é
    char * 256, que seria o mesmo de 1 * 256, lembrando que o maximo de bytes é 256 bytes.)*/

    if(response == NULL) {
        printf("Erro na alocacao de memoria!!");
        exit(1); // o exit(1) faz com que o programa feche na mesma hora.
    };

    printf("Digite o seu nome: ");
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

int main() {
    
    char* t = pergunta_name();
  
    
    for(int i = 0; t[i] != '\0'; i++){

        if(t[i] == '0' || t[i] == '1'|| t[i] == '2'|| t[i] == '3' || t[i] == '4'|| t[i] == '5'|| t[i] == '6'|| t[i] == '7'|| t[i] == '8'|| t[i] == '9') {
            printf("Nome Invalido!, numero %c foi digitado.\n",t[i]);
            exit(1);     
        };
        
    };

      printf("Nome: %s\n", t);
      free(t); // Esse comando libera a mémoria alocada.

    return 0;
}