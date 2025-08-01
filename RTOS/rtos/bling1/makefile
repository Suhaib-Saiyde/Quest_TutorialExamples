# WinAVR Sample makefile written by Eric B. Weddington, J�rg Wunsch, et al.
# Released to the Public Domain
# Please read the make user manual!
#
# Modified to be used with uC/OS-II by Julius Luukko (Julius.Luukko@lut.fi)
# 2003-06-27.
#
# Some more changes in order to this be usable with uC/OS-II version 2.52
# and 2.70 (Julius Luukko 2003-07-21).
#
# Moved erasing the MCU from separate command line to the same command
# line as programming (Julius Luukko 2003-10-14)
#
# Change UCOSDIR and PORTDIR to correspond to your installation. INCDIR1 
# and INCDIR2 might also need to be changed. avrdude settings must also be
# checked!
#
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF (for use with AVR Studio 3.x or VMLAB).
#
# make extcoff = Convert ELF to AVR Extended COFF (for use with AVR Studio
#                4.07 or greater).
#
# make program = Download the hex file to the device, using avrdude.  Please
#                customize the avrdude settings below first!
#
# make filename.s = Just compile filename.c into the assembler code only
#
# make tar = Create a tar.gz of the project files
#
# To rebuild project do "make clean" then "make all".
#


# MCU name
MCU = atmega128

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Target file name (without extension).
TARGET = bling1

# Optimization level, can be [0, 1, 2, 3, s]. 0 turns off optimization.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT = 0

# Where uC/OS-II and the port are
# For *nix systems you can use something like the next two lines if you 
# have uC/OS-II v2.70
# UCOSDIR = $(wildcard ~/Micrium/Micrium/Software/uCOS-II/Source)
# PORTDIR = $(wildcard ~/Micrium/Micrium/Software/uCOS-II/Ports/AVR/ATmega128/GNU/jlu)
# If you have uC/OS-II v2.52, use
#UCOSDIR = $(wildcard ~/Micrium/Micrium/software/ucos-ii/source)
#PORTDIR = $(wildcard ~/Micrium/Micrium/Software/uCOS-II/Ports/AVR/ATmega128/GNU/jlu)
# With Windows, use something like the next lines
# UCOSDIR = c:\Micrium\Micrum\Software\uCOS-II\Source
#PORTDIR = c:\Micrium\Micrium\Software\uCOS-II\Ports\AVR\ATmega128\GNU\jlu
UCOSDIR = c:/Micrium/Micrium/SOFTWARE/uCOS-II/Source
 PORTDIR = c:/Micrium/Micrium/SOFTWARE/uCOS-II/Ports/AVR/ATmega128/GNU/jlu

INCDIR1	= $(UCOSDIR)
INCDIR2	= $(PORTDIR)
# INCDIR1	= $(UCOSDIR)/SOURCE
# INCDIR2	= $(PORTDIR)/SOURCE

# List C source files here. (C dependencies are automatically generated.)
SRC = $(TARGET).c

# If there is more than one source file, append them above, or adjust and
# uncomment the following:
#SRC += foo.c bar.c

# You can also wrap lines by appending a backslash to the end of the line:
#SRC += baz.c \
#xyzzy.c

# uC/OS-II AVR port c source and the main uC/OS-II source
# If you have uC/OS-II v2.52, use the second line!
# UCOSSRC = $(PORTDIR)/os_cpu_c.c $(PORTDIR)/os_dbg.c $(UCOSDIR)/ucos_ii.c
UCOSSRC = $(PORTDIR)/os_cpu_c.c $(UCOSDIR)/ucos_ii.c

# List Assembler source files here.
# Make them end in .asm. This is different from the WinAVR example makefile
ASRC = 

# uC/OS-II AVR port assembler source
UCOSASRC = $(PORTDIR)/os_cpu_a.asm

# List all header files, which are part of this project (only used for tar)
HDRS = os_cfg.h includes.h

# Other files you want to be included in the tar
OTHER = README

# Optional compiler flags.
#  -g:        generate debugging information (for GDB, or for COFF conversion)
#  -O*:       optimization level
#  -f...:     tuning, see gcc manual and avr-libc documentation
#  -Wall...:  warning level
#  -Wa,...:   tell GCC to pass this to the assembler.
#    -ahlms:  create assembler listing
CFLAGS = -O$(OPT) \
	-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
	-Wall -Wstrict-prototypes \
	-Wa,-ahlms=$(notdir $(<:.c=.lst))



