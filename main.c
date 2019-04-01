#include <stdio.h>
#include <stdlib.h>

//buffer-> [menu|i|contstruct|..........]

struct pessoa
{
    char nome[30];
    int idade,matricula;
};

void* aponta(void** buffer, int** menu, int** i, int** contstruct)
{
    *menu=*buffer;
    *i=*menu+1;
    *contstruct=*i+1;
}

void adiciona(struct pessoa* p)
{
    printf("Digite o nome:");
    scanf("%s",&p->nome);
    printf("Digite a idade:");
    scanf("%d",&p->idade);
    printf("Digite a matricula:");
    scanf("%d",&p->matricula);
}

void main()
{
    void *buffer;
    int *menu, *i, *contstruct;
    struct pessoa *p,*p1,*p2;

    buffer=malloc(sizeof(int)*3);
    aponta(&buffer,&menu,&i,&contstruct);
    *contstruct=0;
    do
    {
        printf("1.Adicionar Pessoa\n2.Remover\n3.Mostrar\n4.Sair\n"); 
        scanf("%d",menu);
    
        switch(*menu)
        {
            case 1:
                *contstruct=*contstruct+1;
                buffer=realloc(buffer,(sizeof(int)*3+sizeof(struct pessoa)*(*contstruct)));
                aponta(&buffer,&menu,&i,&contstruct);
                p=contstruct+1;
                if(*contstruct==1)
                    adiciona(p);
                else
                {
                    //funcionando
                    for(*i=1;*i<*contstruct;*i=*i+1)
                        p=p+1;   
                    adiciona(p);
                }
                printf("Registro adicionado!\n\n");
                p=contstruct+1;
                break;

            case 2:
                printf("Digite o indice da pessoa a remover:");
                scanf("%d",menu);
                if(*menu==*contstruct)
                {
                    *contstruct=*contstruct-1;
                    buffer=realloc(buffer,(sizeof(int)*3+sizeof(struct pessoa)*(*contstruct)));
                }
                p1=p;
                for(*i=1;*i<*menu;*i=*i+1)
                    p1=p1+1;
                p2=p1+1;
                for(*i=1;*i<=(*contstruct-*menu);*i=*i+1)
                {
                    strcpy(p1->nome,p2->nome);
                    p1->idade=p2->idade;
                    p1->matricula=p2->matricula;
                    p1=p1+1;
                    p2=p2+1;
                }
                *contstruct=*contstruct-1;
                buffer=realloc(buffer,(sizeof(int)*3+sizeof(struct pessoa)*(*contstruct)));
                *menu=0;
                break;

            case 3:
                if(*contstruct==0) 
                    printf("Agenda vazia.\n");
                else
                {
                    p=contstruct+1; //garantindo que o P vai estar apontado para o inicio
                    for(*i=1;*i<=*contstruct;*i=*i+1)
                    {
                        printf("==== Pessoa %d ====\n",*i);
                        printf("Nome: %s\n",p->nome);
                        printf("Idade: %d\n",p->idade);
                        printf("Matricula: %d\n",p->matricula);
                        p=p+1;
                    }
                    p=contstruct+1; //reapontando o P para o inicio
                }
                printf("\n");
                break;

            default:
                printf("Comando invalido!\n");
                break;
        }
    } while(*menu!=4);
}