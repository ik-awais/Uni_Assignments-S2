#include <iostream>
#include <iomanip>
using namespace std;

int Display_Menu();
int StringLength(char *str);
void StringCopy(char *org, char*copied);

void StringConcatenate(char *str1, char *str2);
void CompressString(char *compress);
char *ReverseSentence(char *orgsentence);
void pluralWords(char **s, int wordCount);

int main()
{
    int choice;
    //Created a function to Display the Menu working in an infinite loop
    while (1)
    {
        choice = Display_Menu(); 
        if (choice != 0)
        {
            if (choice == 1)
            {
                cout << "Enter 2 strings to be concatenated: " << endl;
                char string1[100];
                char string2[100];
                // To keep the buffer clean, used cin.ignore
                cin.ignore();
                // cin.getline works same as getline(cin, stringName)
                //  but for C language
                cin.getline(string1, 100);
                cin.getline(string2, 100);
                StringConcatenate(string1, string2);
            }
            else if (choice == 2)
            {
                cin.ignore();
                char string[100];
                cin.getline(string, 100);
                CompressString(string);
            }
            else if (choice == 3)
            {
                char sentence[100];
                cin.ignore();
                cin.getline(sentence, 100);
                // Since ReverseSentence function was a char pointer type
                // function, hence saved the returned pointer and displayed
                char *reversedptr = ReverseSentence(sentence);
                for(int i = 0; (*(reversedptr + i)) != '\0'; i++)
                {
                    cout << *(reversedptr + i);
                }
                cout << endl;
                delete[] reversedptr;
            }
            else if (choice == 4)
            {   int count;
                cin >> count;
                char **words2D = new char*[count];
                // Allocating memory for each word
                for(int i = 0; i < count; i++)
                {
                    *(words2D + i) = new char[20];
                }
                cin.ignore();
                // Taking input of each word
                for(int i = 0; i < count; i++)
                {
                    cin.getline(*(words2D + i), 20);   
                }
                pluralWords(words2D, count);
                for(int i = 0; i < count; i++)
                {
                    //Frees allocated memory of words
                    delete[] *(words2D + i);
                }
                //Frees the double pointer
                delete[] words2D; 

            }
            else
            {
                return 0;   
            }
        }
        else
        {
            cout << "Enter a valid choice." << endl;
        }
    }
    return 0;
}

