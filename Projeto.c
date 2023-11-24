#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct endeco
{
    char rua[100],bairro[100],cidade[100],estado[100],cep[20],numero[10];
}Tend;
typedef struct empresa
{
    char nomeEmpresa[255],dadosRespoel[255],cnpj[100],razaoSocial[255],nomeFantasia[100],
    telefone[100],email[20],dataAbertura[10];
    Tend endeco;
}Temp;

typedef struct usuario
{
    char nomeUser[100],senha[21];
    Temp empresa;
    struct usuario *prox;
}Tuser;

void insereElemento(Tuser **h){
    Tuser *novo,*antes,*atual;

    antes=atual=(*h);

    novo = malloc(sizeof(Tuser));
    printf("digite o nome do usuario\n");
    scanf("%[^\n]",novo->nomeUser);
    printf("digite uma senha ate 20 dígitos\n");
    scanf("%s",novo->senha);
    printf("digite o nome da empresa\n");
    scanf("%[^\n]",novo->empresa.nomeEmpresa);
    

    if (!(*h))
    {
        (*h)=novo;
        return;
    }
    
}

int main (){
    char nome[100];
    int opcao=1;
    Tuser *head=NULL;

    while (opcao)
    {
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            insereElemento(&head);
            break;
        
        default:
            break;
        }
    }
}