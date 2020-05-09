#ifndef __MAIN__H_
#define __MAIN__H_

#include <stdio.h>
#include <time.h>

#define IMG_SIZE 5
#define BW_THRESH 128

//Function Prototypes-----------------------------------------
void BW_Conversion(int image[IMG_SIZE][IMG_SIZE]);     
void Print_IMG(int image[IMG_SIZE][IMG_SIZE]);          
void IMG_Create();                                      
void MeanAVG_filter(int image[IMG_SIZE][IMG_SIZE]);     
void IMG_Inversion(int image[IMG_SIZE][IMG_SIZE]);      
void IMG_Scaling(int image[IMG_SIZE][IMG_SIZE]);        
void IMG_Compression(int image[IMG_SIZE][IMG_SIZE], int intensity[], int span[]);
void IMG_Decompression(int image[IMG_SIZE][IMG_SIZE], int intensity[], int span[]); 

#endif