#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define TAILLE_MAX 50
/*prototypes*/
void initTab (int T[] , int n);
void remplitTableauAlea (int T[] , int n);
void afficheTableau (int T[] , int n);
int getMin (int T[] , int n);
int getMax (int T[] , int n);
double calculeMoyenne (int T[] , int n);
double calculeEcartType (int T[] , int n);
void calculeHistogramme (int T[] , int n, int H[], int m);
void affciheHistogramme (int T[], int n);
/*Implementation*/
void initTableau (int T[], int n)
{
    int i;
    for( i = 0 ; i < n ; i++){
        T[i] = 0 ;
    }
} 
void remplitTableauAlea (int T[] , int n)
{
    int i;
    for( i = 0 ; i < n ; i++){
        tab[i] = rand() % 101; //nombres entre 0 et 100
    }
}
void afficheTableau(int T[], int n){
    int i;
    printf("T = [");
    for(i = 0; i < n ; i++){
        printf(" %d" , T[i]);
    }
    printf("]\n");
}


//index du min 
int getMin(int T[] , int n){
    int i , min = 0;
    for(i = 1 ; i < n ; i++){
        if(T[i] < T[min] )
        min = i;
    }
    return min;
}


//index du max
int getMax(int T[] , int n){
    int i , max = 0 ;
    for (i = 0 ; i < n ; i++){
        if(T[i] > T[max]){
            max = i ;
        }
    }
    return max;
}


double calculeMoyenne(int T[] , int n){
    double sum = 0 ;
    int i;
    for(i = 0 ; i < n ; i++){
        sum+=T[i];
    }
    return ((double)(sum/n));
}


double calculeEcartType (int T[] , int n){
    double res = 0 ;
    double moy = calculeMoyenne(T,n);
    double ecart;
    int i;
    for(i=0 ; i<n ; i++){
        ecart = T[i] - moy;
        res +=ecart*ecart;
    }
    return sqrt(res / (double)n);
}

//calcul d'histogramme
void calculeHistogramme (int T[], int n , int H[] , int m){
    double min = T[getMin(T,n)], max = T[getMax(T,n)];
    double L = (max - min) / (double)m;
    double inf = min , sup = min + L;

    initTab(H,m);
    for( j = 0; j < m; ++j, inf = sup, sup+=L){
        if (j == m-1)
         sup += 1.0e-6;
    printf("class %d: [%f,%f[ ->" , j , inf , sup);
    for (i = 0 ; i < n ; ++i){
        if ((T[i] >= inf) && (T[i] < sup)){
            ++H[j];
            printf(" %d" , T[i]);
        }
    }   
    printf("\n");
    }
}

//Affichage d'histogramme 
void afficheHistogramme (int T[] , int n){
    int i, t;
    for (i = 0; i < n; ++i){
        printf("%d: ",i);
        for (t = 0 ; t < T[i] ; ++t)
            printf("*");
        printf("\n");
    }
}
//Test
int main(){
        /* Declarations */
        int tab[TAILLE_MAX] , histo[TAILLE_MAX];
        int taille_tab, taille_histo;
        /* Get the current size of the array */
        do{
            printf("taille du tableau (<=%d):" , TAILLE_MAX);
            scanf("%d" , &taille_tab);
        }while ((taille_tab < 1)|| (taille_tab > TAILLE_MAX));
        initTableau(tab, taille_tab);
        afficheTableau(tab, taille_tab);
        srand(0);
        remplitTableauAlea(tab , taille_tab);
        affciheTableau(tab, taille_tab);
        /* display some statistics */
        printf("element min = %d (position %d)\n", tab[getMin(tab, taille_tab)], getMin(tab, taille_tab));
        printf("element max = %d (position %d)\n", tab[getMax(tab, taille_tab)], getMax(tab, taille_tab));
        printf("moyenne     = %f (%d elements)\n", calculeMoyenne(tab, taille_tab), taille_tab);
        printf("ecart-type  = %f (%d elements)\n", calculeEcartType(tab, taille_tab), taille_tab);

        /* get the number of classes */
        do
        {
        printf("nombre de classes (<= %d):", TAILLE_MAX);
        scanf("%d", &taille_histo);
        } while ((taille_histo < 1)  & & (taille_histo > TAILLE_MAX));

        /* compute an histo out of the array */
        calculeHistogramme(tab, taille_tab, histo, taille_histo);
        afficheTableau(histo, taille_histo);
        afficheHistogramme(histo, taille_histo);

        return EXIT_SUCCESS;
     }





