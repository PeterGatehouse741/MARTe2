#############################################################
#
# Copyright 2015 F4E | European Joint Undertaking for ITER 
#  and the Development of Fusion Energy ('Fusion for Energy')
# 
# Licensed under the EUPL, Version 1.1 or - as soon they 
# will be approved by the European Commission - subsequent  
# versions of the EUPL (the "Licence"); 
# You may not use this work except in compliance with the 
# Licence. 
# You may obtain a copy of the Licence at: 
#  
# http://ec.europa.eu/idabc/eupl
#
# Unless required by applicable law or agreed to in 
# writing, software distributed under the Licence is 
# distributed on an "AS IS" basis, 
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either 
# express or implied. 
# See the Licence for the specific language governing 
# permissions and limitations under the Licence. 
#
# $Id: Makefile.inc 3 2012-01-15 16:26:07Z aneto $
#
#############################################################

OBJSX=Loader.x RealTimeLoader.x

PACKAGE=Core/BareMetal
ROOT_DIR=../../../..
MARTe2_MAKEDEFAULT_DIR?=$(ROOT_DIR)/MakeDefaults

#Allow portable compilation of the core (i.e. with the Architecture and Environment defined elsewhere w.r.t. to the core)
MARTe2_PORTABLE_SPB_DIR=.
ifdef MARTe2_PORTABLE_ENV_DIR
MARTe2_PORTABLE_SPB_DIR=$(MARTe2_PORTABLE_ENV_DIR)/BareMetal/L6App
endif
SPB=$(MARTe2_PORTABLE_SPB_DIR)/Environment/$(ENVIRONMENT).x

include $(MARTe2_MAKEDEFAULT_DIR)/MakeStdLibDefs.$(TARGET)

INCLUDES+=-I.
INCLUDES+=-I../L0Types
INCLUDES+=-I../L1Portability
INCLUDES+=-I../L2Objects
INCLUDES+=-I../L3Streams
INCLUDES+=-I../L4Configuration
INCLUDES+=-I../L4Logger
INCLUDES+=-I../L4Messages
INCLUDES+=-I../L5GAMs
LIBRARIES_STATIC+=$(BUILD_DIR)/$(ENVIRONMENT)/L6App$(LIBEXT)

all: $(OBJS) $(SUBPROJ) \
	        $(BUILD_DIR)/L6AppB$(LIBEXT) \
	        $(BUILD_DIR)/L6AppB.def
	echo  $(OBJS)

include depends.$(TARGET)

include $(MARTe2_MAKEDEFAULT_DIR)/MakeStdLibRules.$(TARGET)

