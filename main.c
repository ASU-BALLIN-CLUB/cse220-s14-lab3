// Group members: Sean Slamka, Shangxin (James) Wang, Aydin Balci

#include <stdio.h>

#include "common.h"


int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    static int line_number = 1;

    print_page_header(argv[1], date);

    source_file = init_lister(argv[1], source_name, date);
    // passes argv1 into init_lister

    if( source_file == NULL )
    {
	return 1;
    }
    // if statement for the source file not containing anything.

    char source_buffer2[MAX_SOURCE_LINE_LENGTH];
    // Instantiating the source buffer.

    while(fgets(source_buffer2,MAX_SOURCE_LINE_LENGTH,source_file) )
    {
	printf("%i", line_number);
	printf(": ");
        printf("%s",source_buffer2);
        line_number++;
    }

    // The while loop for the main function, prints out all the information then increments the line number.
    fclose (source_file);
    // closes the file.

    return 0;
}   // end of main.

FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;

	struct tm* timeinfo;

    time(&timer);
    timeinfo = localtime(&timer);
    strcpy(dte, asctime(timeinfo));

	printf(dte);

    source_file_name = name;
    file = fopen(source_file_name,"r");

    return file;
}
// Init_lister file to print out the time/source file.


BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;


return (TRUE);
}
// Boolean to see if the print/source buffer are correct.


static void print_page_header(char source_name[], char date[])
{
    static int page_number = 1;

    printf("Page\t");
    printf("%i",page_number);
    printf("\t");
    printf("%s", source_name);
    printf("\t");
    // Prints out header: Page, page number, file source, the current date.
}
