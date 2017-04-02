# For complete documentation of this file, please see Geany's main documentation
[styling]
# Edit these in the colorscheme .conf file instead

# foreground;background;bold;italic
default=0x000000;0xffffff;false;false
comment=0x808080;0xffffff;false;false
number=0x007f00;0xffffff;false;false
string=0xff901e;0xffffff;false;false
operator=0x000000;0xffffff;false;false
identifier=0x880000;0xffffff;false;false
cpuinstruction=0x111199;0xffffff;true;false
mathinstruction=0x7f0000;0xffffff;true;false
register=0x000000;0xffffff;true;false
directive=0x3d670f;0xffffff;true;false
directiveoperand=0xff901e;0xffffff;false;false
commentblock=0x808080;0xffffff;false;false
character=0xff901e;0xffffff;false;false
stringeol=0x000000;0xe0c0e0;false;false
extinstruction=0x007f7f;0xffffff;false;false

[keywords]
# all items must be in one line
# this is by default a very simple instruction set; not of Intel or so
instructions=adc add and call cmp dec div idiv imul in inc int iret ja jae jb jbe je jne jg jge jl jle jnbe jnb jnae jna jz jnz jnle jnl jnge jng jc jnc jo jno js jns jmp loop mov movsx movsxd movzx mul neg not out or pop push ret rol ror sal sar sbb shl shr sub test xchg xor
registers=rax eax ax ah al rbx ebx bx bh bl rcx ecx cx ch cl rdx edx dx dh dl rsi esi si sil rdi edi di dil rbp ebp bp bpl rsp esp sp spl r8 r8d r8w r8b r9 r9d r9w r9b r10 r10d r10w r10b r11 r11d r11w r11b r12 r12d r12w r12b r13 r13d r13w r13b r14 r14d r14w r14b r15 r15d r15w r15b rip eip ip
directives=cpu .data .bss .text org list nolist page equivalent word dword qword text equ section global extern %macro %endmacro db dw dd dq movsb stosb resb resw resd resq byte %1 %2 %3 %4 %5 %6 %7 %8 %9 %10


[settings]
# default extension used when saving files
extension=asm

# the following characters are these which a "word" can contains, see documentation
#wordchars=_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789

# single comments, like # in this file
comment_single=;
# multiline comments
#comment_open=
#comment_close=

# set to false if a comment character/string should start at column 0 of a line, true uses any
# indentation of the line, e.g. setting to true causes the following on pressing CTRL+d
	#command_example();
# setting to false would generate this
#	command_example();
# This setting works only for single line comments
comment_use_indent=true

# context action command (please see Geany's main documentation for details)
context_action_cmd=

[indentation]
#width=4
# 0 is spaces, 1 is tabs, 2 is tab & spaces
#type=1

[build_settings]
# %f will be replaced by the complete filename
# %e will be replaced by the filename without extension
# (use only one of it at one time)
compiler=yasm "%f"

[build-menu]
FT_00_LB=_Compile
FT_00_CM=yasm -felf64 -gdwarf2 "%f"
FT_00_WD=
FT_01_LB=_Link
FT_01_CM=gcc -g -o "%e" "%e".o
FT_01_WD=
FT_02_LB=_Debug
FT_02_CM=kdbg "%e"
FT_02_WD=
