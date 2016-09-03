BASEDIR = $(pwd)..
ODIR    = $(BASEDIR)/obj
LDIR    = $(BASEDIR)/lib
BINDIR  = $(BASEDIR)/bin
IDIR    = $(BASEDIR)/interface
WORKDIR = $(BASEDIR)/work

TYPEINFO	= /usr/local/root/cint/include

CC=g++
CFLAGS=-Wall -I$(IDIR)


# Add header files from interface directory here
_DEPS = Sphere.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Compile .cpp implementation files into object files
_OBJ = MC_Sphere.o Sphere.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -I. 

$(BINDIR)/MC_SPHERE_SIM: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) -I. 

.PHONY: clean

Clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