# Optional assembler flags.
#  -Wa,...:   tell GCC to pass this to the assembler.
#  -ahlms:    create listing
#  -gstabs:   have the assembler create line number information; note that
#             for use in COFF files, additional information about filenames
#             and function names needs to be present in the assembler source
#             files -- see avr-libc docs [FIXME: not yet described there]
ASFLAGS = -Wa,-ahlms=$(notdir $(<:.asm=.lst)),-gstabs 



# Optional linker flags.
#  -Wl,...:   tell GCC to pass this to linker.
#  -Map:      create map file
#  --cref:    add cross reference to  map file
LDFLAGS = -Wl,-Map=$(TARGET).map,--cref



# Additional libraries
#
# Minimalistic printf version
#LDFLAGS += -Wl,-u,vfprintf -lprintf_min
#
# Floating point printf version (requires -lm below)
#LDFLAGS +=  -Wl,-u,vfprintf -lprintf_flt
#
# -lm = math library
# LDFLAGS += -lm




# Programming support using avrdude. Settings and variables.

# Programming hardware: avrisp stk500 avr910 pavr stk200 pony-stk200
#                       dt006 bascom alf
# Type: avrdude -c ?
# to get a full listing.
#
AVRDUDE_PROGRAMMER = usbasp

#amarender commented next line
#AVRDUDE_PORT = com1	   # programmer connected to serial device
#AVRDUDE_PORT = lpt1	# programmer connected to parallel port
AVRDUDE_PORT = /dev/1-6	   # serial device on *nix
# AVRDUDE_PORT = /dev/ttyS0	   # serial device on *nix
#amarender
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
AVRDUDE_ERASE = -e
AVRDUDE_FLAGS = -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER)


# Uncomment the following if you want avrdude's erase cycle counter.
# Note that this counter needs to be initialized first using -Yn,
# see avrdude manual.
#AVRDUDE_ERASE += -y
#
# Uncomment the following if you do /not/ wish a verification to be
# performed after programming the device.
#AVRDUDE_FLAGS += -V
#
# Increase verbosity level.  Please use this when submitting bug
# reports about avrdude. See <http://savannah.nongnu.org/projects/avrdude> 
# to submit bug reports.
#AVRDUDE_FLAGS += -v -v

#amarender
AVRDUDE_FLAGS = -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER)
AVRDUDE_FLAGS += $(AVRDUDE_NO_VERIFY)
AVRDUDE_FLAGS += $(AVRDUDE_VERBOSE)
AVRDUDE_FLAGS += $(AVRDUDE_ERASE_COUNTER)

# ---------------------------------------------------------------------------

# Define directories, if needed.
DIRAVR = c:/winavr
DIRAVRBIN = $(DIRAVR)/bin
DIRAVRUTILS = $(DIRAVR)/utils/bin
DIRINC = .
DIRLIB = $(DIRAVR)/avr/lib


# Define programs and commands.
SHELL = sh

CC = avr-gcc

OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size


# Programming support using avrdude.
AVRDUDE = avrdude 


REMOVE = rm -f
COPY = cp

HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
ELFSIZE = $(SIZE) -A $(TARGET).elf

FINISH = echo Errors: none
BEGIN = echo -------- begin --------
END = echo --------  end  --------




# Define all object files.
OBJ = $(SRC:.c=.o) $(ASRC:.asm=.o) 
OBJ += $(notdir $(UCOSSRC:.c=.o)) $(notdir $(UCOSASRC:.asm=.o))

# Define all listing files.
LST = $(OBJ:.o=.lst)

# Combine all necessary flags and optional flags. 
# Add target processor to flags.
ALL_CFLAGS = -mmcu=$(MCU) -I. -I$(INCDIR1) -I$(INCDIR2) $(CFLAGS)
ALL_ASFLAGS = -mmcu=$(MCU) -I. -I$(INCDIR1) -I$(INCDIR2) -x assembler-with-cpp $(ASFLAGS)



# Default target.
all: begin gccversion sizebefore $(TARGET).elf $(TARGET).hex $(TARGET).eep \
	$(TARGET).lss sizeafter finished end


# Eye candy.
# AVR Studio 3.x does not check make's exit code but relies on
# the following magic strings to be generated by the compile job.
begin:
	@$(BEGIN)

finished:
	@$(FINISH)

end:
	@$(END)


