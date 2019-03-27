#include <stdio.h>
#include <stdlib.h>

//buffer-> [cont|i|scan|..........]

struct pessoa{
    char nome[30];
    int idade,tel;
};

void apontaini(void* buffer,int* cont, int* i,int* scan){
    cont=buffer;
    i=cont+1;
    scan=i+1;
    printf("Entrouaponta\n");
}

void main()
{
    void *buffer;
    int *cont,*i,*num;
    //struct pessoa *p;

    buffer=malloc(sizeof(int)*3);
    apontaini(buffer,cont,i,num);

    printf("1.Adicionar Pessoa\n2.Remover\n3.Mostrar\n");
    scanf("%d",num);

    switch(*num)
    {
        case 1:
            printf("Entrou\n");
            cont++;
            buffer=realloc(buffer,sizeof(int)*3+(*cont*sizeof(struct pessoa)));
            break;
    }
}
