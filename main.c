#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//buffer-> [menu|i|j|contstruct|pessoas...]

struct pessoa
{
    char nome[30];
    int idade,matricula;
};

void* aponta(void** buffer, int** menu, int** i, int** j, int** contstruct)
{
    *menu=*buffer;
    *i=*menu+1;
    *j=*i+1;
    *contstruct=*j+1;
}

void adiciona(struct pessoa* p)
{
    printf("Digite o nome:");
    scanf("%s",p->nome);
    printf("Digite a idade:");
    scanf("%d",&p->idade);
    printf("Digite a matricula:");
    scanf("%d",&p->matricula);
}

void mostra(int* contstruct, int* i, struct pessoa* p)
{
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
}

void delete(void* buffer,int* menu, int* i, int* contstruct, struct pessoa* p, struct pessoa* p1, struct pessoa* p2)
{
       if (*contstruct == 0)
                    printf("Nao ha contatos para remover.\n");
                else
                {               
                    printf("Digite o indice da pessoa a remover:");
                    scanf("%d",menu);
                    if(*contstruct==1)
                    {
                        *contstruct=*contstruct-1;
                        buffer=realloc(buffer,(sizeof(int)*4+sizeof(struct pessoa)*(*contstruct)));
                    }
                    else
                    {              
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
                        buffer=realloc(buffer,(sizeof(int)*4+sizeof(struct pessoa)*(*contstruct)));
                    }
                }
                *menu=0;
}

void search(void* buffer, int* menu, int* i,int* j, int* contstruct, struct pessoa* p, struct pessoa* p1)
{
    buffer=realloc(buffer,sizeof(int)*4+(*contstruct+1)*sizeof(struct pessoa));
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    p1=p;
    for(*i=1;*i<=*contstruct;*i=*i+1)
        p1=p1+1;
    printf("Nome da pessoa: ");
    scanf("%s",p1->nome);
    for(*i=1;*i<=*contstruct;*i=*i+1)
    {
        if(strcmp(p->nome, p1->nome)== 0)
        {
            printf("\n---DADOS---\n");
            printf("Nome: %s\n",p->nome);
            printf("Idade: %d\n",p->idade);
            printf("Matricula: %d\n", p->matricula);
        }
        else
        {
            if(*i==*contstruct)
                printf("Nao ha registro dessa pessoa!\n");
        }
        p=p+1;
    }
    buffer=realloc(buffer,sizeof(int)*4+(*contstruct)*sizeof(struct pessoa));
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    printf("\n");
}

void selectSortById(void* buffer,int* menu,int* i,int* j,int* contstruct,struct pessoa* p,struct pessoa* p1, struct pessoa* p2)
{
    buffer=realloc(buffer,sizeof(int)*4 + sizeof(struct pessoa)*(*contstruct)+1);
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    p1=p;
    p2=p1+1;
    
    for(*i=0;*i<contstruct;*i=*i+1)
    {
        for(*j=*i+1;*j<*contstruct;*j=*j+1)
        {
            if(p2->idade < p1->idade)
            {
                p=p2; //aponta o p pro menor
                *menu=1;
            }
            p2=p2+1;
        }
            if(*menu==1)
            {
                p2=contstruct+(sizeof(struct pessoa)*(*contstruct)+1); //aponta o p2 pra struct temp
                *(p2)=*(p1);               
                *(p1)=*(p);              
                *(p)=*(p2);
                *menu=0;
            }
        p1=p1+1;
        p=contstruct+1;
        p2=p1+1;        
    }
    buffer=realloc(buffer,sizeof(int)*4 + sizeof(struct pessoa)*(*contstruct));
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    *menu=0;
}