# Display size of file.
sizebefore:
	@if [ -f $(TARGET).elf ]; then echo Size before:; $(ELFSIZE);fi

sizeafter:
	@if [ -f $(TARGET).elf ]; then echo Size after:; $(ELFSIZE);fi



# Display compiler version information.
gccversion : 
	$(CC) --version




# Convert ELF to COFF for use in debugging / simulating in
# AVR Studio or VMLAB.
COFFCONVERT=$(OBJCOPY) --debugging \
	--change-section-address .data-0x800000 \
	--change-section-address .bss-0x800000 \
	--change-section-address .noinit-0x800000 \
	--change-section-address .eeprom-0x810000 


coff: $(TARGET).elf
	$(COFFCONVERT) -O coff-avr $< $(TARGET).cof


extcoff: $(TARGET).elf
	$(COFFCONVERT) -O coff-ext-avr $< $(TARGET).cof




# Program the device.  The magic trickery below examines the .eep hex
# file whether the size is > 0, and if so, reprograms the EEPROM as
# well.  Just delete these lines if you don't want this feature (like
# on the ATmegas with the EESAVE fuse bit set).
program: $(TARGET).hex $(TARGET).eep
# 	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_ERASE)
#amarender
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) $(AVRDUDE_WRITE_EEPROM)
#amarender commented next line
#	$(AVRDUDE) $(AVRDUDE_FLAGS) -i $(TARGET).hex $(AVRDUDE_ERASE)
# 	@$(SIZE) --target=$(FORMAT) $(TARGET).eep | while read line; \
# 	do \
# 		set -- $$line; \
# 		if [ "x$$1" != "x0" ] ; then continue; fi; \
# 		if [ "$$2" -ne 0 ] ; then \
# 			echo $(AVRDUDE) $(AVRDUDE_FLAGS) -m eeprom -i $(TARGET).eep; \
# 			$(AVRDUDE) $(AVRDUDE_FLAGS) -m eeprom -i $(TARGET).eep; \
# 			break; \
# 		fi; \
# 	done

tar:
	tar czf $(TARGET)source.tgz $(SRC) $(ASRC) $(HDRS) $(OTHER) makefile


# Create final output files (.hex, .eep) from ELF output file.
%.hex: %.elf
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

%.eep: %.elf
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 -O $(FORMAT) $< $@

# Create extended listing file from ELF output file.
%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@



# Link: create ELF output file from object files.
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(OBJ)
%.elf: $(OBJ)
	$(CC) $(ALL_CFLAGS) $(OBJ) --output $@ $(LDFLAGS)


# Compile: create object files from C source files.
%.o : %.c
	$(CC) -c $(ALL_CFLAGS) $< -o $@


# Assemble: create object files from assembler source files.
%.o : %.asm
	$(CC) -c $(ALL_ASFLAGS) $< -o $@






# Target: clean project.
clean: begin clean_list finished end

clean_list :
	$(REMOVE) $(TARGET).hex
	$(REMOVE) $(TARGET).eep
	$(REMOVE) $(TARGET).obj
	$(REMOVE) $(TARGET).cof
	$(REMOVE) $(TARGET).elf
	$(REMOVE) $(TARGET).map
	$(REMOVE) $(TARGET).obj
	$(REMOVE) $(TARGET).a90
	$(REMOVE) $(TARGET).sym
	$(REMOVE) $(TARGET).lnk
	$(REMOVE) $(TARGET).lss
	$(REMOVE) $(OBJ)
	$(REMOVE) $(LST)
	$(REMOVE) $(SRC:.c=.d) $(notdir $(UCOSSRC:.c=.d))


# Automatically generate C source code dependencies. 
# (Code originally taken from the GNU make user manual and modified 
# (See README.txt Credits).)
#
# Note that this will work with sh (bash) and sed that is shipped with WinAVR
# (see the SHELL variable defined above).
# This may not work with other shells or other seds.
VPATH=.:$(INCDIR1):$(INCDIR2)
%.d: %.c
	set -e; $(CC) -MM $(ALL_CFLAGS) $< \
	| sed 's/\($(*F)\)\.o[ :]*/\1.o \1.d : /g' > $(@F); \
	[ -s $@ ] || rm -f $@


# Remove the '-' if you want to see the dependency files generated.
-include $(SRC:.c=.d) $(notdir $(UCOSSRC:.c=.d))



# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion coff extcoff \
	clean clean_list program


