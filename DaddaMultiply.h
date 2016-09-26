#ifndef DADDAMULTIPLY_H
#define DADDAMULTIPLY_H



/** ALLOCATE MEMORY FOR A MATRIX
 *
 * "height" - Number of rows for matrix
 *
 * "width" - Number of columns for matrix
 *
 * "return" - Pointer to memory block allocated
 *
 */

char** Allocate_Matrix(int height, int width);




/** FREE MEMORY ALLOCATED FOR MATRIX
 *
 * "Matrix" - 2d Memory block to be freed
 *
 * "Height" - Number of rows in Matrix
 *
 */

void Free_Matrix(char **Matrix, int Height);




/** SET ALL VALUES IN MATRIX TO '-' (EMPTY)
 *
 * ""Matrix" - Matrix to be set to empty
 *
 * "Height" - Number of rows in matrix
 *
 * "Width" - Number of columns in matrix
 *
 */

void Set_Matrix_Empty(char **Matrix, int Height, int Width);




/** PERFORM LONG MULTIPLICATION OF "a" AND "b"
 *
 * "a" - First binary array to be multiplied
 *
 * "b" - Second binary array to be multiplied
 *
 * "Dadda_Matrix" - Matrix where long multiplication
 *                  will be stored
 *
 */

void Binary_Long_Multiplication(char *a, char *b, char **Dadda_Matrix);




/** REDUCE MATRIX USING DADDA MULITIPLICATION ALGORITHM
 *
 * "Dadda_Matrix" - Matrix to be reduced
 *
 * "depth" - Height of Largest column.
 *
 * "return" - Next reduction height to reduce matrix to
 *            Uses the formula d(j+1) = 1.5 * dj. Formula
 *
 */

int Reduce_Dadda_Matrix(char **Dadda_Matrix, int depth);




/** RESULT[] = DADDA_MATRIX[FIRST ROW][]
 *
 * "Dadda_Matrix" - 2d matrix that first row will
 *                  be copied from
 *
 * "Result" - Binary array  values will be copied
 *            into.
 *
 */

void Set_Result_From_Matrix(char **Dadda_Matrix, char *Result);




/** PRINT MATRIX
 *
 * "Dadda_Matrix" - 2d matrix to be printed to screen.
 *
 */

void Print_Matrix(char **Dadda_Matrix);





#endif // DADDAMULTIPLY_H

