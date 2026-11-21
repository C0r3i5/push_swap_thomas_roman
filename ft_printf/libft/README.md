*This project has been created as part of the 42 curriculum by twalter.*

# Description

The libft-Project ist the first project in the Ecole 42 CoreCorriculum.

It is a collection of numerous general purpose functions in c that can be used as a base for future programms.
Some are reimplemented libc functions and some are additional functions.

## Functions for string manipulation

- ft_isalpha

checks  for an alphabetic character

- ft_isdigit

checks for a digit (0 through 9)

- ft_isalnum

checks for an alphanumeric character

- ft_isascii

checks whether c is a 7-bit unsigned char value that fits into
the ASCII character set.

- ft_isprint

checks for any printable character including space.

- ft_strlen

calculates the length of the string pointed to by s, 
excluding the terminating null byte ('\0').

- ft_memset

fills  the  first  n  bytes of the memory area
pointed to by s with the constant byte c.

- ft_bzero

explicit_bzero - zero a byte string

- ft_memcpy

copies  n bytes from memory area src to memory
area dest.  The memory areas must not overlap.  Use memmove(3)  if  the memory areas do overlap.

- ft_memmove

Copies n bytes from memory area src to memory area dest.  
The memory areas may overlap.

- ft_strlcpy

copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.

- ft_strlcat

appends the NUL-terminated string src to the end of dst.  
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

- ft_toupper

If c is a lowercase letter, returns its uppercase equivalent

- ft_tolower

If c is an uppercase letter, returns  its  lowercase  equivalent

- ft_strchr

locates the first occurrence of c (converted to a char) 
in the string pointed to by s.  The terminating null character is considered part of the string; therefore if c is ‘\0’, the functions locate the terminating ‘\0’.

- ft_strrchr

returns a pointer to the last occurrence of  the character c in the string s.

- ft_strncmp

compares the two strings s1 and s2. 
The comparison is done using unsigned characters.

- ft_memchr

scans  the  initial n bytes of the memory area pointed to by s for the first instance of c.  Both c and the  bytes  of the memory area pointed to by s are interpreted as unsigned char.

- ft_memcmp

compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2

- ft_strnstr

locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched.

- ft_atoi

convert a string to an integer

- ft_calloc

allocates memory for an array of  nmemb  elements
of  size bytes each and returns a pointer to the allocated memory.

- ft_strdup

returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string  is  obtained  with malloc(3), and can be freed with free(3).

*This functions are reimplemented from the libc (GNU C library or bsd/string.h).*
*You can find the manpage for this function use the name without ft_. For example:* 

	ft_isalpha -> man isalpha

## Additional functions for strings

- ft_substr	

Allocates memory (using malloc(3)) and returns a
substring from the string ’s’.
The substring starts at index ’start’ and has a
maximum length of ’len’.

- ft_strjoin

Allocates memory (using malloc(3)) and returns a
new string, which is the result of concatenating
’s1’ and ’s2’.

- ft_strtrim

Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.

- ft_split

Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter.
Each string in the returned array is allocated
independently.
The array of pointers itself is also allocated
dynamically.
The returned array must be NULL terminated.

- ft_itoa

Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled.

- ft_strmapi

Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.

- ft_striteri

Applies the function ’f’ to each character of the
string passed as argument, passing its index as
the first argument. Each character is passed by
address to ’f’ so it can be modified if necessary.

- ft_putchar_fd

Outputs the character ’c’ to the specified file
descriptor.

- ft_putstr_fd

Outputs the string ’s’ to the specified file
descriptor.

- ft_putendl_fd

Outputs the string ’s’ to the specified file
descriptor followed by a newline.

- ft_putnbr_fd

Outputs the integer ’n’ to the specified file
descriptor.

## Functions for lists

- ft_lstnew

Allocates memory (using malloc(3)) and returns
a new node. The ’content’ member variable is
initialized with the given parameter ’content’.
The variable ’next’ is initialized to NULL.

- ft_lstadd_front

Adds the node ’new’ at the beginning of the list.

- ft_lstsize

Counts the number of nodes in the list.

- ft_lstlast

Returns the last node of the list.

- ft_lstadd_back

Adds the node ’new’ at the end of the list.

- ft_lstdelone

Takes a node as parameter and frees its content
using the function ’del’. Free the node itself but
does NOT free the next node.

- ft_lstclear

Deletes and frees the given node and all its
successors, using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL.

- ft_lstiter

Iterates through the list ’lst’ and applies the
function ’f’ to the content of each node.

- ft_lstmap

Iterates through the list ’lst’, applies the
function ’f’ to each node’s content, and creates
a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to
delete the content of a node if needed.

# Instuctions

To compile the library use the provided makefile and the command

	make 

This command compile the whole library and create the libft.a file.
Same as 

	make all

and

	make libft.a

To clean the folder and delete the created .o files use

	make clean

To clean also the created libft.a use

	make fclean

To clean and recreate with one command use

	make re

# Resources

## AI use
With the help of AI, I discussed basic C topics and topics that my fellow peers couldn't answer or that were unclear to all of us.

Some unit tests include suggestions from the AI "Google Gemini".

## Used Resources:
- Peers :)
- Manpage of the original c functions
- Stackoverflow
- Gemini

## Files in the project folder
- Makefile (contains the build rules)
- libft.h (include used system headers and prototyp of the functions)
- ft_*.c (implementation for the new functions)
