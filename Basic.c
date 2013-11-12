#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Tyler Harbin-Giuntoli

void main(){
    int i = 0, j = 0, start = 0;//counters

    char file[30];//filename
    char key[30];//key
    FILE *data;
    data = fopen("data.txt", "r");
    fscanf(data, "%s", &file);
    fscanf(data, "%s", &key);
    fclose(data);//done with this file now

    FILE *fp;
    FILE *out;
    fp = fopen(file, "rb");//in file
    out = fopen("output.bmp", "wb");//out file
    fseek(fp, 0, SEEK_END);//go to end of file
    j = (ftell(fp));//stores size of file in bytes
    rewind(fp);//go back to beginning
    fseek(fp, 10, SEEK_SET);//find 10th byte
    fread(&start,1,1,fp);//load data at byte into start, tells us where array begins
    rewind(fp);//go back to beginning of file
    printf("Starting at %d\nOut of %d bytes\n", start, j);//tells us end of header location
    if(start>j)
        printf("Error in start point!\n");//if it breaks
    rewind(fp);//back to beginning of file
    int in;//I/O variable
    char thro;//used to allow slow scanning

    for(i=0;i<start;i++){//Header Info Range
        fread(&in, 1, 1, fp);
        fwrite(&in, 1, 1, out);
    }
    for(i=start; i<j; i++){//beginning of bitmap array

        fread(&in, 1, 1, fp);
        //start encryption

        //end encryption
        //in = in%256;//use if necessary
        fwrite(&in, 1, 1, out);
    }
    fclose(fp);//clean up
    fclose(out);
}//end of program
