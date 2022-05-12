/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/// structure d'une cellule 
typedef struct cellule{
    int value;
    struct cellule * next;
}cellule;


// structure d'une liste
typedef struct liste{
    struct cellule * debut;
} liste;


// creer une cellule avec un entier
struct cellule * creer_cellule(int v){
    struct cellule * c = malloc(sizeof(struct cellule));
    c->value = v;
    c->next = NULL;
    return c;
}


// creer une liste vide et la retourne 
struct liste * creer_liste(){
    struct liste * l = malloc(sizeof(struct liste));
    l->debut = NULL;
    return l;
}


// ajouter un entier a la fin d'une liste et la retoune
struct liste * ajouter_fin(int x,struct liste * l){
    struct cellule * new_c = creer_cellule(x);
    struct cellule * current = l->debut;
     
     if(current == NULL){
         l->debut = new_c;
     }
     else{
         while(current->next != NULL){
             current = current->next;
         }
         
         current->next = new_c;
     }
     
    return l;
    
}









// retourne la taille d'une liste
int taille_liste(struct liste* l){
    int i = 0;
    
    struct cellule * current = l->debut;
    
    if(current != NULL){
        i += 1;
    
        while(current-> next != NULL){
            current = current->next;
            i += 1;
        }
    }
    
    printf("Taille = %d \n",i);
    return i;
}



// affiche une liste d'entier 
void affiche_liste(struct liste * l){
    struct cellule * current = l->debut;
    if(current == NULL){
        printf("Liste vide.\n");
    }
    else{
        do{
            printf("| %d ",current->value);
            current = current->next;
        }
        while(current != NULL);
        printf("|\n");
        
    }
    

}


//ajouter un entier au debut d ela liste

struct liste * ajouter_debut(int v,struct liste * l){
    struct cellule * new_c = creer_cellule(v);
    
    struct cellule * current = l->debut;
    
    if(current == NULL){ // liste vide
        l->debut = new_c;
    }
    else{
        new_c->next = current;
        l->debut = new_c;
    }
    return l;
}


struct liste * ajouter_indice(int i, int v,struct liste * l){
    
    int taille = taille_liste(l);
    
    if(i > taille){
        printf("Taille de la liste(%d) est inferieur a l'indice i(%d) \n",taille,i);
        return l;
    }
    if(0 > i){
        printf("L'indice i doit etre positif.");
        return l;
    }
    
    
    if(i == 0){
        l = ajouter_debut(v,l);
        return l;
    }
    
    if(i == taille){
        l = ajouter_fin(v,l);
        return l;
    }
    
    int current_i = 0;
    struct cellule * new_c = creer_cellule(v);
    
    struct cellule * current = l->debut;
    
    
    while( current_i + 1 != i){
        current = current->next;
        current_i += 1;
    }
   
   new_c->next = current->next;
   current->next = new_c;
   
    return l;
}






//supprimer debut
struct liste * supprimer_debut(liste * l){

    struct cellule * current = l->debut;
    
    
    if(current == NULL){
        printf("Liste deja vide.\n");
        return l;
    }
    
    if(current->next == NULL){
        l->debut = NULL;
        return l;
    }
    
    l->debut = current->next;
    free(current);
   
    return l;
}


//supprimer debut
struct liste * supprimer_fin(liste * l){

    struct cellule * current = l->debut;
    
    
    if(current == NULL){
        printf("Liste deja vide.\n");
        return l;
    }
    
    if(current->next == NULL){
        l->debut = NULL;
        return l;
    }
    
    
    while(current->next->next != NULL){
        current = current->next;
    }
    
    current->next = NULL;
   
    return l;
}







struct liste * supprimer_indice(int i,struct liste * l){
    
    int taille = taille_liste(l);
    
    if(i > taille){
        printf("Taille de la liste(%d) est inferieur a l'indice i(%d) \n",taille,i);
        return l;
    }
    if(0 > i){
        printf("L'indice i doit etre positif.");
        return l;
    }
    
    
    if(i == 0){
        l = supprimer_debut(l);
        return l;
    }
    
    if(i == taille - 1){
        l = supprimer_fin(l);
        return l;
    }
    
    
    
    int current_i = 0;
    
    struct cellule * current = l->debut;
    
    
    while( current_i + 1 != i){
        current = current->next;
        current_i += 1;
    }
   
   
   struct cellule * to_delete = current->next;
   current->next = to_delete->next;
   free(to_delete);
   return l;
}





int main()
{
    
    struct liste * l = creer_liste();
    affiche_liste(l);
    
    //l = ajouter_debut(8,l);
    
    
    
    ajouter_fin(0,l);
    ajouter_fin(1,l);
    ajouter_fin(2,l);
    ajouter_fin(10,l);
    ajouter_fin(3,l);
    ajouter_fin(4,l);
    ajouter_fin(5,l);
    
    //l = ajouter_debut(6,l);
    
    /*
    l = ajouter_indice(0,0,l);
    l = ajouter_indice(2,2,l);
    l = ajouter_indice(6,6,l);
    */
    //l = supprimer_fin(l);
    
    l = supprimer_indice(3,l);
    affiche_liste(l);
    taille_liste(l);
    
    
    
    return 0;
}
