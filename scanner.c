//
//  scanner.c
//  Lab3
//
//  Created by Bryce Holton.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#include <stdio.h>
#include "scanner.h"

/*******************
 Static functions needed for the scanner
 You need to design the proper parameter list and
 return types for functions with ???.
 ******************/
static char get_char(char source_buffer[]);
static void skip_comment(char source_buffer[]);
static void skip_blanks(char source_buffer[]);
static void get_word(char source_buffer[]);
static void get_number(char source_buffer[]);
static void get_string(char source_buffer[]);
static char get_special(char source_buffer[]);
static char downshift_word(char source_buffer[]);
static BOOLEAN is_reserved_word(char source_buffer[]);

typedef enum
{
    LETTER, DIGIT, QUOTE, SPECIAL, EOF_CODE,
}
CharCode;

/*********************
 Static Variables for Scanner
 Must be initialized in the init_scanner function.
 *********************/
static FILE *src_file;
static char src_name[MAX_FILE_NAME_LENGTH];
static char todays_date[DATE_STRING_LENGTH];
static CharCode char_table[256];  // The character table

typedef struct
{
    char *string;
    TokenCode token_code;
}
RwStruct;

const RwStruct rw_table[9][10] = {
    {{"do",DO},{"if",IF},{"in",IN},{"of",OF},{"or",OR},{"to",TO},{NULL,0}}, //Reserved words of size 2
    {{"and",AND},{"div",DIV},{"end",END},{"for",FOR},{"mod",MOD},{"nil",NIL},{"not",NOT},{"set",SET},{"var",VAR},{NULL,0}}, //Reserved words of size 3
    {{"case",CASE},{"else",ELSE},{"file",FFILE},{"goto",GOTO},{"then",THEN},{"type",TYPE},{"with",WITH},{NULL,0}}, //Reserved words of size 4
    {{"array",ARRAY},{"begin",BEGIN},{"const",CONST},{"label",LABEL},{"until",UNTIL},{"while",WHILE},{NULL,0}},  //Reserved words of size 5
    {{"downto",DOWNTO}, {"packed",PACKED},{"record",RECORD}, {"repeat",REPEAT},{NULL,0}},  // Reserved words of size 6
    {{"program", PROGRAM},{NULL,0}}, // Reserved words of size 7
    {{"function", FUNCTION},{NULL,0}}, // Reserved words of size 8
    {{"procedure", PROCEDURE},{NULL,0}}  // Reserved words of size 9
};