<<<<<<< HEAD
void quickSortByAge(void* buffer,int* menu,int* i,int* j,int* contstruct,struct pessoa* p,struct pessoa* p1, struct pessoa* p2)
{
    buffer=realloc(buffer,sizeof(int)*4+sizeof(struct pessoa)*(*contstruct)+1);
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    p1=p;
    p2=p1;
    for(*i=0;*i<*contstruct;*i=*i+1)
        p2+=1;  //leva o p2 p/ a ultima pessoa e salva o indice do pivo no i
    p1+=*i/2; //leva o p1 pro meio (pivo)
    while(*i<=*j)
    {
        for(;p->idade < p1->idade;p+=1); //leva o p pra um valor maior que o pivo
        for(*j=*contstruct;p2->idade > p1->idade;p2+=1 && *j=*j-1); //leva o p2 pra um valor menor que o pivo
        for(*menu=*i;*menu<*contstruct+1;*menu=*menu+1)
            p1+=1;  //leva o p1 pra TEMP
        *(p1)=*(p2);
        *(p2)=*(p);
        *(p)=*(p1);
        p1=(contstruct+1)+*i/2; //reaponta o i pra pos pivo

    }
    
=======
void sortByAge(void* buffer,int* menu,int* i,int* j,int* contstruct,struct pessoa* p,struct pessoa* p1, struct pessoa* p2)
{
    buffer=realloc(buffer,(sizeof(int)*4+sizeof(struct pessoa)*(*contstruct+1)));
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    p1=p;
    p2=p1+1;
    for(*i=1;*i<=*contstruct;*i=*i+1)
    {
        for(*j=*i;*j<=*contstruct;*j=*j+1)
        {
            if(p1->idade > p2->idade)
            {
                for(*menu=*j+1;*menu<=*contstruct;*menu=*menu+1) //faz o p2 ir pra nova posicao alocada (temp)
                    p2=p2+1;
                *(p2)=*(p1);
                p2=p+*j;    //re aponta o p2 pra dps do p1
                *(p1)=*(p2);
                for(*menu=*i;*menu<=*contstruct;*menu=*menu+1) //faz o p1 ir pra temp
                    p1=p1+1;
                *(p2)=*(p1);
                p1=p+(*i-1);    //re aponta o p1 pra onde estava
            }
            p2=p2+1;
        }
        p1=p1+1;
        p2=p1+1;
    }
    buffer=realloc(buffer,(sizeof(int)*4+sizeof(struct pessoa)*(*contstruct)));
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    *menu=0;
>>>>>>> 07ed634a9c090995d1e25ac96e06eaf265ea62eb
}

void sortByName(void* buffer,int* menu,int* i,int* j,int* contstruct,struct pessoa* p,struct pessoa* p1, struct pessoa* p2)
{
    buffer=realloc(buffer,(sizeof(int)*4+sizeof(struct pessoa)*(*contstruct+1)));
    aponta(&buffer,&menu,&i,&j,&contstruct);
    p=contstruct+1;
    p1=p;
    p2=p1+1;
    for(*i=1;*i<=*contstruct;*i=*i+1)
    {
        for(*j=*i;*j<=*contstruct;*j=*j+1)
        {
            if(strcmp(p1->nome,p2->nome)>0)
            {
                for(*menu=*j+1;*menu<=*contstruct;*menu=*menu+1) //faz o p2 ir pra nova posicao alocada (temp)
                    p2=p2+1;
                *(p2)=*(p1);
                p2=p+*j;    //re aponta o p2 pra dps do p1
                *(p1)=*(p2);
                for(*menu=*i;*menu<=*contstruct;*menu=*menu+1) //faz o p1 ir pra temp
                    p1=p1+1;
                *(p2)=*(p1);
                p1=p+(*i-1);    //re aponta o p1 pro inicio
            }
            p2=p2+1;
        }
        p1=p1+1;
        p2=p1+1;
    }
    buffer=realloc(buffer,(sizeof(int)*4+sizeof(struct pessoa)*(*contstruct)));
    aponta(&buffer,&menu,&i,&j,&contstruct);
    *menu=0;
}

void main()
{
    void *buffer;
    int *menu, *i, *j, *contstruct;
    struct pessoa *p,*p1,*p2;

    buffer=malloc(sizeof(int)*4);
    aponta(&buffer,&menu,&i,&j,&contstruct);
    *contstruct=0;
    do
    {
        printf("1.Adicionar Pessoa\n2.Remover\n3.Mostrar\n4.Sair\n---ADICIONAIS---\n5.Buscar por nome\n6.Ordenar por nome\n7.Ordenar por Matricula\n8.Ordenar por Idade\n"); 
        scanf("%d",menu);
    
        switch(*menu)
        {
            case 1:
                *contstruct=*contstruct+1;
                buffer=realloc(buffer,(sizeof(int)*4+sizeof(struct pessoa)*(*contstruct)));
                aponta(&buffer,&menu,&i,&j,&contstruct);
                p=contstruct+1;
                if(*contstruct==1)
                    adiciona(p);
                else
                {
                    for(*i=1;*i<*contstruct;*i=*i+1)
                        p=p+1;   
                    adiciona(p);
                }
                printf("Registro adicionado!\n\n");
                p=contstruct+1;
            break;

            case 2:
                delete(buffer,menu,i,contstruct,p,p1,p2);
            break;

            case 3:
                mostra(contstruct,i,p);
            break;

            case 5:
                search(buffer,menu,i,j,contstruct,p,p1);
            break;
 
            case 6:
                sortByName(buffer,menu,i,j,contstruct,p,p1,p2);
            break;
            
            case 7:
                selectSortById(buffer,menu,i,j,contstruct,p,p1,p2);
            break;

            case 8:
                sortByAge(buffer,menu,i,j,contstruct,p,p1,p2);
            break;

            default:
                printf("Comando invalido!\n");
            break;
        }
    } while(*menu!=4);

    free(buffer);
}