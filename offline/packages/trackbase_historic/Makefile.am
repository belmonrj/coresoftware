##############################################
# please add new classes in alphabetical order

AUTOMAKE_OPTIONS = foreign

# list of shared libraries to produce
lib_LTLIBRARIES = \
  libtrackbase_historic_io.la

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include  \
  -I$(ROOTSYS)/include \
  -I$(OPT_SPHENIX)/include \
  -I$(OFFLINE_MAIN)/include/eigen3

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(ROOTSYS)/lib \
  -L$(OFFLINE_MAIN)/lib \
  -L$(OFFLINE_MAIN)/lib64

pkginclude_HEADERS = \
  SvtxTrack.h \
  SvtxTrack_v1.h \
  SvtxTrack_v2.h \
  SvtxTrack_FastSim.h \
  SvtxTrack_FastSim_v1.h \
  SvtxTrackMap.h \
  SvtxTrackMap_v1.h \
  SvtxTrackState.h \
  SvtxTrackState_v1.h \
  SvtxVertex.h \
  SvtxVertex_v1.h \
  SvtxVertexMap.h \
  SvtxVertexMap_v1.h 

ROOTDICTS = \
  SvtxTrack_Dict.cc \
  SvtxTrackState_Dict.cc \
  SvtxTrackState_v1_Dict.cc \
  SvtxTrack_v1_Dict.cc \
  SvtxTrack_v2_Dict.cc \
  SvtxTrack_FastSim_Dict.cc \
  SvtxTrack_FastSim_v1_Dict.cc \
  SvtxTrackMap_Dict.cc \
  SvtxTrackMap_v1_Dict.cc \
  SvtxVertex_Dict.cc \
  SvtxVertex_v1_Dict.cc \
  SvtxVertexMap_Dict.cc \
  SvtxVertexMap_v1_Dict.cc 

pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  SvtxTrack_Dict_rdict.pcm \
  SvtxTrackState_Dict_rdict.pcm \
  SvtxTrackState_v1_Dict_rdict.pcm \
  SvtxTrack_v1_Dict_rdict.pcm \
  SvtxTrack_v2_Dict_rdict.pcm \
  SvtxTrack_FastSim_Dict_rdict.pcm \
  SvtxTrack_FastSim_v1_Dict_rdict.pcm \
  SvtxTrackMap_Dict_rdict.pcm \
  SvtxTrackMap_v1_Dict_rdict.pcm \
  SvtxVertex_Dict_rdict.pcm \
  SvtxVertex_v1_Dict_rdict.pcm \
  SvtxVertexMap_Dict_rdict.pcm \
  SvtxVertexMap_v1_Dict_rdict.pcm 

# sources for io library
libtrackbase_historic_io_la_SOURCES = \
  $(ROOTDICTS) \
  SvtxTrackState_v1.cc \
  SvtxTrack.cc \
  SvtxTrack_v1.cc \
  SvtxTrack_v2.cc \
  SvtxTrack_FastSim.cc \
  SvtxTrack_FastSim_v1.cc \
  SvtxTrackMap.cc \
  SvtxTrackMap_v1.cc \
  SvtxVertex.cc \
  SvtxVertex_v1.cc \
  SvtxVertexMap.cc \
  SvtxVertexMap_v1.cc

libtrackbase_historic_io_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  -L$(OFFLINE_MAIN)/lib64

libtrackbase_historic_io_la_LIBADD = \
  -lphool \
  -lActsCore \
  -lActsFatras \
  -lActsExamplesFramework

# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;



################################################
# linking tests

BUILT_SOURCES = testexternals.cc

noinst_PROGRAMS = \
  testexternals_trackbase_historic_io

testexternals_trackbase_historic_io_SOURCES = testexternals.cc
testexternals_trackbase_historic_io_LDADD = libtrackbase_historic_io.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

################################################

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
