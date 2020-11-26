#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Création d'une liste chaînées d'eléments
typedef struct Personne Personne;
struct Personne{
	int age;
	float moyenne;
	Personne *suivant;
	char nom[10];
};
typedef struct Liste Liste;
struct Liste{
	Personne* premier;
};
Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Personne *personne = malloc(sizeof(*personne));

    if (liste == NULL || personne == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(personne->nom,"Mohamed");
    personne->age = 23;
    personne->moyenne = 15.46;
    personne->suivant = NULL;
    liste->premier = personne;

    return liste;
}
void insertion(Liste *liste,char *nvnom,int nvage,float nvmoyenne)
{
    /* Création du nouvel élément */
    Personne *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nouveau->nom,nvnom);
    nouveau->age=nvage;
    nouveau->moyenne=nvmoyenne;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}
void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Personne *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf(" {nom: %s , age:%d , moyenne:%f} -> ", actuel->nom,actuel->age,actuel->moyenne);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
//Fonction qui calcule le nombre des éléments dans la liste chaînée
int nbre_Elements(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int c=0;

    Personne *actuel = liste->premier;

    while (actuel != NULL)
    {
    	c+=1;
        actuel = actuel->suivant;
    }
    return c;
}
//Fonction de hachage
int hachage(char *chaine,Liste *liste)
{
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= nbre_Elements(liste);

    return nombreHache;
}
int main()
{
    Liste *maListe = initialisation(); // initialisation de la liste
    //insertion des éléments dans la liste 
    insertion(maListe,"Youssef",22,16.36);
    insertion(maListe, "Ibrahim",23,15.21);
    insertion(maListe, "Ali",24,13.65);
    insertion(maListe,"Anas",23,13.87);
    insertion(maListe,"Youssef",25,18);
    insertion(maListe, "Ibrahim",26,17.5);
    insertion(maListe, "Ibrahim",23,19);
    insertion(maListe,"Anas",20,12);
    afficherListe(maListe);// affichage des éléments de la liste
    printf("\nLe nombre des elements de la liste est : %d \n",nbre_Elements(maListe));
    //Création d'un tableau de pointeurs de structure de même type que les éléments de la liste chaînée  
     if(nbre_Elements(maListe)>0){

    	 Liste *tab=(Liste*)malloc(nbre_Elements(maListe)*sizeof(Liste));//Allocation dynamique d'une table de Personnes
    	 if(tab==NULL){
    	 	exit(0); // Vérification si l'allocation a marché
    	 }
    	 /*code*/
    	 for(int i=0;i<nbre_Elements(maListe);i++){
    	 	tab[i].premier=NULL;
    	 }

    	 //Ajout des personnes dans le tableau
    	 Personne *personne = maListe->premier;
    	 while(personne!=NULL){
    	 	Personne *p=malloc(sizeof(Personne));
    	 	int nombre_de_hachage=hachage(personne->nom,maListe);
    	 	if(tab[nombre_de_hachage].premier==NULL){
    	 		tab[nombre_de_hachage].premier=p;
    	 		p->age=personne->age;
    	 		p->moyenne=personne->moyenne;
    	 		strcpy(p->nom,personne->nom);
    	 		p->suivant=NULL;
    	 	}
 	   	 	else {
    	 			
    	 			p=tab[nombre_de_hachage].premier;
    	 			while(p->suivant!=NULL){
    	 				p=p->suivant;
    	 			}
    	 			Personne *p2=malloc(sizeof(Personne));
    	 			p->suivant=p2;
    	 			p2->age=personne->age;
    	 		    p2->moyenne=personne->moyenne;
    	 		    strcpy(p2->nom,personne->nom);
    	 			p2->suivant=NULL;
    	 	}
    	 	personne=personne->suivant;
    	 }
    	  
   		  /*Coder les autres tâches ici*/
    }
    
   
    return 0;
}
    	 	
    	 	



    




   


