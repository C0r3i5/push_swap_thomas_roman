*This project has been created as part of the 42 curriculum by twalter.*

# Description

The ft_printf-Project is a reimplementation of the original libc printf().
It only include a subset of the function of the original printf().

The ft_printf() function write output to stdout, the standard output stream.
If an output error is encountered, a negative value is returned.

## Conversions
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

The buffer management of the original printf() is not implemented.

# Instuctions

To compile the library use the provided makefile and the command

	make 

This command compile the whole library and create the libftprintf.a file.
Same as 

	make all

and

	make libftprintf.a

To clean the folder and delete the created .o files use

	make clean

To clean also the created libftprintf.a use

	make fclean

To clean and recreate with one command use

	make re

**The libft projectfiles need to be in the ft_printf folder and will be automatic compiled with the libftprintf project.**

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
- libft-Library