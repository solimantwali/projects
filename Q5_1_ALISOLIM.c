#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char caeser(char letter, int c){
    //printf("letter is %c, shift is %d\n", letter, c);
    int ascii_letter = (int)letter;
    //printf("ascii val of letter is %d\n", ascii_letter);
    //printf("val of encrypted letter is %d\n", ascii_letter+c);
    if (ascii_letter+c > 90 && ascii_letter+c < 97){
        int new_letter = (char) ascii_letter+c-26;
        return new_letter;
    } else if (ascii_letter+c > 122){
        int new_letter = (char) ascii_letter+c - 26;
        return new_letter;
    } else{
        char new_letter = (char)(ascii_letter+c);
        //printf("new letter is %c\n", new_letter);
        return new_letter;
    }
}

int * vigenere(char* enc_msg, char* dec_msg){
    int n = strlen(enc_msg);
    //printf("first letters for the encoded and decoded are %c and %c respectively\n", enc_msg[0], dec_msg[0]);
    //printf("length of message is %d characters\n", n);
    //printf("the encrypted and associated decrypted message are %s and %s, respectively\n", enc_msg, dec_msg);
    int* cipher = calloc(n, sizeof(int));
    int i = 0;
    for (i; i < n ; i++){
        int c = 0;
        while(caeser(dec_msg[i],c) != enc_msg[i]){
            c++;
        }
        //printf("cipher[%d] is %d\n", i, c);
        cipher[i] = c;
    }
    cipher[n] = -1;
    int *retarr = calloc(n, sizeof(int));
    int seq = 0;

    //printf("now finding other shit\n\n");
    int ret_size = 1;
    for (ret_size; ret_size < n ; ret_size++){
    //printf("ret size is %d\n", ret_size);

        for(int k = 0 ; k<ret_size ; k++){
            retarr[k] = cipher[k];
            //printf("retarr[%d] = %d\n", k, retarr[k]);
        }
        int ruined = 0;
        for(int j = 0; j<ret_size ; j++){
            
            int f = 1;
            while (f*ret_size+j < n){
                if (retarr[j] == cipher[f*ret_size+j]){
                    //printf("retarr[%d] and cipher[%d] are the same.\n", j, f*ret_size+j);
                    seq = 1;
                } else {
                    //printf("it's fucked. retarr[%d] and cipher[%d] are not the same.\n", j, f*ret_size+j);
                    ruined += 1;
                }
                f++;
            }
        }
        //printf("ruined value is %d\n", ruined);
        if (ruined == 0){
            //printf("length of key is %d\n", ret_size);
            break;
        }
        //printf("\n\n");
    }
    //printf("ret size is %d\n", ret_size);
    for(int w = 0; w<ret_size; w++){
        //printf("retarr[%d] is %d\n", w, retarr[w]);
    }
    retarr[ret_size] = -1;
    free(cipher);

    return retarr;
}


int main(void){
    //char letter = 'L';
    //int c = 5;
    //char boi = caeser(letter, c);
    //printf("main: the letter %c has been changed to %c via phase shift of %d\n", letter, boi, c);
    //printf("hi\n");
    //printf("yo\n");

    char * enc_msg = "CCEEFCCEEFCC";
    char* dec_msg = "AAAAAAAAAAAA";
    int* cipk = vigenere(enc_msg, dec_msg);

    //printf("yo\n");
    
    int k = 0;

    while (cipk[k]!= -1){
        printf("%d ", cipk[k]);
        k++;
        //free(cipk[k]);
    }
    return 0;
}