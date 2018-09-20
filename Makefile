#variables
CC = g++
CFLAGS= -g -Wall
TARGET = l0l
WRAPPER = core/l0l.sh
#commands
RM = rm -f
RMDIR = rm -rf
CP = cp
CPDIR = cp -a
MKDIR_RX = install -dm755
MKDIR_RO = install -dm644
INSTALL_RX = install -Dm755
INSTALL_RO = install -Dm644
# locations
PREFIX = /usr
SHAREDIR = $(DESTDIR)$(PREFIX)/share
BINDIR = $(DESTDIR)$(PREFIX)/bin
LICENSEDIR = $(SHAREDIR)/licenses

$(TARGET): $(TARGET).cpp
	$(CC) -o $(TARGET) $(TARGET).cpp

# to see all compilation errors & warnings
verbose:
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

#linux only
clean:
	$(RM) $(TARGET)

install:
	# make
	$(CC) -o $(TARGET) $(TARGET).cpp
	# install files to share
	$(MKDIR_RX) $(SHAREDIR)/$(TARGET)
	$(INSTALL_RX) __init__.py $(TARGET) $(SHAREDIR)/$(TARGET)
	$(CPDIR) core $(SHAREDIR)/$(TARGET)
	# install wrapper to bin
	$(INSTALL_RX) $(WRAPPER) $(BINDIR)/$(TARGET)
	# install license
	$(MKDIR_RX) $(LICENSEDIR)/$(TARGET)
	$(INSTALL_RO) LICENSE $(LICENSEDIR)/$(TARGET)

uninstall:
	# remove executable from path
	$(RM) $(BINDIR)/$(TARGET)
	# remove files from share
	$(RMDIR) $(SHAREDIR)/$(TARGET)
	$(RMDIR) $(LICENSEDIR)/$(TARGET)
