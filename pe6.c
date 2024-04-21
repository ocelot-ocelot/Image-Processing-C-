#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Name: 	Cem Cengiz Yazıcı
// ID  :	0076272
// mail:	cyazici20@ku.edu.tr


// Function to read the image by iterating rows and columns
void readImage(char *filename, int **arr, int rows, int cols)
{
	FILE* fin = fopen(filename, "r");
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++)
		{
			fscanf(fin, "%d,", &arr[i][j]);
		}
	}
	fclose(fin);
}


// Function to write image into the file specified by the filename
void writeImage(char *filename, int **arr, int rows, int cols)
{
	FILE* fout = fopen(filename, "w");
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(j==cols-1)
				fprintf(fout, "%d", arr[i][j]);
			else
				fprintf(fout, "%d,", arr[i][j]);
		}
		fprintf(fout,"\n");
	}
	fclose(fout);

}

// Function to invert Image
void **invertImage(int **arr, int rows, int cols)
{
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			arr[i][j] = 255-arr[i][j];
		}
	}
}

// Function to shift intensity values by specified amount.
// Overshooting and undershooting values are set to 255 and 0 respectively.
void shiftImage(int **arr, int rows, int cols, int changeval)
{
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			arr[i][j] = arr[i][j]+changeval;
			if(arr[i][j]>255)
				arr[i][j] = 255;
			else if(arr[i][j]<0)
				arr[i][j] = 0;
		}
	}
}

// Generate a new File Name given extension
// For example, if file name is "file.txt" and the extension is "_new.txt", filename will be "file_new.txt"
char *generateFilename(char *filename, char *extension){
	char *filename_buff = malloc(sizeof(char)*(strlen(extension)+strlen(filename)));
	strcpy(filename_buff, filename);
	char *newfilename = strtok(filename_buff, ".");
	strcat(newfilename, extension);
	return newfilename;
}

int main(int argc, char *argv[])
{
	// Get function arguments
	int rows = atoi(argv[2]);
	int cols = atoi(argv[3]);
	int changeval = atoi(argv[4]);
 	char *filename = argv[1];  
	
	// Allocate Memory for Intensity Values
	int **arr = (int **)malloc(rows*sizeof(int *));
	for(int k=0; k<rows; k++)
	{
		arr[k] = (int *)malloc(cols*sizeof(int));
	}
	if(arr == NULL){fprintf(stderr, "Unable to allocate Memory.");}

	// Generate File Names for Output Files
	char *newfilename = generateFilename(filename, "_neg.txt");
	char *newfilename2 = generateFilename(filename, "_changeVal.txt");
			
	// Call the functions to generate images
	// Invert the image intensities
	// Write onto new file
	readImage(filename, arr, rows, cols);
	invertImage(arr,rows,cols);
	writeImage(newfilename, arr, rows, cols);
	
	// Invert image again to get the original image back
	// Then shift the intensity values 
	// Write onto new file
	invertImage(arr, rows, cols);
	shiftImage(arr, rows, cols, changeval);
	writeImage(newfilename2, arr, rows, cols);
	free(newfilename);
	free(newfilename2);
	free(arr);
}
