//
//  main.c
//  Lyrics demo
//
//  Created by apple on 2019/10/23.
//  Copyright © 2019 apple. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 2048
#define MAX_PATH 1024
#define MAX_NAME 512
void textProcessor(FILE *lrcx,FILE *lrc);
int isLineRight(char* buffer);
void deleteString(char *buffer,int position);
void getFileName(char* lrcxPath, char* fileName);
void editPath(char* lrcxPath);

int main(int argc, const char * argv[]) {
    //input the path of .lrcx file
    char lrcxPath[MAX_PATH];
    printf("Drag the .lrcx File:");
    
    scanf("%s",lrcxPath);
    //edit the path(ep. space,"")
    char fileName[MAX_NAME];
    getFileName(lrcxPath, fileName);
    char outPath[MAX_PATH]="/Users/apple/Desktop/" ;
    strcat(outPath, fileName);
    //open the .lrcx file by the path above
    FILE *lrcx;
    lrcx=fopen(lrcxPath, "r");
    
    //create a new .lrc file as the output
    FILE *lrc;
    lrc=fopen(outPath,"w");
    
    /*lyrics text processor*/
    textProcessor(lrcx, lrc);
    
    //close the files
    fclose(lrcx);
    fclose(lrc);
}

void textProcessor(FILE *lrcx,FILE *lrc){
    char buffer[MAX_LENGTH];
    
    while(fgets(buffer, MAX_LENGTH, lrcx)!=NULL)
    {
        if(isLineRight(buffer)==1){
            //edit the time format
            buffer[6]=':';
            deleteString(buffer, 9);
            
            fputs(buffer, lrc);
        }
    }
}
   
int isLineRight(char* buffer){
    int point=0;
    
    while(buffer[point]!='\n'){
        if(buffer[point]=='['){
            if(buffer[point+1]>='0'&&buffer[point+1]<='9'){
                ;
            }
            else return 0;
        }
        point++;
    }
    return 1;
}

void deleteString(char *buffer,int position){
    int point=position;
    while(buffer[point]!='\0'){
        buffer[point]=buffer[point+1];
        point++;
    }
    buffer[point]=buffer[point+1];
}

void editPath(char* lrcxPath){
    
}

void getFileName(char* lrcxPath, char* fileName){
    //find endPoint and the last '/'
    int endPoint;
    for(endPoint=0;lrcxPath[endPoint]!='\0';endPoint++){;}
    int lastSection;
    for(lastSection=endPoint;lrcxPath[lastSection]!='/';lastSection--){;}
    lastSection++;
    int i;
    //get the file name to the string
    //endPoint-1 to delete the 'x' out of 'lrcx'
    for(i=0;lastSection!=endPoint-1;lastSection++,i++){
        fileName[i]=lrcxPath[lastSection];
    }
    
}
