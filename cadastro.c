#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca de strings
#include <errno.h>
#include <ctype.h>
#include <time.h>

#define max_lenght 255

char *input_respons()
{

    char *response = (char *)malloc(sizeof(char) * max_lenght + 1);
    /*Nesse comando acima eu estou, declarando um variavel char com um nome response, o (char*) indique que eu preciso que o malloc retorne um ponteiro char*, poís o padrão e que
    retorne um void, eu abro uma função chamado malloc e dou um limite usado sizeof(), uso o char como primeiro valor, o valor de um char e 1byte, coloco que o limite de tamanho é
    char * 256, que seria o mesmo de 1 * 256, lembrando que o maximo de bytes é 256 bytes.)*/

    if (response == NULL)
    {
        printf("Erro na alocacao de memoria!!");
        exit(1); // o exit(1) faz com que o programa feche na mesma hora.
    };

    fgets(response, max_lenght + 1, stdin);
    /*fgets é um comando que pega dados, como o scanf, mais a diferença do fgets é que ele lê os dados colocados nele, no comando acima coloco que o valor digitado deve ser armazenado
    no ponteiro char chamando response, no segundo parametro coloco o máximo de caracteres que devem ser lido, o max_lenght e uma constante com o valor de 255, a conta será 255 + 1
    lembrando que o máximo de caracter de um char e´256 bytes, o stdin é colocado para falar que a entrada é uma entrada padrao de teclado ou arquivo*/

    size_t length = strlen(response);
    if (length > 0 && response[length - 1] == '\n')
    {
        response[length - 1] = '\0';
    }
    /*size_t - verifica o valor em bytes, strlen() server para ver o comprimento em bytes*/

    return response;
};

int validacao(const char *val)
{

    for (int i = 0; val[i] != '\0'; i++)
    {

        if (isdigit(val[i]))
        {
            printf("Nome Invalido!, numero %c foi digitado.\nTente novamente! ", val[i]);
            exit(1);
        }
    }
    return 0;
};

int year_validator(int year)
{

    if (year < 1000 || year > 9999)
    {
        printf("Data Invalida, tentar novamente!");
        exit(1);
    };
    time_t t;
    struct tm *info;
    time(&t);

    info = localtime(&t);

    int year_atual = info->tm_year + 1900;

    int idadeCont = year_atual - year;

    return idadeCont;
};

int validador_email(const char *email)
{
    int count_at = 0, count_dot = 0;

     for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            count_at++;
        }
        else if (email[i] == '.')
        {
            count_dot++;
        }
    }

    if (count_at != 1 || count_dot < 1)
    {
        printf("E-mail inválido!\n");
        exit(1);
    }
    return 0;
};

char *pergunta_email()
{
    printf("\nDigite o seu E-mail: ");
    char *input_email = input_respons();
    validador_email(input_email);
    return input_email;
};

char *pergunta_end()
{
    printf("Digite o seu endereço ( nao e necessario colocar numero da casa nessa validacao ) : ");
    char *input = input_respons();
    validacao(input);
    return input;
};

char *pergunta_name()
{

    printf("Digite o seu nome: ");
    char *input_name = input_respons();
    validacao(input_name);
    return input_name;
};

int int_validator(int tel)
{
  if (tel < 100000000 || tel > 999999999)
    {
        printf("Número de telefone inválido!\n");
        exit(1);
    }

    return tel;
};

struct list
{
    char nome[100], email[50], endereco[70];
    int idade, status, dependente, sex, num_casa, tel;
    float altura;
};

int main()
{

    struct list cadastro;
    char *nome_save = pergunta_name();

    strncpy(cadastro.nome, nome_save, sizeof(cadastro.nome));
    printf("Nome Cadastrado: %s\n", nome_save);

    free(nome_save); // Esse comando libera a mémoria alocada.

    printf("\nDigite o ano do seu nascimento: ");

    int dig_year;

    scanf("%d", &dig_year);

    int idadeCont = year_validator(dig_year);
    cadastro.idade = idadeCont;
    printf("Idade Cadastrada! %d \n", cadastro.idade);

    printf("digite o seu telefone: ");
    int phone;
    scanf("%d", &phone);
    int_validator(phone);
    cadastro.tel = phone;

    printf("Número Cadastrado! %d \n", cadastro.tel);

    while (getchar() != '\n');

    char *email_save = pergunta_email();
    strncpy(cadastro.email, email_save, sizeof(cadastro.email));
    printf("Email Cadastrado! %s", cadastro.email);

    free(email_save);

    char *endereco_save = pergunta_end();
    strncpy(cadastro.endereco, endereco_save, sizeof(cadastro.endereco));
    printf("Endereco cadastrado! %s", cadastro.endereco);



    return 0;
}