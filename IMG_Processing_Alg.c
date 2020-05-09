#include "main.h"

//Image_Processing Functions----------------------------------
void IMG_Compression(int image[IMG_SIZE][IMG_SIZE], int intensity[], int span[]) {
    int int_ctr = 0;
    int pix_ctr = 0;
    int ctr = 1; // to compare to value in pixel vector
    
    for (int i = 0; i < IMG_SIZE; i++) {
        if (i % 2 == 0) {//traverse right, starting from left-most
            for (int j = 0; j < IMG_SIZE; j++) {
                if(i == 0 && j == 0) {
                intensity[int_ctr] = image[i][j];
                continue;
            }
                if(image[i][j] == intensity[int_ctr]) {
                ctr++; }
                else {
                    int_ctr++;
                    intensity[int_ctr] = image[i][j];
                    span[pix_ctr] = ctr;
                    pix_ctr++;
                    ctr = 1;
                }
            }
        }
        else {//traverse left, starting from right-most
            for (int j = IMG_SIZE-1; j >= 0; j--) {
                if(image[i][j] == intensity[int_ctr]) {
                ctr++; }
                else {
                    int_ctr++;
                    intensity[int_ctr] = image[i][j];
                    span[pix_ctr] = ctr;
                    pix_ctr++;
                    ctr = 1;
                }
            }
        }
    }
    span[pix_ctr] = ctr;
}

void IMG_Decompression(int image[IMG_SIZE][IMG_SIZE], int intensity[], int span[]) {
    int int_ctr = 0;
    int pix_ctr = 0;
    int ctr = 0;
            for (int i = 0; i < IMG_SIZE; i++) {
                if (i % 2 == 0) { //traverse right, starting from left-most
                    for (int j = 0; j < IMG_SIZE; j++) {
                        if (ctr < span[pix_ctr]) {
                            image[i][j] = intensity[int_ctr];
                            ctr++;
                        }
                        else { //go to next intensity val, span val
                            ctr = 0;
                            int_ctr++;
                            pix_ctr++;
                            image[i][j] = intensity[int_ctr];
                            ctr++;
                        }
                    }
                }
                else {
                    for (int j = IMG_SIZE-1; j >= 0; j--) {
                        if (ctr < span[pix_ctr]) {
                            image[i][j] = intensity[int_ctr];
                            ctr++;
                        }
                        else { //go to next intensity val, span val
                            ctr = 0;
                            int_ctr++;
                            pix_ctr++;
                            image[i][j] = intensity[int_ctr];
                            ctr++;
                        }
                    }
                }
            }
    
}

void BW_Conversion(int image[IMG_SIZE][IMG_SIZE]) {
    for(auto i = 0; i < IMG_SIZE; i++) {
        for (auto j = 0; j < IMG_SIZE; j++) {
            if (image [i][j] < BW_THRESH)
                image [i][j] = 0;
            else
                image [i][j] = 255;
        }
    }
}

void Print_IMG(int image[IMG_SIZE][IMG_SIZE]) {
    for (size_t i = 0; i < IMG_SIZE; i++) {
        for (size_t j = 0; j < IMG_SIZE; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void IMG_Create(int image[IMG_SIZE][IMG_SIZE]) {
    srand((unsigned) time(NULL));           //sclock seed
    for (auto i = 0; i < IMG_SIZE; i++) {
        for (auto j = 0; j < IMG_SIZE; j++) {
        image [i][j] = (rand() % (255-0+1)); } //generate value from 0-255
    }
}

void IMG_Inversion(int image[IMG_SIZE][IMG_SIZE]) { 
    for (auto i = 0; i < IMG_SIZE; i++) {
        for (auto j = 0; j < IMG_SIZE; j++) { 
        image [i][j] = 255 - image [i][j]; } //flipping each pixel
    }
}

void IMG_Scaling(int image[IMG_SIZE][IMG_SIZE]) {
    for (auto i = 0; i < IMG_SIZE; i++) {
        for (auto j = 0; j < IMG_SIZE; j++) {
        image [i][j] = image [i][j]/2; }
    }
}

void MeanAVG_filter(int image[IMG_SIZE][IMG_SIZE]) {
    int mean_acc = 0;
    int averages[9];
    int avg_ctr = 0;
    for (auto i = 1; i <= IMG_SIZE - 2; i++) {      // N = 9, 3x3 neighborhood, traverses inner square 4x4 matrix
        for (auto j = 1; j <= IMG_SIZE - 2; j++) {  // Excludes outermost matrix layer
            mean_acc = (image[i-1][j-1] + image[i-1][j] + image[i-1][j+1] 
            + image[i][j-1] + image[i][j+1] + image[i+1][j-1] + image[i+1][j]
            + image[i+1][j+1])/8;
            averages[avg_ctr] = mean_acc;           //stores averages in vector
            avg_ctr++;
        }
    }
    avg_ctr = 0;                                    //traverses inner matrix again and
    for (auto x = 1; x <= IMG_SIZE - 2; x++)        //assigns vector value to each pixel
        for (auto y = 1; y <= IMG_SIZE - 2; y++) {
            image[x][y] = averages[avg_ctr];
            avg_ctr++;
        }
}

//End Image-Processing Functions-----------------------------
