#include <stdio.h>
#include <stdlib.h>
#define NUM_STORES 100
#define NUM_GELO 10

typedef struct Gelato{
    char *flavour;      // flavour
    int pop_num;            // popularity number
    int quantity;           // quantity
} Gelato;

typedef struct AlgosStore{
    char *mgr;          // name of manager
    int staffcount;         // number of staff members
    Gelato** gel_arr;       // array of gelatos
} AlgosStore;

typedef struct AlgosGelatos{
    char *ceo;          // name of CEO
    AlgosStore** storay;     // array of AlgosStores
} AlgosGelatos;

void print_chain(AlgosGelatos algo){
    printf("Name of CEO: %s\n\n", algo.ceo);
    int i = 0;
    for (i; i<NUM_STORES; i++){          
        printf("Name of manager: %s\n", algo.storay[i] -> mgr);
        printf("Number of staff members: %d\n", algo.storay[i] -> staffcount);
        int j = 0;                          // another counter for the gelato array
        for(j ; j<NUM_GELO ; j++){
            if (algo.storay[i] -> gel_arr[j] != NULL){
                Gelato *boi = algo.storay[i] -> gel_arr[j];
                printf("\tGelato flavour: %s\n", boi -> flavour);
                printf("\tGelato Popularity Number: %d\n", boi -> pop_num);
                printf("\tGelato quantity: %d\n", boi -> quantity);
            }
        }
        printf("\n");
    }
}

int mystrcmp(char* str1, char* str2){
    int i = 0, fried = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i])                              {fried = 1;break;}
        i++;
    }
    if(fried == 0 && str1[i] == '\0' && str2[i] == '\0')    {return 1;}
    else                                                    {return 0;}
}

void distro(AlgosGelatos * storepoint, Gelato **arrgelo){
    int removo[NUM_GELO];
    for (int i=0; i<NUM_STORES; i++){
        for(int j = 0; j<NUM_GELO; j++){
            char * daflav = storepoint->storay[i]->gel_arr[j]->flavour;
            int dacount = storepoint->storay[i]->gel_arr[j]->quantity;
            //printf("Gel flavour %d for store %d is %s\n", j+1, i+1, daflav);
            //printf("Gel quantity for flavour %s, store %d is: %d\n", daflav, i+1, dacount);
            for (int k = 0; k<NUM_GELO; k++){
                int quant = arrgelo[k]->quantity;
                if (mystrcmp(daflav, arrgelo[k]->flavour)){
                    //printf("Current quantity of flavour %s is: %d\n", daflav, dacount);
                    //printf("The distributor carries %d gelatos of flavour %s\n", arrgelo[k]->quantity, daflav);
                    //printf("Since there are %d stores, each store gets %d gelos of flavour %s\n", NUM_STORES, quant/NUM_STORES, daflav);
                    dacount += quant/NUM_STORES;
                    removo[k] = NUM_STORES*(quant/NUM_STORES);
                    //printf("New count for flavour %s is: %d\n", daflav, dacount);
                }
            }
            //printf("\n\n");
        }
    }
    for (int i = 0; i<NUM_STORES ; i++){
        arrgelo[i]->quantity -= removo[i];
        //printf("The remainder for the distributor's flavour %s is: %d\n", arrgelo[i]->flavour, arrgelo[i]->quantity);
    }
}





int main(void){
    AlgosGelatos algo;
    algo.ceo = "motherfucker";
    AlgosStore** store_array = calloc(NUM_STORES, sizeof(AlgosStore*));
    algo.storay = store_array;

    AlgosStore *store1 = malloc(sizeof(AlgosStore));
    store1 -> mgr = "hain";
    store1 -> staffcount = 69;
    store_array[0] = store1;

    Gelato *gel1 = malloc(sizeof(Gelato));
    gel1 -> flavour = "redboi";
    gel1 -> quantity = 420;
    gel1 -> pop_num = 3;

    Gelato *gel2 = malloc(sizeof(Gelato));
    gel2 -> flavour = "blueboi";
    gel2 -> quantity = 422;
    gel2 -> pop_num = 1;

    Gelato ** gel_arr1 = calloc(NUM_GELO, sizeof(Gelato*));
    gel_arr1[0] = gel1;
    gel_arr1[1] = gel2;
    //gel_arr1[2] = NULL;
    store1 -> gel_arr = gel_arr1;

    AlgosStore *store2 = malloc(sizeof(AlgosStore));
    store2 -> mgr = "yaboi";
    store2 -> staffcount = 200;
    store_array[1] = store2;

    Gelato *gel3 = malloc(sizeof(Gelato));
    gel3 -> flavour = "redboi";
    gel3 -> quantity = 999;
    gel3 -> pop_num = 87;
    Gelato *gel4 = malloc(sizeof(Gelato));
    gel4 -> flavour = "blueboi";
    gel4 -> quantity = 96;
    gel4 -> pop_num = 7777;
    Gelato ** gel_arr2 = calloc(2, sizeof(Gelato*));
    gel_arr2[0] = gel3;
    gel_arr2[1] = gel4;
    store2 -> gel_arr = gel_arr2;

    AlgosStore *store3 = malloc(sizeof(AlgosStore));
    store3 -> mgr = "int FOO";
    store3 -> staffcount = 11111;
    store_array[2] = store3;

    Gelato *gel5 = malloc(sizeof(Gelato));
    gel5 -> flavour = "redboi";
    gel5 -> quantity = 88888;
    gel5 -> pop_num = 88888888;
    Gelato *gel6 = malloc(sizeof(Gelato));
    gel6 -> flavour = "blueboi";
    gel6 -> quantity = 55555;
    gel6 -> pop_num = 55555;
    Gelato ** gel_arr3 = calloc(NUM_GELO, sizeof(Gelato*));
    gel_arr3[0] = gel5;
    gel_arr3[1] = gel6;
    store3 -> gel_arr = gel_arr3;

    Gelato **bumbar = calloc(NUM_GELO, sizeof(Gelato*));
    Gelato *gel7 = malloc(sizeof(Gelato));
    gel7 -> flavour = "redboi";
    gel7 -> quantity = 65;
    gel7 -> pop_num = 30;
    Gelato *gel8 = malloc(sizeof(Gelato));
    gel8 -> flavour = "blueboi";
    gel8 -> quantity = 66;
    gel8 -> pop_num = 45;
    bumbar[0] = gel7;
    bumbar[1] = gel8;

/*     if(mystrcmp(algo.storay[0]->gel_arr[0]->flavour,algo.storay[1]->gel_arr[0]->flavour)){
        printf("shits equal b.\n");
    } else {
        printf("shit aint equal b.\n");
    } */



    //print_chain(algo);
    distro(&algo, bumbar);
    return 0;
}