void init_scanner(FILE *source_file, char source_name[], char date[])
{
    src_file = source_file;
    strcpy(src_name, source_name);
    strcpy(todays_date, date);
    
    /*******************
     initialize character table, this table is useful for identifying what type of character
     we are looking at by setting our array up to be a copy the ascii table.  Since C thinks of
     a char as like an int you can use ch in get_token as an index into the table.
     *******************/
    
}
BOOLEAN get_source_line(char source_buffer[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    //    char source_buffer[MAX_SOURCE_LINE_LENGTH];  //I've moved this to a function parameter.  Why did I do that?
    static int line_number = 0;
    
    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL)
    {
        ++line_number;
        sprintf(print_buffer, "%4d: %s", line_number, source_buffer);
        print_line(print_buffer, src_name, todays_date);
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
Token* get_token()
{
    char ch; //This can be the current character you are examining during scanning.
    char token_string[MAX_TOKEN_STRING_LENGTH]; //Store your token here as you build it.
    char *token_ptr = token_string; //write some code to point this to the beginning of token_string
    char token;  //I am missing the most important variable in the function, what is it?  Hint: what should I return?
    
    //1.  Skip past all of the blanks
    
    //2.  figure out which case you are dealing with LETTER, DIGIT, QUOTE, EOF, or special, by examining ch
    
    //3.  Call the appropriate function to deal with the cases in 2.
    
    return 'a'; //What should be returned here?
}
static char get_char(char source_buffer[])
{
    /*
     If at the end of the current line (how do you check for that?),
     we should call get source line.  If at the EOF (end of file) we should
     set the character ch to EOF and leave the function.
     */
    
    /*
     Write some code to set the character ch to the next character in the buffer
     */
    return 'a';
}

static void skip_blanks(char source_buffer[])
{
    /*
     Write some code to skip past the blanks in the program and return a pointer
     to the first non blank character
     */
    int count= 0;
    char temp[256];
    
	while(source_buffer[0] == ' '){ // while space exists in the first
		for(int i = 0; i<strlen(source_buffer); i++){
			temp[i] = source_buffer[i+1];
            
		}
    
}
static void skip_comment(char source_buffer[])
{
    /*
     Write some code to skip past the comments in the program and return a pointer
     to the first non blank character.  Watch out for the EOF character.
     */
	char temp[MAX_TOKEN_STRING_LENGTH];
	char temp2[MAX_TOKEN_STRING_LENGTH];
	int count = 0;
    
    for(int i = 0; i < strlen(source_buffer); i++)
    {
        source_buffer[i] = source_buffer[i+1];
    }
    source_buffer[strlen(source_buffer)+1] = '\0';
    
    while(source_buffer[0] != '}'){ //AS LONG AS THERE EXISTS A CHARACTER
		temp[count] = source_buffer[0]; //ASSIGN CHARACTER AT THE CURRENT COUNT OF TEMP TO FIRST CHARACTER OF TOKEN STRING
        
		for(int i = 1; i<strlen(source_buffer); i++){ //START PAST FIRST BLANK CHARACTER (
			temp2[i-1] = source_buffer[i];
			temp2[i+1] = '\0';
		}
        
		count++;
        
		temp[count+1] = '\0';
	}//End of while
    source_buffer[0] = ' ';
    
}
    static void get_word(char source_buffer[])
    {
        /*
         Write some code to Extract the word
         */
        char temp[MAX_TOKEN_STRING_LENGTH];
        char uptemp[MAX_TOKEN_STRING_LENGTH];
        char temp2[MAX_TOKEN_STRING_LENGTH];
        int count = 0;
        
        for(int i = 0; i < strlen(uptemp); i++)
        {
            uptemp[i] = ' ';
        }
        
        
        while(isalpha(source_buffer[0])){ //AS LONG AS THERE EXISTS A CHARACTER
            temp[count] = source_buffer[0]; //ASSIGN CHARACTER AT THE CURRENT COUNT OF TEMP TO FIRST CHARACTER OF TOKEN STRING
            
            for(int i = 1; i<strlen(source_buffer); i++){ //START PAST FIRST BLANK CHARACTER (
                temp2[i-1] = source_buffer[i];
                temp2[i+1] = '\0';
            }
            
            transfer(source_buffer, temp2);
            
            count++;
            
            temp[count+1] = '\0';
        }//End of while
        
        transfer(uptemp, temp);
        
        //Downshift the word, to make it lower case
        for(int i = 0; i<strlen(temp); i++){
            temp[i] = tolower(temp[i]);
        }
        
        int flag = 0;
        //checks for reserved word
        for(int i=0; i<35; i++){
            if(strcmp(temp, reserved[i]) == 0){
				printf( "\t>> %s\t%s\n", uptemp, temp);
                line_count++;
				flag = 1;
                break;
            }
        }
        
        if(flag == 0)
        {
            printf( "\t>> <INDENTIFIER>\t%s\n", temp);
            count++;
        }
        
        
        /*
         Write some code to Check if the word is a reserved word.
         if it is not a reserved word its an identifier.
         */
    }
    static void get_number(char source_buffer[])
    {
        /*
         Write some code to Extract the number and convert it to a literal number.
         */
        char temp[256];
        char temp2[MAX_TOKEN_STRING_LENGTH];
        int count = 0;
        
        while(isdigit(source_buffer[0]) || (source_buffer[0] == '.') || (source_buffer[0] == 'e') || (source_buffer[0] == '-')){ //AS LONG AS THERE EXISTS A CHARACTER
            temp[count] = source_buffer[0]; //ASSIGN CHARACTER AT THE CURRENT COUNT OF TEMP TO FIRST CHARACTER OF TOKEN STRING
            
            for(int i = 1; i<strlen(source_buffer); i++){ //START PAST FIRST BLANK CHARACTER (
                temp2[i-1] = source_buffer[i];
                temp2[i+1] = '\0';
            }
            
            //printf("Temp 1: %s\n", temp);  //Debugging Lines
            //printf("Temp 2: %s\n", temp2); //Debugged
            transfer(source_buffer, temp2);
            
            count++;
            
            temp[count+1] = '\0';
        }//End of while
        printf("\t>> <NUMBER>\t%s\n", temp);
        count++;
    }
    static void get_string(char source_buffer[])
    {
        /*
         Write some code to Extract the string
         */
        /*
         Write some code to Extract the string
         */
        char temp[MAX_TOKEN_STRING_LENGTH];
        char temp2[MAX_TOKEN_STRING_LENGTH];
        int count = 0;
        
        for(int i = 0; i < strlen(source_buffer); i++)
        {
            source_buffer[i] = source_buffer[i+1];
        }
        source_buffer[strlen(source_buffer)+1] = '\0';
        
        while(source_buffer[0] != '\''){ //AS LONG AS THERE EXISTS A CHARACTER
            temp[count] = source_buffer[0]; //ASSIGN CHARACTER AT THE CURRENT COUNT OF TEMP TO FIRST CHARACTER OF TOKEN STRING
            
            for(int i = 1; i<strlen(source_buffer); i++){ //START PAST FIRST BLANK CHARACTER (
                temp2[i-1] = source_buffer[i];
                temp2[i+1] = '\0';
            }
            
            //printf("Temp 1: %s\n", temp);  //Debugging Lines
            //printf("Temp 2: %s\n", temp2); //Debugged
            transfer(source_buffer, temp2);
            
            count++;
            
            temp[count+1] = '\0';
        }//End of while
        source_buffer[0] = ' ';
        
        
        printf("\t>> <STRING>\t%s\n", temp);
        count++;
    }
    static char get_special(char source_buffer[])
    {
        int count =0;
        /*
         Write some code to Extract the special token.  Most are single-character
         some are double-character.  Set the token appropriately.
         */
        printf("\t>> %c\t%c\n", source_buffer[0], source_buffer[0]);
        count++;
        source_buffer[0] = ' ';
        
    }
    static char downshift_word(char source_buffer[])
    {
        /*
         Make all of the characters in the incoming word lower case.
         */
        char temp[256];
        for (int i = 0; i < strlen(source_buffer); i++) {
            temp[i] = tolower(source_buffer[i]);
        }
        return temp[strlen(source_buffer)];
    }
    static BOOLEAN is_reserved_word(char character)
    {
        /*
         Examine the reserved word table and determine if the function input is a reserved word.
         */
        return FALSE;
    }
