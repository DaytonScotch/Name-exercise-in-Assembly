.data
prompt : .asciiz "Please enter your first name: "  # get name from user
greeting : .asciiz "Hello, "                  # greeting message
newline : .asciiz "\n"                     # newline character
name : .space 30                           # limit name input to 30 characters

.text
.globl main
main :
# Print prompt for input
li $v0, 4           # syscall to print string
la $a0, prompt      # load address of prompt
syscall

# Read user input
li $v0, 8           # syscall to read string
la $a0, name        # load address of name buffer
li $a1, 30          # set max length of input to 30
syscall

# Print greeting message
li $v0, 4           # syscall to print string
la $a0, greeting    # load address of greeting
syscall
la $a0, name        # load address of name buffer
syscall
la $a0, newline     # load newline character
syscall

# Exit program
li $v0, 10          # syscall to exit
syscall