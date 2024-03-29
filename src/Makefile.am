AUTOMAKE_OPTIONS = subdir-objects
DEFS = @DEFS@ @FLAC_CFLAGS@
DEFAULT_INCLUDES = -I$(top_builddir)/include -I$(top_srcdir)/include -I$(top_builddir)/intl

bin_PROGRAMS	=	mednafen

SUBDIRS			=
noinst_LIBRARIES	=
mednafen_LDADD		=
mednafen_DEPENDENCIES	=
mednafen_SOURCES 	= 	debug.cpp error.cpp mempatcher.cpp settings.cpp endian.cpp mednafen.cpp git.cpp file.cpp general.cpp memory.cpp netplay.cpp state.cpp state_rewind.cpp movie.cpp player.cpp PSFLoader.cpp SSFLoader.cpp SNSFLoader.cpp SPCReader.cpp tests.cpp testsexp.cpp qtrecord.cpp IPSPatcher.cpp
mednafen_SOURCES	+=	VirtualFS.cpp NativeVFS.cpp Stream.cpp MemoryStream.cpp ExtMemStream.cpp FileStream.cpp MTStreamReader.cpp

if HAVE_SDL
SUBDIRS 		+=	drivers
mednafen_LDADD          +=	drivers/libmdfnsdl.a
mednafen_DEPENDENCIES   +=	drivers/libmdfnsdl.a

#
# Resource file wasn't linking in properly when it was in an archive, so we resort to this!
#
if WIN32
.rc.o:
	@WINDRES@ @DEFS@ -I$(top_builddir)/include $(CPPFLAGS) -o $@ $<

mednafen_SOURCES	+=	win32-common.cpp drivers/win-resource.rc
endif

endif

if DOS
SUBDIRS			+=	drivers_dos
mednafen_LDADD		+=	drivers_dos/libmdfndos.a
mednafen_DEPENDENCIES	+=	drivers_dos/libmdfndos.a
endif

if ENABLE_LIBXXX_MODE
SUBDIRS			+=	drivers_libxxx
mednafen_LDADD		+=	drivers_libxxx/libmdfnxxx.a
mednafen_DEPENDENCIES	+=	drivers_libxxx/libmdfnxxx.a
endif

SUBDIRS			+=	sexyal
mednafen_LDADD		+=	sexyal/libsexyal.a @ALSA_LIBS@ @JACK_LIBS@
mednafen_DEPENDENCIES	+=	sexyal/libsexyal.a

if HAVE_SDL
mednafen_LDADD		+=	@SDL_LIBS@
endif

include cdplay/Makefile.am.inc
include demo/Makefile.am.inc

if WANT_APPLE2_EMU
include apple2/Makefile.am.inc
endif

if WANT_GB_EMU
include gb/Makefile.am.inc
endif

if WANT_GBA_EMU
include gba/Makefile.am.inc
endif

if WANT_LYNX_EMU
include lynx/Makefile.am.inc
endif

if WANT_MD_EMU
include md/Makefile.am.inc
endif

if WANT_NES_EMU
include nes/Makefile.am.inc
endif

#if WANT_NES_NEW_EMU
#include nes_new/Makefile.am.inc
#endif

if WANT_NGP_EMU
include ngp/Makefile.am.inc
endif

if WANT_PCE_EMU
include pce/Makefile.am.inc
endif

if WANT_PCE_FAST_EMU
include pce_fast/Makefile.am.inc
endif

if WANT_PCFX_EMU
include pcfx/Makefile.am.inc
endif

if WANT_PSX_EMU
include psx/Makefile.am.inc
endif

if WANT_SASPLAY_EMU
include	sasplay/Makefile.am.inc
endif

if WANT_SMS_EMU
include sms/Makefile.am.inc
endif

if WANT_SNES_EMU
include snes/Makefile.am.inc
endif

if WANT_SNES_FAUST_EMU
include snes_faust/Makefile.am.inc
endif

if WANT_SS_EMU
SUBDIRS			+=	ss
else
if WANT_SSFPLAY_EMU
SUBDIRS			+=	ss
endif
endif

if WANT_SS_EMU
mednafen_LDADD          +=      ss/libss.a
mednafen_DEPENDENCIES   +=      ss/libss.a
endif

if WANT_SSFPLAY_EMU
mednafen_LDADD          +=      ss/libssfplay.a
mednafen_DEPENDENCIES   +=      ss/libssfplay.a
endif

if WANT_VB_EMU
include vb/Makefile.am.inc
endif

if WANT_WSWAN_EMU
include wswan/Makefile.am.inc
endif


if WANT_DEBUGGER
include desa68/Makefile.am.inc
endif

include hw_cpu/Makefile.am.inc
include hw_misc/Makefile.am.inc
include hw_sound/Makefile.am.inc
include hw_video/Makefile.am.inc
include time/Makefile.am.inc
include mthreading/Makefile.am.inc
include cdrom/Makefile.am.inc
include sound/Makefile.am.inc
include net/Makefile.am.inc
include string/Makefile.am.inc
include video/Makefile.am.inc
include resampler/Makefile.am.inc
include cputest/Makefile.am.inc
include cheat_formats/Makefile.am.inc
include quicklz/Makefile.am.inc
include compress/Makefile.am.inc
include hash/Makefile.am.inc

if HAVE_EXTERNAL_LZO2
mednafen_LDADD		+=	@LZO2_LIBS@
DEFS			+=	@LZO2_CFLAGS@
else
include minilzo/Makefile.am.inc
endif

if HAVE_EXTERNAL_LIBZSTD
mednafen_LDADD		+=	@LIBZSTD_LIBS@
DEFS			+=	@LIBZSTD_CFLAGS@
else
include zstd/Makefile.am.inc
endif

if HAVE_EXTERNAL_TREMOR
mednafen_LDADD		+=	@TREMOR_LIBS@
else
include tremor/Makefile.am.inc
endif

if HAVE_EXTERNAL_MPCDEC
mednafen_LDADD		+=	@MPCDEC_LIBS@
else
include mpcdec/Makefile.am.inc
endif

if HAVE_EXTERNAL_TRIO
mednafen_LDADD		+=	@TRIO_LIBS@
DEFS			+=	@TRIO_CFLAGS@
else
include trio/Makefile.am.inc
endif

mednafen_LDADD		+= 	@FLAC_LIBS@ @ZLIB_LIBS@ @LIBINTL@ @LIBICONV@

