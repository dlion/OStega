/*
A simple libraries to use steganography with OpenCV
Thinking and created by Domenico Luciani aka DLion
*/

/* Function to insert and crypt a message into an bmp image.
 * first parameter is an image, second parameter is a message.
 * It returns -1 to error or 0 to complete successfull.
 */
int imgStega(IplImage*, char*);

/* Function to get a steganographed message into an bmp image
 * first parameter is an image
 * It returns the decrypted message
 */
char *imgDestega(IplImage*);