int Display_Menu()
{
    int choice = 0;
    cout << "\n=======\tTEXT PROCESSING ENGINE\t=======" << endl;
    cout << "1. Merge two strings" << endl;
    cout << "2. Compress a string" << endl;
    cout << "3. Reverse a sentence" << endl;
    cout << "4. Convert singular words to plural" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
    {
        return choice;
    }
    else
    {
        return 0;
    }
}
// Since following block of code was being
// reused over and over again, hence it was cleaner
// to use a separate function for it.
int StringLength(char *str)
{
    int i = 0, size = 0;
    while (*(str + i) != '\0')
    {
        size++;
        i++;
    }
    return size;
}
// Using string library wasn't allowed
// So I had to use this function to copy strings
// into my Dynamically Allocated Memory
void StringCopy(char *org, char*copied){
    int i;
    for(i = 0; *(org + i) != '\0'; i++)
    {
        *(copied + i) = *(org + i);
    }
    *(copied + i) = '\0';
}
void StringConcatenate(char *str1, char *str2)
{
    int size1 = StringLength(str1);
    int size2 = StringLength(str2);
    const int SIZE = size1 + size2;
    char *temp = str2;
    // Creating a new string for the final result
    // wasn't allowed so I overwrote str2
    str2 = new char[SIZE + 1];
    int i = 0; 
    while(*(temp + i) != '\0')
    {
        *(str2 + i) = *(temp + i);
        i++;
    }
    i = 0;
    while(*(str1 + i) != '\0')
    {
        *(str2 + (size2 + i)) = *(str1 + i); 
        i++;
    }
    // Null character determines when a string ends
    // so manually added it at the end of the string after
    // copying all the characters from str1
    *(str2 + i) = '\0';
    i = 0;
    while(i < SIZE)
    {
        cout << *(str2 + i);
        i++;
    }
    cout << endl;
    delete[] str2;
}
void CompressString(char *compress){
    int size = StringLength(compress);
    int i = 0, j, k;
    // The algorithm used for concatenating string
    // was to shift the array from right to left whenever a duplicated 
    // character was detected
    // The following tree of loops is the algorithm in action
    while (*(compress + i) != '\0')
    {
        j = i + 1;
        while(*(compress + j) != '\0')
        {
            if(*(compress + j) == *(compress + i))
            {
                k = j;
                while(*(compress + k) != '\0')
                {
                    *(compress + k) = *(compress + (k + 1));
                    k++;
                }
                j--;
            }
            j++;
        }
        j = i + 1;
        i++;
    }
    size = StringLength(compress);
    for(int i = 0; i < size; i++)
    {
        cout << *(compress + i);
    }
    cout << endl;
}
char *ReverseSentence(char *orgsentence){
    int size = StringLength(orgsentence);
    char *reversedSentence = new char[size + 1];
    int k = 0, temp = 0;
    // Null character & space between words were the main
    // center of focus in the following logic
    // I started from the end of sentence. 
    // As soon as a space was detected. I overwrote the space character
    // by null character. Copied all then from left to right until I might the
    // null character. Wholesome and doable logic it was.
    for(int i = size - 1; i >= 0; i--)
    {
        if(*(orgsentence + i) == ' ')
        {
            temp = i;
            i++;
            while(1)
            {                 
                if(*(orgsentence + i) == '\0')
                {
                    *(reversedSentence + k) = ' ';
                    k++;
                    break;
                }  
                *(reversedSentence + k) = *(orgsentence + i);  
                k++;      
                i++;    
            }
            i = temp;
            *(orgsentence + i) = '\0';
        }
    }
    // Since there is no space before the first word
    // I had to apply an additional loop for the very first word
    int j = 0;
    while(*(orgsentence + j) != '\0')
    {
        *(reversedSentence + k) = *(orgsentence + j);
        k++;
        j++;
    }
    *(reversedSentence + k) = '\0';
    return reversedSentence;
}
void pluralWords(char **s, int wordCount){
    int *lettersCount = new int[wordCount];
    for(int i = 0; i < wordCount; i++)
    {
       *(lettersCount + i) = StringLength(*(s + i)); //Checks how long a word is
    }
    // The rule worked max till last 3 characters of a word. 
    // so created these 3 variables to keep a track of those characters
    int lastChar, seclastChar, thirdlastChar;
    // The following loop with body of 100 lines
    // iterates over for each word. 
    for(int i = 0; i < wordCount; i++)
    {   
        if(*(lettersCount + i) >= 2)
        {
            seclastChar = *(*(s + i) + (*(lettersCount + i) - 2));
        }
        else
        {
            seclastChar = '\0';
        }
        if(*(lettersCount + i) >= 3)
        {
            thirdlastChar = *(*(s + i) + (*(lettersCount + i) - 3));
        }
        else
        {
            thirdlastChar = '\0';
        }
        lastChar = *(*(s + i) + (*(lettersCount + i)) - 1);
        // Append 'es' if:
        if ((lastChar == 'h' && (seclastChar == 'c' || seclastChar == 's')) ||
        (lastChar == 'x') || (lastChar == 's' && seclastChar == 'i') || 
        ((lastChar == 's' || lastChar == 'z') && 
        (seclastChar != 'a' && seclastChar != 'e' && seclastChar != 'i' && seclastChar != 'o' && seclastChar != 'u')) ||
        (lastChar == 'o' && seclastChar == 't' && thirdlastChar == 'a')) 
        {
            char *plural = new char[*(lettersCount + i) + 3];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 'e';
                *(plural + *(lettersCount + i) + 1) = 's';
                *(plural + *(lettersCount + i) + 2) = '\0';
                
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Append 'zes' if:
        else if ((lastChar == 'z' && 
            (seclastChar == 'a' || seclastChar == 'e')))
        {
            char *plural = new char[*(lettersCount + i) + 4];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 'z';
                *(plural + *(lettersCount + i) + 1) = 'e';
                *(plural + *(lettersCount + i) + 2) = 's';
                *(plural + *(lettersCount + i) + 3) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }    
        // Append 'ses' if:   
        else if((lastChar == 's' && 
            (seclastChar == 'a' || seclastChar == 'e')))   
        {
            char *plural = new char[*(lettersCount + i) + 4];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 's';
                *(plural + *(lettersCount + i) + 1) = 'e';
                *(plural + *(lettersCount + i) + 2) = 's';
                *(plural + *(lettersCount + i) + 3) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Append 's' if:
        else if((lastChar == 'f' && seclastChar == 'f'))
        {
            char *plural = new char[*(lettersCount + i) + 2];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 's';
                *(plural + *(lettersCount + i) + 1) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Replace last 2 characters with 've' and append 's' if:
        else if ((lastChar == 'f') || 
        (lastChar == 'e' && seclastChar == 'f'))
        {
            if (lastChar == 'f')
            {
            char *plural = new char[*(lettersCount + i) + 3];
            int j;
                 for(j = 0; j < (*(lettersCount + i) - 1); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i) - 1) = 'v';
                *(plural + *(lettersCount + i)) = 'e';
                *(plural + *(lettersCount + i) + 1) = 's';
                *(plural + *(lettersCount + i) + 2) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
            }
            else
            {
                char *plural = new char[*(lettersCount + i) + 2];
                int j;
                    for(j = 0; j < (*(lettersCount + i) - 2); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i) - 2) = 'v';
                    *(plural + *(lettersCount + i) - 1) = 'e';
                    *(plural + *(lettersCount + i)) = 's';
                    *(plural + *(lettersCount + i) + 1) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
            }           
        }
        // Replace last 2 characters with 'a' if:
        else if ((lastChar == 'n' && seclastChar == 'o'))
        {
            char *plural = new char[*(lettersCount + i)];
            int j;
                 for(j = 0; j < (*(lettersCount + i) - 2); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i) - 2) = 'a';
                *(plural + *(lettersCount + i) - 1) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Replace last 2 characters with 'i' if:
        else if ((lastChar == 's' && seclastChar == 'u'))
        {
            char *plural = new char[*(lettersCount + i)];
            int j;
                 for(j = 0; j < (*(lettersCount + i) - 2); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i) - 2) = 'i';
                *(plural + *(lettersCount + i) - 1) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // 2 Cases:
        else if (lastChar == 'y')
        {
            // Append 's' if:
            if((lastChar == 'y' && 
            (seclastChar == 'a' || seclastChar == 'e' || seclastChar == 'i' ||
            seclastChar == 'o' || seclastChar == 'u')))
            {
                char *plural = new char[*(lettersCount + i) + 2];
                int j;
                    for(j = 0; j < (*(lettersCount + i)); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i)) = 's';
                    *(plural + *(lettersCount + i) + 1) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
            }
            // Replace last character with 'ies' if:
            else
            {
                char *plural = new char[*(lettersCount + i) + 3];
                int j;
                    for(j = 0; j < (*(lettersCount + i) - 1); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i) - 1) = 'i';
                    *(plural + *(lettersCount + i)) = 'e';
                    *(plural + *(lettersCount + i) + 1) = 's';
                    *(plural + *(lettersCount + i) + 2) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
            }
        }
        // For all other cases, append 's':
        else
        {
                char *plural = new char[*(lettersCount + i) + 2];
                int j;
                    for(j = 0; j < (*(lettersCount + i)); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i)) = 's';
                    *(plural + *(lettersCount + i) + 1) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
        }
    }
    cout << "Pluralized words: ";
    for (int i = 0; i < wordCount; i++)
    {
        cout << *(s + i) << ' ';
    }
    cout << endl;
    delete[] lettersCount;
    
}

// Thankyou Aais Bhai for such an extensive and 
// productive problem