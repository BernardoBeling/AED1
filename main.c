#include <stdio.h>
#include <stdlib.h>

//buffer-> [cont|i|scan|..........]

struct pessoa{
    char nome[30];
    int idade,tel;
};

void apontaini(int* cont, int* i,int* scan){
    cont=buffer;
    i=cont+1;
    scan=i+1;
}

void main()
{
    void *buffer;
    int *cont,*i,*scan;
    pessoa *p;

    buffer=malloc(sizeof(int)*3);
    apontaini(cont,i,buffer);

    printf("1.Adicionar Pessoa\n2.Remover\n3.Mostrar\n");
    scanf("%d",scan);
    switch{
    case 1:
        cont++;
        buffer=realloc(buffer,sizeof(int)*3+sizeof(pessoa)*cont);
    }
}
