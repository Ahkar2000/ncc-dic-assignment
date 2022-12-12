#include "stdio.h"
#include "stdlib.h"

char sWord[7] = {'w','i','n','h','t','u','t'};
char tWord[7];
int index = 0;
int check = 0;
int count = 0;
char data;

void dataRead();
int wordCheck(char word[7]);

int main(){

    dataRead();
    printf("We found winhtut %d times in the text.",count);

return 0;
}

void dataRead(){
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
            if(data == sWord[0]){
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
int wordCheck(char word[7]){
    int c = 0;
    for(int i=0; i<7; i++){
        if(sWord[i] == word[i]){
            c++;
        }
    }
    if(c == 7){
        return 1;
    }else{
        return 0;
    }
}
