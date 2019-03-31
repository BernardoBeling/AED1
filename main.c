#include <stdio.h>
#include <stdlib.h>

//buffer-> [menu|i|contstruct|..........]

struct pessoa
{
    char *nome;
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
    //printf("Digite o nome:");
    //scanf("%[^\n]s",p->nome);
    //fgets(&p->nome,30,stdin);
    printf("Digite a idade:");
    scanf("%d",&p->idade);
    printf("Digite a matricula:");
    scanf("%d",&p->matricula);
}

void main()
{
    void *buffer;
    int *menu, *i, *contstruct;
    struct pessoa *p;

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
                    for(*i=0;*i<*contstruct-*i;*i=*i+1)
                        p=p+1;   
                    adiciona(p);
                }
                printf("Registro adicionado!\n");
                p=contstruct+1;
                break;

            case 2:
                printf("Entrou no 2\n");
                break;

            case 3:
                printf("Entrou no 3\n");
                break;

            default:
                printf("Comando invalido!\n");
                break;
        }
    } while(*menu!=4);
}