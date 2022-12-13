#include "stdio.h"
#include "stdlib.h"

char sWord[7] = "winhtut";
char sWord2[17] = "NationalCyberCity";
char tWord[17];
int count = 0;
int count1 = 0;
int index = 0;
int check = 0;
char data;

void countFun1();
void countFun2();
int wordCheck(char word[17]);

int main(){

    countFun1();
    countFun2();
    printf("We found winhtut %d times in the text.\n",count);
    printf("We found NationalCyberCity %d times in the text.",count1);

return 0;
}

void countFun1(){
    FILE *fptr;
    fptr = fopen("words.txt","r");
    if(fptr == NULL){
        exit(1);
    }
    while(!feof(fptr)){
        if(check == 7){
            count += wordCheck(tWord);
            check = 0;
        }
        if(index == 7){
            index = 0;
        }
        if(check == 0){
            data = fgetc(fptr);
            if(data == 'w'){
                tWord[index] = data;
                index++;
                check = 1;
            }
        }else{
            data = fgetc(fptr);
            tWord[index] = data;
            index++;
            check++;
        }
    }
    fclose(fptr);
}
void countFun2(){
    FILE *fptr;
    fptr = fopen("words.txt","r");
    if(fptr == NULL){
        exit(1);
    }
    while(!feof(fptr)){
        if(check == 17){
            count1 += wordCheck(tWord);
            check = 0;
        }
        if(index == 17){
            index = 0;
        }
        if(check == 0){
            data = fgetc(fptr);
            if(data == 'N'){
                tWord[index] = data;
                index++;
                check = 1;
            }
        }else{
            data = fgetc(fptr);
            tWord[index] = data;
            index++;
            check++;
        }
    }
    fclose(fptr);
}
int wordCheck(char word[17]){
    int c = 0;
    if(word[0] == 'w'){
       for(int i=0; i<7; i++){
            if(sWord[i] == word[i]){
                c++;
            }
        }
        if(c == 7){
            return 1;
        }
    }else{
        for(int i=0; i<17; i++){
            if(sWord2[i] == word[i]){
                c++;
            }
        }
        if(c == 17){
            return 1;
        }
    }
    return 0;
}
