#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    int dato;
    struct nod *sig,*ant;
}Nodo;

typedef struct{
    Nodo *prim,*ult;
}Lista;

Nodo* creaNodo(int d);
void iniLista(Lista *cab);
int insertaIni(Lista *cab,int dato);
void imprimir(Lista cab);

int main(){
    Lista list;
    iniLista(&list);
    int dato;
    int tecla=0;
    for(tecla=0;tecla!=3;tecla++){
        printf("Selecciona una opcion:\n");
        printf("1.- Ingresar un numero\n");
        printf("2.- Imprimir\n");
        printf("3.- Salir\n");
        scanf("%d",&tecla);
        if(tecla==1){
                system("cls");
                tecla=0;
                printf("Dame un número");
                scanf("%d",&dato);
                insertaIni(&list,dato);
        }
        if(tecla==2){
                system("cls");
                tecla = 0;
                imprimir(list);
        }
    }
    return 0;
}

Nodo* creaNodo(int d){
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevo){
        nuevo->dato=d;
        nuevo->sig=NULL;
        nuevo->ant=NULL;
    }
    return nuevo;
}

void iniLista(Lista *cab){
    cab->prim=NULL;
    cab->ult=NULL;
}

int insertaIni(Lista *cab,int dato){
    Nodo *nuevo;
    nuevo = creaNodo(dato);
    if(nuevo){
        if(!cab->prim){
            cab->prim=nuevo;
            cab->ult=nuevo;
        }
        else{
            nuevo->sig=cab->prim;
            cab->prim->ant=nuevo;
            cab->prim=nuevo;
        }
        return 1;
    }
    return 0;
}

void imprimir(Lista cab){
    Nodo *aux;
    aux=cab.prim;
    if(aux){
        while(aux){
            printf("%d",aux->dato);
            aux=aux->sig;
        }
        getch();
        system("cls");
    }
    else{
        printf("No hay números\n");
        getch();
        system("cls");
    }
}
